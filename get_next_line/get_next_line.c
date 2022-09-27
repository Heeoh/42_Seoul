/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/27 16:59:14 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>

# define ERROR_I -1
# define ERROR_P NULL
# define TRUE 1
# define FALSE 0

typedef struct _Buf {
	char		*data;
	int			data_len;
	struct _Buf	*next;
}	t_Buf;

typedef struct _Info {
	int		fd;
	size_t	buf_size;
}	t_Info;

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

t_Buf	*add_buf(t_Buf **last, char *data, size_t data_len)
{
	t_Buf	*new_buf;
	char	*bufdata_p;

	new_buf = (t_Buf *)malloc(sizeof(t_Buf));
	if (!new_buf)
		return (ERROR_P);
	new_buf->data = (char *)malloc(data_len + 1);
	if (!new_buf->data)
	{
		free(new_buf);
		return (ERROR_P);
	}
	bufdata_p = my_strcat(new_buf->data, data, data_len);
	*bufdata_p = '\0';
	new_buf->data_len = data_len;
	new_buf->next = NULL;
	if (!*last)
		*last = new_buf;
	else
		(*last)->next = new_buf;
	return (new_buf);
}

void	free_buflst(t_Buf **buflst, t_Buf *new_head)
{
	t_Buf	*p;
	t_Buf	*next_p;

	p = *buflst;
	while (p != new_head)
	{
		next_p = p->next;
		free(p->data);
		free(p);
		p = next_p;
	}
	*buflst = new_head;
}

char	find_next_line_buf(t_Buf *buflst, t_Buf **ep)
{
	t_Buf	*buf_p;
	char	*data_p;
	char	is_nextline_found;

	buf_p = buflst;
	is_nextline_found = FALSE;
	while (buf_p)
	{
		if (buf_p->data[buf_p->data_len - 1] == '\n')
		{
			is_nextline_found = TRUE;
			break ;
		}
		buf_p = buf_p->next;
	}
	if (is_nextline_found)
		*ep = buf_p;
	return (is_nextline_found);
}

char	read_bufsize(t_Info i, t_Buf **buflst, t_Buf **lst_last, t_Buf **ep)
{
	char	*data;
	char	*newline_p;
	char	*tmp;
	char	is_nextline_found;
	size_t	read_size;

	data = (char *)malloc(i.buf_size * sizeof(char) + 1);
	if (!data)
		return (ERROR_I);
	read_size = read(i.fd, data, i.buf_size);
	data[read_size] = '\0';
	if (!read_size)
	{
		*lst_last = add_buf(lst_last, data, 1);
		return (TRUE);
	}
	newline_p = data;
	is_nextline_found = FALSE;
	tmp = data;
	while (*newline_p)
	{
		if (*newline_p == '\n')
		{
			*lst_last = add_buf(lst_last, tmp, newline_p - tmp + 1);
			if (*lst_last == ERROR_P)
			{
				free(data);
				return (ERROR_I);
			}
			if (!*buflst)
				*buflst = *lst_last;
			if (!is_nextline_found)
				*ep = *lst_last;
			is_nextline_found = TRUE;
			tmp = newline_p + 1;
		}
		newline_p++;
	}
	if (read_size - (tmp - data) > 0)
		add_buf(lst_last, tmp, read_size - (tmp - data));
	free(data);
	if (!read_size || is_nextline_found)
		return (TRUE);
	return (FALSE);
}

t_Buf	*read_line(t_Info i, t_Buf **buflst, t_Buf **last)
{
	char	is_line_end;
	t_Buf	*buf_ep;

	*last = *buflst;
	is_line_end = FALSE;
	while (1)
	{
		if (*buflst)
			is_line_end = find_next_line_buf(*buflst, &buf_ep);
		if (is_line_end == TRUE)
			return (buf_ep);
		is_line_end = read_bufsize(i, buflst, last, &buf_ep);
		if (is_line_end == ERROR_I)
			return (ERROR_P);
		if (!*buflst)
			*buflst = *last;
	}
	return (buf_ep);
}

char	*integrate_to_line(t_Buf *buflst, t_Buf *ep, char *isEOF)
{
	char	*line;
	char	*line_p;
	size_t	line_len;
	t_Buf	*buflst_p;

	if (!ep->next && !*(ep->data))
		*isEOF = TRUE;
	line_len = 0;
	buflst_p = buflst;
	while (buflst_p != ep->next)
	{
		line_len += buflst_p->data_len;
		buflst_p = buflst_p->next;
	}
	line = (char *)malloc(line_len * sizeof(char) + 1);
	if (!line)
		return (ERROR_P);
	line_p = line;
	buflst_p = buflst;
	while (buflst_p != ep->next)
	{
		line_p = my_strcat(line_p, buflst_p->data, buflst_p->data_len);
		buflst_p = buflst_p->next;
	}
	*line_p = '\0';
	return (line);
}

char	*get_line(t_Info info, t_Buf **buflst, size_t *backup_len, char *isEOF)
{
	char	*line;
	t_Buf	*buflst_last;
	t_Buf	*buf_ep;

	isEOF = FALSE;
	buf_ep = read_line(info, buflst, &buflst_last);
	line = integrate_to_line(*buflst, buf_ep, isEOF);
	free_buflst(buflst, buf_ep->next);
	return (line);
}

char	*get_next_line(int fd, size_t buf_size)
{
	t_Info			info;
	static t_Buf	*buflst;
	static size_t	backup_len;
	char			*line;
	static	char	isEOF;

	// buf size 처리
	if (!isEOF)
		return (NULL);
	info.fd = fd;
	info.buf_size = buf_size;
	line = get_line(info, &buflst, &backup_len, &isEOF);
	if (!line)
		free_buflst(&buflst, NULL);
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