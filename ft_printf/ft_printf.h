/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:15 by heson             #+#    #+#             */
/*   Updated: 2022/10/20 12:09:44 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# define ERROR_P NULL
# define ERROR_I -1
# define TRUE 1
# define FALSE 0
# define TYPE_INIT 0
# define TYPE_N 8

// typedef enum e_type {
// 	INIT = 0,
// 	C = 'c',
// 	S = 's',
// 	P = 'p',
// 	D = 'd',åå
// 	I = 'i',
// 	U = 'u',
// 	LOW_X = 'x',
// 	UP_X = 'X',
// 	TYPE_N = 8
// }	t_type;

char	g_types[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};

typedef struct s_va_argu {
	char	type;
    int		field_width;
} t_va_argu;

typedef struct s_data {
    char    *data;
    size_t  len;
}   t_data;

int	ft_printf(const char *str, ...);

#endif