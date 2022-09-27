/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/27 12:04:48 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*my_strcat(char *dst, char const *src, size_t n)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < n && src[i])
// 	{
// 		*dst++ = src[i];
// 		if (src[i] == '\n' || src[i] == '\0')
// 			break ;
// 		i++;
// 	}
// 	return (dst);
// }

// t_Buf	*add_buf(t_Buf **last, char *data, size_t data_len)
// {
// 	t_Buf	*new_buf;

// 	new_buf = (t_Buf *)malloc(sizeof(t_Buf));
// 	if (!new_buf)
// 		return (ERROR_P);
// 	new_buf->data = data;
// 	new_buf->next = NULL;
// 	if (!*last)
// 		*last = new_buf;
// 	else
// 		(*last)->next = new_buf;
// 	return (new_buf);
// }

// void	free_buflst(t_Buf **buflst)
// {
// 	t_Buf	*p;
// 	t_Buf	*next_p;

// 	p = *buflst;
// 	while (p)
// 	{
// 		next_p = p->next;
// 		free(p->data);
// 		free(p);
// 		p = next_p;
// 	}
// 	*buflst = NULL;
// }

// int	do_backup(t_Buf **buflst, size_t *backup_len, char *next_line_p)
// {
// 	char	*target;
// 	char	*p;
// 	char	*data;

// 	target = next_line_p;
// 	*backup_len = 0;
// 	p = target;
// 	while (*p++)
// 		(*backup_len)++;
// 	data = (char *)malloc(*backup_len + 1);
// 	if (!data)
// 		return (ERROR_I);
// 	p = data;
// 	while (*target)
// 		*p++ = *target++;
// 	*p = '\0';
// 	free_buflst(buflst);
// 	*buflst = NULL;
// 	if (add_buf(buflst, data, *backup_len) == ERROR_P)
// 		return (ERROR_I);
// 	return (*backup_len);
// }

char	read_bufsize(t_Info i, size_t *read_size, t_Buf **buflst, char **ep)
{
	char	*data;
	char	*newline_p;

	data = (char *)malloc(i.buf_size * sizeof(char) + 1);
	if (!data)
		return (ERROR_I);
	*read_size = read(i.fd, data, i.buf_size);
	data[*read_size] = '\0';
	*buflst = add_buf(buflst, data, *read_size);
	if (*buflst == ERROR_P)
		return (ERROR_I);
	*ep = (*buflst)->data + *read_size;
	newline_p = data;
	while (newline_p && *newline_p)
	{
		if (*newline_p++ == '\n')
		{
			*ep = newline_p;
			newline_p = NULL;
			break ;
		}
	}
	if (!*read_size || !newline_p)
		return (1);
	return (0);
}

char	*read_line(t_Info i, t_Buf **buflst, t_Buf **last, size_t *line_len)
{
	char	is_line_end;
	char	*buf_ep;
	size_t	read_size;

	*last = *buflst;
	while (1)
	{
		is_line_end = read_bufsize(i, &read_size, last, &buf_ep);
		if (is_line_end == ERROR_I)
			return (ERROR_P);
		if (!*buflst)
			*buflst = *last;
		if (is_line_end)
		{
			if (buf_ep != (*last)->data)
				*line_len += buf_ep - (*last)->data;
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
	if (!line)
		return (ERROR_P);
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
	t_Buf	*buflst_last;
	char	*buf_ep;

	line_len = *backup_len;
	while (1)
	{
		buf_ep = read_line(info, buflst, &buflst_last, &line_len);
		if (!line_len)
			return (NULL);
		line = integrate_to_line(line_len, info.buf_size, *buflst);
		if (!*buf_ep)
		{
			*backup_len = 0;
			break ;
		}
		else
		{
			if (do_backup(buflst, backup_len, buf_ep) == ERROR_I)
				return (ERROR_P);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd, size_t buf_size)
{
	t_Info			info;
	static t_Buf	*buflst;
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

// #include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h> 

// int main() {
// 	size_t buf_size = 10;
// 	int fd = open("test.txt", O_RDONLY);
// 	while (1) {
// 		char *res = get_next_line(fd, buf_size);
// 		if (!res) break;
// 		printf("%s", res);
// 		free (res);
// 	}

// 	// while (1);
// }