/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:35:12 by heson             #+#    #+#             */
/*   Updated: 2022/09/24 21:19:55 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <unistd.h> // read
// #include <stdlib.h> // malloc, free

#include <stdio.h> // test

size_t	read_bufsize(int fd, size_t buf_size, size_t *read_size, Buf **bufLst)
{
	char	*data;
	char	*newline_p;

	// read()로 buf_size만큼 읽어오기
	data = (char *)malloc(buf_size * sizeof(char));
	if (!data)
	{
		printf("read_bufSize, line malloc error\n");
		exit(0);
	}
	*read_size = read(fd, data, buf_size);

	// buf_list에 추가
	*bufLst = add_buf(bufLst, data, *read_size);

	newline_p = ft_strchr(data, '\n', *read_size);
	if (*read_size == 0)
	{
		(*bufLst)->data[0] = '\0';
		return (*read_size);
	}
	else if (newline_p != NULL)
		return (newline_p - data);
	else
		return (*read_size);
}

char	*integrate_to_line(size_t line_len, size_t buf_size, Buf *bufLst)
{
	char	*line;
	char	*line_p;
	Buf		*buflst_p;

	if (!line_len)
		return (NULL);
	line = (char *)malloc(line_len * sizeof(char));
	if (!line) 
	{
		printf("integrate_to_line, line malloc error\n");
		exit(0);
	}
	line_p = line;
	buflst_p = bufLst;
	while (buflst_p->next)
	{
		line_p = my_strcat(line_p, buflst_p->data, buf_size);
		buflst_p = buflst_p->next;
	}
	line_p = my_strcat(line_p, buflst_p->data, line_len - (line_p - line) + 1);

	return (line);
}

char	*get_line(int fd, size_t buf_size, char **backup, size_t *backup_size)
{
	size_t	line_len;
	char	*line;
	Buf		*buflst;
	Buf		*buflst_last;
	size_t	buf_ep;
	size_t	read_size;
	
	buflst = NULL;
	buflst_last = buflst;

	do_restore(backup, &buflst_last, *backup_size);
	buflst = buflst_last;
	line_len = *backup_size;
	while (1)
	{
		buf_ep = read_bufsize(fd, buf_size, &read_size, &buflst_last);
		if (!buflst)
			buflst = buflst_last;

		if (buf_ep == 0) // EOF
		{
			// line_len++;
			line = integrate_to_line(line_len, buf_size, buflst);
			free_bufLst(&buflst);
			*backup_size = 0;
			return (line);
		}
		else if (buf_ep != read_size) // 읽어온 buf에 "\n"이 있으면 
		{
			line_len += buf_ep++;
			line = integrate_to_line(line_len, buf_size, buflst);
			*backup_size = do_backup(backup, buflst_last->data + buf_ep, read_size - buf_ep);
			free_bufLst(&buflst);
			return (line);
		}
		else // 읽어온 buf에 "\n"이 없으면 
		{
			line_len += read_size;
		}
	}
	return (line);
} // 25줄 맞추기

char	*get_next_line(int fd, size_t buf_size)
{
	static char		*backup_buf;
	static size_t	backup_buf_size;
	char			*line;

	// buf size 처리
	line = get_line(fd, buf_size, &backup_buf, &backup_buf_size);
	if (!line)
		free(backup_buf);
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