/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/10/10 16:09:07 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	read_bufsize(t_Info i, char **data, size_t *read_size)
{
	char	is_nextline_found;

	*data = (char *)malloc(i.buf_size * sizeof(char) + 1);
	if (!*data)
		return (ERROR_I);
	*read_size = read(i.fd, *data, i.buf_size);
	(*data)[*read_size] = '\0';
	if (!*read_size)
		return (TRUE);
	return (FALSE);
}

t_Buf	*read_line(t_Info i, t_Buf **buflst, t_Buf **last, size_t *line_len)
{
	char	is_line_end;
	char	*data;
	size_t	read_size;
	t_Buf	*buf_ep;

	is_line_end = FALSE;
	while (!is_line_end)
	{
		is_line_end = read_bufsize(i, &data, &read_size);
		if (is_line_end)
		{
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

char	*get_line(t_Info info, t_Buf **buflst)
{
	char			*line;
	size_t			line_len;
	static t_Buf	*buflst_last;
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
		buf_ep = read_line(info, buflst, &buflst_last, &line_len);
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

	info.fd = fd;
	info.buf_size = buf_size;
	line = get_line(info, &buflst);
	if (line && *line)
		return (line);
	return (NULL);
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
// 		res = NULL;
// 	}

// 	// while (1);
// }