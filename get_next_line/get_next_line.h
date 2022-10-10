/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:36:37 by heson             #+#    #+#             */
/*   Updated: 2022/10/10 16:17:54 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR_I -1
# define ERROR_P NULL
# define TRUE 1
# define FALSE 0

typedef struct _Buf {
	char		*data;
	int			data_len;
	struct _Buf	*next;
}	t_Buf;

typedef struct _Info {
	int		fd;
	size_t	buf_size;
}	t_Info;

char	*my_strcat(char *dst, char const *src, size_t n);
t_Buf	*add_buf(t_Buf **buflst, t_Buf **last, char *data, size_t data_len);
char	data_2_buflst(char	*data, t_Buf **buflst, t_Buf **last, t_Buf **ep);
t_Buf	*find_next_line_buf(t_Buf *buflst, size_t *line_len);
void	free_buflst(t_Buf **buflst, t_Buf *new_head);

char	read_bufsize(t_Info info, char **data, size_t *read_size);
t_Buf	*read_line(t_Info info, t_Buf **buflst, t_Buf **last);
char	*integrate_to_line(t_Buf *buflst, t_Buf *ep, size_t line_len);
char	*get_line(t_Info info, t_Buf **buflst, t_Buf **buflst_last);
char	*get_next_line(int fd, size_t buf_size);

#endif