/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:38:58 by heson             #+#    #+#             */
/*   Updated: 2022/09/24 23:13:59 by heson            ###   ########.fr       */
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
	while (i < n && src[i])
	{
		*dst++ = src[i];
		if (src[i] == '\n' || src[i] == '\0')
			break ;
		i++;
	}
	return (dst);
}

Buf	*add_buf(Buf **last, char *data, size_t data_len)
{
	Buf	*new_buf;

	new_buf = (Buf *)malloc(sizeof(Buf));
	if (!new_buf)
		return (0);
	new_buf->data = data;
	new_buf->next = NULL;
	if (!*last)
		*last = new_buf;
	else
		(*last)->next = new_buf;
	return (new_buf);
}

void	free_buflst(Buf **bufLst)
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

size_t	do_backup(Buf **buflst, size_t next_line_loc)
{
	Buf		*buf_p;
	char	*target;
	char	*data_p;
	char	*data;
	int		len;

	buf_p = *buflst;
	while (buf_p->next)
		buf_p = buf_p->next;
	target = buf_p->data + next_line_loc;
	len = 0;
	while (*target++)
		len++;
	data = (char *)malloc(len);
	if (!data)
	{
		printf("do_backup, malloc error\n");
		exit (0);
	}
	data_p = data;
	while (*target)
		*data_p++ = *target++;
	free_buflst(buflst);
	*buflst = NULL;
	add_buf(buflst, data, len);
	return (len);
}
