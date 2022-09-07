#include <unistd.h> // read
#include <stdlib.h> // malloc, free



char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (1)
	{
		if (*p == (char)c)
			return (p);
		if (!*p)
			return (0);
		p++;
	}
}

char	*my_strcat(char *dst, char const *src, size_t n)
{
	unsigned int	i;

	while (i < n) {
		*dst++ = src[i];
		if (src[i] == '\n' || src[i] == '\0')
			break ;
	}
	return (dst);
}

char	*ft_realloc();


char	*get_line(int fd, size_t buf_size, char **buf_arr, size_t buf_cnt)
{
	size_t	line_len;
	char	*line;
	char	*line_p;
	char	*tmp_buf;
	size_t	buf_len;
	int		i;

    // read()로 buf_size만큼 읽어오기
	tmp_buf = (char *)malloc(buf_size * sizeof(char));
	buf_len = read(fd, tmp_buf, buf_size);


	// 읽어온 buf에 "\0"이 있으면 
    //      - line_len에 "\0"까지의 바이트 크기 값을 더한 후 malloc, buf_arr[0]부터 buf_arr[cur]의 "/0"까지 복사
	if (ft_strchr(tmp_buf, '\0') != NULL)
	{
		line_len += buf_len;
		line = (char *)malloc(line_len * sizeof(char));
		line_p = line;
		i = 0;
		while (i < buf_cnt)
			line_p = my_strcat(line_p, buf_arr[i++], buf_size);
		my_strcat(line_p, tmp_buf, buf_len);
	}

	return line;

	// else if (ft_strchr(tmp_buf, '\n') != NULL)
	// {

	// }
	// else
	// {

	// }

    
    // 읽어온 buf에 "\n"이 없으면 
    //      - buf_arr를 realloc해서 읽어온 buf의 주소를 저장, 그 길이만큼을 line_len에 더함

    // 읽어온 buf에 "\n"이 있으면 
    //      - line_len에 "\n"까지의 바이트 크기 값을 더한 후 malloc, buf_arr[0]부터 buf_arr[cur]의 "/n"까지 복사
    //      - buf_arr를 모두 free한 후, "\n" 이후의 남은 값을 buf_arr[0]을 새로 malloc하여 저장

    // 읽어온 buf에 "\0"이 있으면 
    //      - line_len에 "\0"까지의 바이트 크기 값을 더한 후 malloc, buf_arr[0]부터 buf_arr[cur]의 "/0"까지 복사

    // line을 리턴
}

char    *get_next_line(int fd, size_t buf_size)
{
	char	**buf_arr;
	size_t	buf_cnt;

	// buf size 처리

	return (get_line(fd, buf_size, buf_arr, buf_cnt));
}


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int ac, char *av[]) {
	if (ac != 2) {
		printf("not enough argument values\n");
		return 0;
	}

	size_t buf_size = atoi(av[2]);
	int fd = open("test.txt", O_RDONLY);
	char *res = get_next_line(fd, buf_size);
	while (*res != '\n' || *res != '\0')
		write(1, res++, 1);
	write(1, res, 1);

}