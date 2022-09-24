/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/24 22:20:32 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <unistd.h> // read
// #include <stdlib.h> // malloc, free

#include <stdio.h> // test

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

char	*my_strcat(char *dst, char const *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i]) {
		*dst++ = src[i];
		if (src[i] == '\n' || src[i] == '\0')
			break ;
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while(str++)
		cnt++;
	return (cnt);
}

Buf	*add_buf(Buf **last, char *data, size_t data_len)
{
	Buf	*new_buf;
	
	new_buf = (Buf *)malloc(sizeof(Buf));
	if (!new_buf) {
		return 0;
	}
	new_buf->data = data;
	// new_buf->data[data_len] = '\0';
	new_buf->next = NULL;

	if (!*last) *last = new_buf;
	else (*last)->next = new_buf;

	return (new_buf);
}

size_t	do_backup(Buf **buflst, char *next_line_p, int len)
{
	char	*p;
	char	*data;

	data = (char *)malloc(len);
	if (!data) {
		printf("do_backup, malloc error\n");
		exit (0);
	}
	p = data;
	while (*next_line_p) {
		*p++ = *next_line_p++;
	}
	free_buflst(buflst);
	*buflst = NULL;
	add_buf(buflst, data, len);
	return (len);
}

void free_buflst(Buf **bufLst)
{
	Buf	*p;
	Buf	*next_p;

	p = *bufLst;
	while (p)
	{
		next_p = p->next;
		free(p->data);
		free(p);
		p = next_p;
	}
}

size_t	read_bufsize(int fd, size_t buf_size, size_t *read_size, Buf **bufLst)
{
	char	*data;
	char	*newline_p;

	// read()로 buf_size만큼 읽어오기
	data = (char *)malloc(buf_size * sizeof(char));
	if (!data)
	{
		printf("read_bufSize, line malloc error\n");
		exit(0);
	}
	*read_size = read(fd, data, buf_size);

	// buf_list에 추가
	*bufLst = add_buf(bufLst, data, *read_size);

	newline_p = ft_strchr(data, '\n', *read_size);
	if (*read_size == 0)
	{
		(*bufLst)->data[0] = '\0';
		return (*read_size);
	}
	else if (newline_p != NULL)
		return (newline_p - data + 1);
	else
		return (*read_size);
}

char	*integrate_to_line(size_t line_len, size_t buf_size, Buf *bufLst)
{
	char	*line;
	char	*line_p;
	Buf		*buflst_p;

	if (!line_len)
		return (NULL);
	line = (char *)malloc(line_len * sizeof(char));
	if (!line) 
	{
		printf("integrate_to_line, line malloc error\n");
		exit(0);
	}
	line_p = line;
	buflst_p = bufLst;
	while (buflst_p->next)
	{
		line_p = my_strcat(line_p, buflst_p->data, buf_size);
		buflst_p = buflst_p->next;
	}
	line_p = my_strcat(line_p, buflst_p->data, line_len - (line_p - line));

	return (line);
}

char	*get_line(int fd, size_t buf_size, Buf **buflst, size_t *backup_len)
{
	size_t	line_len;
	char	*line;
	Buf		*buflst_last;
	size_t	buf_ep;
	size_t	read_size;
	
	buflst_last = *buflst;
	line_len = *backup_len;
	while (1)
	{
		buf_ep = read_bufsize(fd, buf_size, &read_size, &buflst_last);
		if (!*buflst)
			*buflst = buflst_last;

		if (buf_ep == 0) // EOF
		{
			line = integrate_to_line(line_len, buf_size, *buflst);
			if (line_len) 
				free_buflst(buflst);
			*backup_len = 0;
			return (line);
		}
		else if (buf_ep != read_size) // 읽어온 buf에 "\n"이 있으면 
		{
			line_len += buf_ep;
			line = integrate_to_line(line_len, buf_size, *buflst);
			*backup_len = do_backup(buflst, buflst_last->data + buf_ep, read_size - buf_ep);
			return (line);
		}
		else // 읽어온 buf에 "\n"이 없으면 
			line_len += read_size;
	}
	return (line);
} // 25줄 맞추기

char	*get_next_line(int fd, size_t buf_size)
{
	static Buf		*buflst;
	static size_t	backup_len;
	char			*line;

	// buf size 처리
	line = get_line(fd, buf_size, &buflst, &backup_len);
	// if (!line)
	// 	free_buflst(&buflst);
	return (line);
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