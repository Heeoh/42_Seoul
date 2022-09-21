/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/21 22:48:42 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (i < n) {
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

Buf	*add_buf(Buf *last, char *data, size_t data_len)
{
	Buf	*new_buf;
	
	new_buf = (Buf *)malloc(sizeof(Buf));
	if (!new_buf) {
		return 0;
	}
	new_buf->data = data;
	new_buf->data[data_len] = '\0';
	new_buf->next = NULL;

	if (!last) last = new_buf;
	else last->next = new_buf;

	return (new_buf);
}

size_t	read_bufSize(int fd, size_t buf_size, size_t *read_size, Buf **bufLst_last)
{
	char	*data;
	char	*newline_p;

	// read()로 buf_size만큼 읽어오기
	data = (char *)malloc(buf_size * sizeof(char));
	if (!data) {
		printf("read_bufSize, line malloc error\n");
		exit(0);
	}
	*read_size = read(fd, data, buf_size);

	// buf_list에 추가
	*bufLst_last = add_buf(*bufLst_last, data, *read_size);
	
	newline_p = ft_strchr(data, '\n', *read_size);
	if (*read_size == 0){
		(*bufLst_last)->data[0] = '\0';
		return *read_size;
	}
	else if (newline_p != NULL)
		return (newline_p - data);
	else
		return *read_size;

}

char	*integrate_to_line(size_t line_len, size_t buf_size, Buf *bufLst)
{
	char	*line;
	char	*line_p;
	// Buf		*bufLst_p;

	line = (char *)malloc(line_len * sizeof(char));
	if (!line) {
		printf("integrate_to_line, line malloc error\n");
		exit(0);
	}
	line_p = line;
	// bufLst_p = bufLst;
	while (bufLst->next)
	{
		line_p = my_strcat(line_p, bufLst->data, buf_size);
		bufLst = bufLst->next;
	}
	line_p = my_strcat(line_p, bufLst->data, line_len - (line_p - line) + 1);

	return line;
}

void	backup(char **backup_buf, char *newt_line_p, int len)
{
	char	*p;

	*backup_buf = (char *)malloc(len + 1);
	if (!backup_buf) {
		printf("do_backup, malloc error\n");
		exit (0);
	}
	p = *backup_buf;
	while (p < *backup_buf + len) {
		*p++ = *newt_line_p++;
	}
	p = 0;
}

void	restore(char **backup_buf, Buf *bufLst_last) {
	int len;

	len = ft_strlen(*backup_buf);
	if (*backup_buf)
		bufLst_last = add_buf(bufLst_last, *backup_buf, len);
	free(*backup_buf);
}

void do_free(Buf *bufLst) {
	Buf	*p;
	Buf	*next_p;

	p = bufLst;
	while (p)
	{
		next_p = p->next;
		free(p);
		p = next_p;
	}
}

char	*get_line(int fd, size_t buf_size, char **backup_buf)
{
	size_t	line_len;
	char	*line;
	Buf		*bufLst;
	Buf		*bufLst_last;
	int		buf_ep;
	size_t	read_size;
	
	bufLst = NULL;
	bufLst_last = bufLst;

	restore(backup_buf, bufLst_last);
	bufLst = bufLst_last;
	line_len = 0;
	while (1) {
		buf_ep = read_bufSize(fd, buf_size, &read_size, &bufLst_last);
		if (!bufLst) bufLst = bufLst_last;

		if (buf_ep == 0) // EOF
		{
			line_len++;
			line = integrate_to_line(line_len, buf_size, bufLst);
			return (line);
		}
		else if (buf_ep != read_size) // 읽어온 buf에 "\n"이 있으면 
		{
			line_len += buf_ep;
			line = integrate_to_line(line_len, buf_size, bufLst);
			backup(backup_buf, bufLst_last->data + buf_ep + 1, read_size - (buf_ep + 1));
			do_free(bufLst);
			return (line);
		}
		else // 읽어온 buf에 "\n"이 없으면 
		{
			line_len += read_size;
		}
	}
	return (line);
}

char	*get_next_line(int fd, size_t buf_size)
{
	static char	*backup_buf;
	char		*line;

	// buf size 처리
	line = get_line(fd, buf_size, &backup_buf);
	// printf("backup: %s\n", backup_buf);
	if (*line)
		return (line);
	else
		return (NULL);
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