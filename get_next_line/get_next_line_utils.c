/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:38:58 by heson             #+#    #+#             */
/*   Updated: 2022/09/26 20:08:32 by heson            ###   ########.fr       */
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

t_Buf	*add_buf(t_Buf **last, char *data, size_t data_len)
{
	t_Buf	*new_buf;

	new_buf = (t_Buf *)malloc(sizeof(t_Buf));
	// null huard
	new_buf->data = data;
	new_buf->next = NULL;
	if (!*last)
		*last = new_buf;
	else
		(*last)->next = new_buf;
	return (new_buf);
}

void	free_buflst(t_Buf **buflst)
{
	t_Buf	*p;
	t_Buf	*next_p;

	p = *buflst;
	while (p)
	{
		next_p = p->next;
		free(p->data);
		free(p);
		p = next_p;
	}
	*buflst = NULL;
}

size_t	do_backup(t_Buf **buflst, t_Buf *buflst_last, char *next_line_loc)
{
	char	*target;
	char	*p;
	char	*data;
	int		len;

	target = next_line_loc;
	len = 0;
	p = target;
	while (*p++)
		len++;
	data = (char *)malloc(len + 1);
	// null huard
	p = data;
	while (*target)
		*p++ = *target++;
	*p = '\0';
	free_buflst(buflst);
	*buflst = NULL;
	add_buf(buflst, data, len);
	return (len);
}
