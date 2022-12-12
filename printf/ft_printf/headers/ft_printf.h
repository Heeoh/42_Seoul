/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:14:15 by heson             #+#    #+#             */
/*   Updated: 2022/12/12 16:30:31 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

# define ERROR_P NULL
# define ERROR_I -1
# define TRUE 1
# define FALSE 0

typedef enum e_types {
	CHAR = 0,
	STR,
	POINTER,
	DECIMAL,
	INT,
	U_INT,
	LOWER_X,
	UPPER_X,
	PERCENT,
	TYPE_N,
	TYPE_INIT = -1
}	t_types;

typedef enum e_flags {
	NEGATIVE_FW = 0,
	ZERO,
	PRECISION,
	BASE,
	SIGN,
	SPACE,
	FLAG_N
}	t_flags;

typedef struct s_va_argu {
	t_types	type;
	int		field_width;
	int		flags[6];
}	t_va_argu;

typedef struct s_data {
	char	*data;
	size_t	len;
}	t_data;

int	ft_printf(const char *str, ...);

#endif