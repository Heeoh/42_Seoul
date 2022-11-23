/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:15 by heson             #+#    #+#             */
/*   Updated: 2022/11/23 19:22:22 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR_P NULL
# define ERROR_I -1
# define TRUE 1
# define FALSE 0

# include <stddef.h>

typedef enum e_types {
	CHAR = 0,
	STR,
	POINTER,
	DECIMAL,
	INT,
	U_INT,
	LOWER_X,
	UPPER_X,
	TYPE_N,
	TYPE_INIT = -1
} t_types;

typedef struct s_va_argu {
	t_types	type;
    int		field_width;
} t_va_argu;

typedef struct s_data {
    char    *data;
    size_t  len;
}   t_data;

int	ft_printf(const char *str, ...);

#endif