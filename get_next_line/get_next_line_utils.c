/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:38:58 by heson             #+#    #+#             */
/*   Updated: 2022/10/10 17:17:21 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_strcat(char *dst, char const *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
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

// size_t	get_line_len(t_Buf *buflst, t_Buf *ep)
// {
// 	size_t	len;
// 	t_Buf	*p;

// 	len = 0;
// 	p = buflst;
// 	while (p && p != ep->next)
// 	{
// 		len += p->data_len;
// 		p = p->next;
// 	}
// 	return (len);
// }
