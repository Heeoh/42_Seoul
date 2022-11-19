/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:15 by heson             #+#    #+#             */
/*   Updated: 2022/11/19 21:55:57 by heson            ###   ########.fr       */
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