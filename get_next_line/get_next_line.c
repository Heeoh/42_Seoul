/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/10/10 16:18:22 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_strcat(char *dst, char const *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		*dst++ = src[i];
		if (src[i] == '\n' || src[i] == '\0')
			break ;
		i++;
	}
	return (dst);
}

t_Buf	*add_buf(t_Buf **buflst, t_Buf **last, char *data, size_t data_len)
{
	t_Buf	*new_buf;

	new_buf = (t_Buf *)malloc(sizeof(t_Buf));
	if (!new_buf)
		return (ERROR_P);
	new_buf->data = (char *)malloc(data_len + 1);
	if (!new_buf->data)
	{
		free(new_buf);
		new_buf = NULL;
		return (ERROR_P);
	}
	my_strcat(new_buf->data, data, data_len);
	new_buf->data[data_len] = '\0';
	new_buf->data_len = data_len;
	new_buf->next = NULL;
	if (!*buflst)
		*buflst = new_buf;
	else
		(*last)->next = new_buf;
	return (new_buf);
}

char	data_2_buflst(char	*data, t_Buf **buflst, t_Buf **last, t_Buf **ep)
{
	char	*newline_p;
	char	*data_p;
	char	is_nextline_found;

	newline_p = data;
	data_p = data;
	*ep = NULL;
	is_nextline_found = FALSE;
	while (*newline_p)
	{
		if (*newline_p == '\n' || *(newline_p + 1) == '\0')
		{
			*last = add_buf(buflst, last, data_p, newline_p - data_p + 1);
			if (*last == ERROR_P)
				return (ERROR_I);
			if (!*ep)
				*ep = *last;
			if (*newline_p == '\n')
				is_nextline_found = TRUE;
			data_p = newline_p + 1;
		}
		newline_p++;
	}
	return (is_nextline_found);
}

t_Buf	*find_next_line_buf(t_Buf *buflst, size_t *line_len)
{
	t_Buf	*buf_p;
	char	is_nextline_found;
	size_t	len;

	buf_p = buflst;
	is_nextline_found = FALSE;
	len = 0;
	while (buf_p)
	{
		len += buf_p->data_len;
		if (buf_p->data[buf_p->data_len - 1] == '\n')
		{
			is_nextline_found = TRUE;
			break ;
		}
		buf_p = buf_p->next;
	}
	if (is_nextline_found)
	{
		*line_len = len;
		return (buf_p);
	}
	return (NULL);
}

void	free_buflst(t_Buf **buflst, t_Buf *new_head)
{
	t_Buf	*p;
	t_Buf	*next_p;

	if (!buflst)
		return ;
	p = *buflst;
	while (p && p != new_head)
	{
		next_p = p->next;
		if (p->data)
			free(p->data);
		p->data = NULL;
		free(p);
		p = next_p;
	}
	*buflst = new_head;
}

char	read_bufsize(t_Info info, char **data, size_t *read_size)
{
	*data = (char *)malloc(info.buf_size * sizeof(char) + 1);
	if (!*data)
		return (ERROR_I);
	*read_size = read(info.fd, *data, info.buf_size);
	(*data)[*read_size] = '\0';
	if (!*read_size)
		return (TRUE);
	return (FALSE);
}

t_Buf	*read_line(t_Info info, t_Buf **buflst, t_Buf **last)
{
	char	is_line_end;
	char	*data;
	size_t	read_size;
	t_Buf	*buf_ep;

	is_line_end = FALSE;
	while (!is_line_end)
	{
		is_line_end = read_bufsize(info, &data, &read_size);
		if (is_line_end)
		{
			if (*last)
				buf_ep = *last;
			*last = add_buf(buflst, last, data, 1);
		}
		else if (is_line_end == ERROR_I)
			return (ERROR_P);
		else
			is_line_end = data_2_buflst(data, buflst, last, &buf_ep);
		free(data);
		data = NULL;
	}
	return (buf_ep);
}

char	*integrate_to_line(t_Buf *buflst, t_Buf *ep, size_t line_len)
{
	char	*line;
	char	*line_p;
	t_Buf	*buflst_p;

	if (!buflst || buflst->data[0] == '\0')
		return (NULL);
	buflst_p = buflst;
	while (buflst_p && buflst_p != ep->next)
	{
		line_len += buflst_p->data_len;
		buflst_p = buflst_p->next;
	}
	line = (char *)malloc(line_len * sizeof(char) + 1);
	if (!line)
		return (ERROR_P);
	line_p = line;
	buflst_p = buflst;
	while (buflst_p && buflst_p != ep->next)
	{
		line_p = my_strcat(line_p, buflst_p->data, buflst_p->data_len);
		buflst_p = buflst_p->next;
	}
	*line_p = '\0';
	return (line);
}

char	*get_line(t_Info info, t_Buf **buflst, t_Buf **buflst_last)
{
	char			*line;
	size_t			line_len;
	t_Buf			*buf_ep;

	line_len = 0;
	buf_ep = NULL;
	if (*buflst)
	{
		if ((*buflst)->data[0] == '\0')
		{
			free_buflst(buflst, NULL);
			buflst = NULL;
			return (NULL);
		}
		buf_ep = find_next_line_buf(*buflst, &line_len);
	}
	if (!buf_ep)
	{
		buf_ep = read_line(info, buflst, buflst_last);
	}
	line = integrate_to_line(*buflst, buf_ep, line_len);
	free_buflst(buflst, buf_ep->next);
	return (line);
}

char	*get_next_line(int fd, size_t buf_size)
{
	t_Info			info;
	char			*line;
	static t_Buf	*buflst;
	static t_Buf	*buflst_last;

	info.fd = fd;
	info.buf_size = buf_size;
	line = get_line(info, &buflst, &buflst_last);
	if (line && *line)
		return (line);
	return (NULL);
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
		res = NULL;
	}

	// while (1);
}