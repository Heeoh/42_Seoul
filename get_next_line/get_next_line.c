/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/26 20:03:36 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	read_bufsize(t_Info i, size_t *read_size, t_Buf **buflst, size_t *ep)
{
	char	*data;
	char	*newline_p;

	data = (char *)malloc(i.buf_size * sizeof(char) + 1);
	if (!data) // null guard
		return (ERROR_I);
	*read_size = read(i.fd, data, i.buf_size);
	data[*read_size] = '\0';
	*buflst = add_buf(buflst, data, *read_size);
	*ep = *read_size;
	newline_p = data;
	while (newline_p && *newline_p)
	{
		if (*newline_p++ == '\n')
		{
			*ep = newline_p - data;
			newline_p = NULL;
			break ;
		}
	}
	if (!*read_size || !newline_p)
		return (1);
	return (0);
}

int	read_line(t_Info i, t_Buf **buflst, t_Buf **lst_last, size_t *line_len)
{
	char	is_line_end;
	size_t	buf_ep;
	size_t	read_size;

	*lst_last = *buflst;
	while (1)
	{
		is_line_end = read_bufsize(i, &read_size, lst_last, &buf_ep);
		if (is_line_end < 0)
			return (ERROR_I);
		if (!*buflst)
			*buflst = *lst_last;
		if (is_line_end)
		{
			if (buf_ep > 0)
				*line_len += buf_ep;
			return (buf_ep);
		}
		else
			*line_len += read_size;
	}
}

char	*integrate_to_line(size_t line_len, size_t buf_size, t_Buf *buflst)
{
	char	*line;
	char	*line_p;
	t_Buf	*buflst_p;

	if (!line_len)
		return (NULL);
	line = (char *)malloc(line_len * sizeof(char) + 1);
	// null guard
	if (!line)
	{
		free_buflst(&buflst);
		return (NULL);
	}
	line_p = line;
	buflst_p = buflst;
	while (buflst_p->next)
	{
		line_p = my_strcat(line_p, buflst_p->data, buf_size);
		buflst_p = buflst_p->next;
	}
	line_p = my_strcat(line_p, buflst_p->data, line_len - (line_p - line));
	*line_p = '\0';
	return (line);
}

char	*get_line(t_Info info, t_Buf **buflst, size_t *backup_len)
{
	size_t	line_len;
	char	*line;
	t_Buf		*buflst_last;
	int		buf_ep;

	line_len = *backup_len;
	while (1)
	{
		buf_ep = read_line(info, buflst, &buflst_last, &line_len);
		if (!line_len)
			return (NULL);
		if (buf_ep == 0)
		{
			line = integrate_to_line(line_len, info.buf_size, *buflst);
			*backup_len = 0;
			break ;
		}
		else
		{
			line = integrate_to_line(line_len, info.buf_size, *buflst);
			*backup_len = do_backup(buflst, buflst_last, buf_ep);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd, size_t buf_size)
{
	t_Info			info;
	static t_Buf		*buflst;
	static size_t	backup_len;
	char			*line;

	// buf size 처리
	info.fd = fd;
	info.buf_size = buf_size;
	line = get_line(info, &buflst, &backup_len);
	if (!line)
		free_buflst(&buflst);
	return (line);
}

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> 

int main() {
	size_t buf_size = 10;
	int fd = open("test.txt", O_RDONLY);
	while (1) {
		char *res = get_next_line(fd, buf_size);
		if (!res) break;
		printf("%s", res);
		free (res);
	}

	// while (1);
}