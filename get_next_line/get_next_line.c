/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/24 23:42:03 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <unistd.h> // read
// #include <stdlib.h> // malloc, free

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
		return (NULL);
	new_buf->data = data;
	new_buf->next = NULL;
	if (!*last)
		*last = new_buf;
	else
		(*last)->next = new_buf;
	return (new_buf);
}

void	free_buflst(Buf **buflst)
{
	Buf	*p;
	Buf	*next_p;

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
	while (*target++)  // !!! 여기서 target을 증가시키면 뒤에서 데이터 복사불가!!
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


int	read_bufsize(int fd, size_t buf_size, size_t *read_size, Buf **buflst)
{
	char	*data;
	char	*newline_p;

	data = (char *)malloc(buf_size * sizeof(char) + 1);
	if (!data)
		return (-1);
	*read_size = read(fd, data, buf_size);
	data[*read_size] = '\0';
	*buflst = add_buf(buflst, data, *read_size);
	if (!*buflst)
		return (-1);
	newline_p = ft_strchr(data, '\n', *read_size);
	if (*read_size == 0)
	{
		(*buflst)->data[0] = '\0';
		return (*read_size);
	}
	else if (newline_p != NULL)
		return (newline_p - data + 1);
	else
		return (*read_size);
}

size_t	read_line(int fd, size_t buf_size, Buf **buflst, size_t *line_len)
{
	Buf		*buflst_last;
	int		buf_ep;
	size_t	read_size;

	buflst_last = *buflst;
	while (1)
	{
		buf_ep = read_bufsize(fd, buf_size, &read_size, &buflst_last);
		if (buf_ep < 0)
		{
			free_buflst(buflst);
			buflst = NULL;
			return (0);
		}
		if (!*buflst)
			*buflst = buflst_last;
		if (buf_ep == 0)
			return (0);
		else if (buf_ep != read_size)
		{
			*line_len += buf_ep + 1;
			return (buf_ep);
		}
		else
			*line_len += read_size;
	}
}

char	*integrate_to_line(size_t line_len, size_t buf_size, Buf *buflst)
{
	char	*line;
	char	*line_p;
	Buf		*buflst_p;

	if (!line_len)
		return (NULL);
	line = (char *)malloc(line_len * sizeof(char));
	if (!line)
	{
		free_buflst(&buflst);
		return (NULL);
	}
	line_p = line;
	buflst_p = buflst;
	while (buflst_p->next)
	{
		line_p = my_strcat(line_p, buflst_p->data, buf_size);
		buflst_p = buflst_p->next;
	}
	line_p = my_strcat(line_p, buflst_p->data, line_len - (line_p - line));
	return (line);
}

char	*get_line(int fd, size_t buf_size, Buf **buflst, size_t *backup_len)
{
	size_t	line_len;
	char	*line;
	size_t	buf_ep;

	line_len = *backup_len;
	while (1)
	{
		buf_ep = read_line(fd, buf_size, buflst, &line_len);
		if (!buflst) 
			return (NULL);
		if (buf_ep == 0)
		{
			line = integrate_to_line(line_len, buf_size, *buflst);
			if (line_len)
				free_buflst(buflst);
			*backup_len = 0;
			break ;
		}
		else
		{
			line = integrate_to_line(line_len, buf_size, *buflst);
			*backup_len = do_backup(buflst, buf_ep);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd, size_t buf_size)
{
	static Buf		*buflst;
	static size_t	backup_len;
	char			*line;

	// buf size 처리
	line = get_line(fd, buf_size, &buflst, &backup_len);
	return (line);
}

#include <fcntl.h>
#include <stdlib.h>

int main() {
	size_t buf_size = 10;
	int fd = open("test.txt", O_RDONLY);
	while (1) {
		char *res = get_next_line(fd, buf_size);
		if (!res) break;
		while (*res != '\n' && *res != '\0')
			write(1, res++, 1);
		write(1, res, 1);
	}

}