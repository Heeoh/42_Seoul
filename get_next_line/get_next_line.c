#include <unistd.h> // read
#include <stdlib.h> // malloc, free, realloc(test)

#include <stdio.h> // test

// utils
char	*ft_strchr(const char *s, int c, int n)
{
	char	*p;

	p = (char *)s;
	while (p < s + n)
	{
		if (*p == (char)c)
			return (p);
		if (!*p)
			return (0);
		p++;
	}
	return (0);
}

// utils
char	*my_strcat(char *dst, char const *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n) {
		*dst++ = src[i];
		if (src[i] == '\n' || src[i] == '\0')
			break ;
		i++;
	}
	return (dst);
}

// utils
char	*ft_realloc();

size_t	read_bufSize(int fd, size_t buf_size, char **buf, size_t *read_size) {
	// char	*tmp_buf;
	// size_t	read_size;
	char	*newline_p;

	// read()로 buf_size만큼 읽어오기
	*buf = (char *)malloc(buf_size * sizeof(char));
	if (!*buf) {
		printf("read_bufSize, line malloc error\n");
		exit(0);
	}
	*read_size = read(fd, *buf, buf_size);
	newline_p = ft_strchr(*buf, '\n', *read_size);

	if (*read_size == 0){
		*buf[0] = '\0';
		return *read_size;
	}
	else if (newline_p != NULL)
		return (newline_p - *buf);
	else
		return *read_size;

}

char	*integrate_to_line(size_t line_len, size_t buf_size, char **buf_arr, size_t buf_cnt)
{
	char	*line;
	char	*line_p;
	int		i;

	line = (char *)malloc(line_len * sizeof(char));
	if (!line) {
		printf("integrate_to_line, line malloc error\n");
		exit(0);
	}
	line_p = line;
	i = 0;  
	while (i < buf_cnt - 1)
		line_p = my_strcat(line_p, buf_arr[i++], buf_size);
	line_p = my_strcat(line_p, buf_arr[i++], line_len - (line_p - line) + 1);

	return line;
}


char	*get_line(int fd, size_t buf_size, char **buf_arr, size_t buf_cnt)
{
	size_t	line_len;
	char	*line;
	int		buf_ep;
	size_t	read_size;
	
	buf_cnt = 0;

	while (1) {
		buf_cnt++;
		buf_arr = (char **)realloc(buf_arr, sizeof(char *) * buf_cnt);
		if (!buf_arr) {
			printf("get_line, buf_arr realloc error\n");
			exit(0);
		}
		buf_ep = read_bufSize(fd, buf_size, &buf_arr[buf_cnt-1], &read_size);

		if (buf_ep == 0) // EOF
		{
			line_len++;
			line = integrate_to_line(line_len, buf_size, buf_arr, buf_cnt);
			// buf_arr 관리
			return line;
		}
		else if (buf_ep != read_size) // 읽어온 buf에 "\n"이 있으면 
		{
			line_len += buf_ep;
			line = integrate_to_line(line_len, buf_size, buf_arr, buf_cnt);
			// buf_arr 관리
			return line;
		}
		else // 읽어온 buf에 "\n"이 없으면 
		{
			line_len += read_size;
		}
	}

	return line;

}

char    *get_next_line(int fd, size_t buf_size)
{
	char	**buf_arr;
	size_t	buf_cnt;
	char	*line;

	// buf size 처리
	buf_arr = (char**)malloc(0);
	if (!buf_arr) {
		printf("get_next_line, buf_arr malloc error\n");
		exit(0);
	}
	line = get_line(fd, buf_size, buf_arr, buf_cnt);
	if (*line) return (line);
	else return 0;
}



#include <fcntl.h>
#include <stdlib.h>

int main() {
	size_t buf_size = 10;
	int fd = open("test.txt", O_RDONLY);
	while (1) {
		char *res = get_next_line(fd, buf_size);
		if (!res) break;
		while (*res != '\n' && *res != '\0')
			write(1, res++, 1);
		write(1, res, 1);
	}
	

}