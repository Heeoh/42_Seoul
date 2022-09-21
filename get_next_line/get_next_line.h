/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:36:37 by heson             #+#    #+#             */
/*   Updated: 2022/09/21 23:00:22 by heson            ###   ########.fr       */
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
size_t	ft_strlen(char *str);

Buf	    *add_buf(Buf *last, char *data, size_t data_len);
size_t	read_bufSize(int fd, size_t buf_size, size_t *read_size, Buf **bufLst_last);
char	*integrate_to_line(size_t line_len, size_t buf_size, Buf *bufLst);
char	*get_line(int fd, size_t buf_size, char **backup_buf, size_t *backup_buf_size);
char    *get_next_line(int fd, size_t buf_size);


#endif