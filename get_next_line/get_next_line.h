/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:36:37 by heson             #+#    #+#             */
/*   Updated: 2022/09/24 23:12:15 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h> // read
#include <stdlib.h> // malloc, free

typedef struct _Buf {
	char *data;
	struct _Buf *next;
} Buf;

char	*ft_strchr(const char *s, int c, int n);
char	*my_strcat(char *dst, char const *src, size_t n);
// size_t	ft_strlen(char *str);
Buf		*add_buf(Buf **last, char *data, size_t data_len);
void	free_buflst(Buf **bufLst);
size_t	do_backup(Buf **buflst, size_t next_line_loc);

size_t	read_bufsize(int fd, size_t buf_size, size_t *read_size, Buf **bufLst);
size_t	read_line(int fd, size_t buf_size, Buf **buflst, size_t *line_len);
char	*integrate_to_line(size_t line_len, size_t buf_size, Buf *bufLst);
char	*get_line(int fd, size_t buf_size, Buf **buflst, size_t *backup_len);
char	*get_next_line(int fd, size_t buf_size);


#endif