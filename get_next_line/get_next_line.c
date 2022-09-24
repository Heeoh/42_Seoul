/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/24 23:14:11 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <unistd.h> // read
// #include <stdlib.h> // malloc, free

#include <stdio.h> // test

size_t	read_bufsize(int fd, size_t buf_size, size_t *read_size, Buf **bufLst)
{
	char	*data;
	char	*newline_p;

	data = (char *)malloc(buf_size * sizeof(char) + 1);
	if (!data)
	{
		printf("read_bufSize, line malloc error\n");
		exit(0);
	}
	*read_size = read(fd, data, buf_size);
	data[*read_size] = '\0';
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

size_t	read_line(int fd, size_t buf_size, Buf **buflst, size_t *line_len)
{
	Buf		*buflst_last;
	size_t	buf_ep;
	size_t	read_size;

	buflst_last = *buflst;
	while (1)
	{
		buf_ep = read_bufsize(fd, buf_size, &read_size, &buflst_last);
		if (!*buflst)
			*buflst = buflst_last;
		if (buf_ep == 0)
			return (0);
		else if (buf_ep != read_size)
		{
			*line_len += buf_ep + 1;
			return (buf_ep);
		}
		else
			*line_len += read_size;
	}
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
	size_t	buf_ep;

	line_len = *backup_len;
	while (1)
	{
		buf_ep = read_line(fd, buf_size, buflst, &line_len);
		if (buf_ep == 0)
		{
			line = integrate_to_line(line_len, buf_size, *buflst);
			if (line_len)
				free_buflst(buflst);
			*backup_len = 0;
			break ;
		}
		else
		{
			line = integrate_to_line(line_len, buf_size, *buflst);
			*backup_len = do_backup(buflst, buf_ep);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd, size_t buf_size)
{
	static Buf		*buflst;
	static size_t	backup_len;
	char			*line;

	// buf size 처리
	line = get_line(fd, buf_size, &buflst, &backup_len);
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