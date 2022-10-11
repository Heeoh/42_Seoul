/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:38:58 by heson             #+#    #+#             */
/*   Updated: 2022/10/12 02:19:02 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*my_strcat(char *dst, char const *src, size_t n)
{
	// unsigned int	i;
	char	*p;

	// printf("my_strcat\n");
	// i = 0;
	p = (char *)src;
	while (p < src + n)
	{
		*dst++ = *p;
		if (*p == '\n' || *p == '\0')
			break ;
		p++;
	}
	return (dst);
}

t_Buf	*add_buf(t_Buf **buflst, t_Buf **last, char *data, size_t data_len)
{
	t_Buf	*new_buf;

	// printf("add_buf\n");
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

char	data_2_buflst(char	*data, t_Buf **buflst, t_Buf **last, t_Buf **ep, size_t *line_len)
{
	char	*newline_p;
	char	*data_p;
	char	is_nextline_found;

	// printf("data_2_buflst\n");
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
			if (!is_nextline_found)
			{
				*ep = *last;
				*line_len += (*last)->data_len;
			}
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

	// printf("find_next_line_buf\n");
	buf_p = buflst;
	is_nextline_found = FALSE;
	while (buf_p)
	{
		*line_len += buf_p->data_len;
		if (buf_p->data[buf_p->data_len - 1] == '\n')
		{
			is_nextline_found = TRUE;
			break ;
		}
		buf_p = buf_p->next;
	}
	if (is_nextline_found)
		return (buf_p);
	return (NULL);
}

void	free_buflst(t_Buf **buflst, t_Buf *new_head)
{
	t_Buf	*p;
	t_Buf	*next_p;

	// printf("free_buflst\n");
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