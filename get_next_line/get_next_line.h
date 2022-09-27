/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:36:37 by heson             #+#    #+#             */
/*   Updated: 2022/09/27 15:53:55 by heson            ###   ########.fr       */
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
t_Buf	*add_buf(t_Buf **last, char *data, size_t data_len);
void	free_buflst(t_Buf **buflst, t_Buf *last);
// int		do_backup(t_Buf **buflst, t_Buf *last, size_t *backup_len);
char	*find_next_line_p(char *data);

char	read_bufsize(t_Info i, size_t *read_size, t_Buf **buflst, char **ep);
char	*read_line(t_Info i, t_Buf **buflst, t_Buf **last, size_t *line_len);
char	*integrate_to_line(size_t line_len, size_t buf_size, t_Buf *bufLst);
char	*get_line(t_Info info, t_Buf **buflst, size_t *backup_len);
char	*get_next_line(int fd, size_t buf_size);

#endif