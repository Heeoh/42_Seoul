/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:38:58 by heson             #+#    #+#             */
/*   Updated: 2022/09/21 21:49:47 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h";

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