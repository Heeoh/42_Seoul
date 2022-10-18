/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:15 by heson             #+#    #+#             */
/*   Updated: 2022/10/18 12:49:47 by heson            ###   ########.fr       */
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

enum e_type {
	INIT = 0,
	C = 'c',
	S = 's',
	P = 'p',
	D = 'd',
	I = 'i',
	U = 'u',
	LOW_X = 'x',
	UP_X = 'X',
	TYPE_N = 8
};

enum e_type	g_types[8] = {C, S, P, D, I, U, LOW_X, UP_X};

typedef struct s_va_argu {
    char				*pos;
    enum e_type			type;
    int					field_width;
	char				*ep;
	struct s_va_argu	*next;
} t_va_argu;

typedef struct s_argu_lst {
    t_va_argu	*head;
    t_va_argu	*last;
    size_t		size;
} t_argu_lst;

int	ft_printf(const char *str, ...);

#endif