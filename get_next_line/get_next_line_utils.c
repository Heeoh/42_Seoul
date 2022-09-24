/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:38:58 by heson             #+#    #+#             */
/*   Updated: 2022/09/24 21:43:25 by heson            ###   ########.fr       */
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
	while (i < n && src[i]) {
		*dst++ = src[i];
		if (src[i] == '\n' || src[i] == '\0')
			break ;
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while(str++)
		cnt++;
	return (cnt);
}

Buf	*add_buf(Buf **last, char *data, size_t data_len)
{
	Buf	*new_buf;
	
	new_buf = (Buf *)malloc(sizeof(Buf));
	if (!new_buf) {
		return 0;
	}
	new_buf->data = data;
	new_buf->data[data_len] = '\0';
	new_buf->next = NULL;

	if (!*last) *last = new_buf;
	else (*last)->next = new_buf;

	return (new_buf);
}

size_t	do_backup(Buf **buflst, char *next_line_p, int len)
{
	char	*p;
	char	*data;

	data = (char *)malloc(len);
	if (!data) {
		printf("do_backup, malloc error\n");
		exit (0);
	}
	p = data;
	while (*next_line_p) {
		*p++ = *next_line_p++;
	}
	add_buf(buflst, data, len);
	return (len);
}

void	do_restore(char **backup_buf, Buf **bufLst_last, size_t len) {
	if (*backup_buf)
		*bufLst_last = add_buf(bufLst_last, *backup_buf, len);
}

void free_buflst(Buf **bufLst)
{
	Buf	*p;
	Buf	*next_p;

	p = *bufLst;
	while (p)
	{
		next_p = p->next;
		free(p);
		p = next_p;
	}
}