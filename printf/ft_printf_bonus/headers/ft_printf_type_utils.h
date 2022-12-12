/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:01:25 by heson             #+#    #+#             */
/*   Updated: 2022/12/12 16:02:36 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPE_UTILS_H
# define FT_PRINTF_TYPE_UTILS_H

# include "ft_printf.h"
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

int	get_data_c(t_data *data, t_va_argu argu, va_list ap);
int	get_data_s(t_data *data, t_va_argu argu, va_list ap);
int	get_data_di(t_data *data, t_va_argu argu, va_list ap);
int	get_data_u(t_data *data, t_va_argu argu, va_list ap);
int	get_data_x(t_data *data, t_va_argu argu, va_list ap);
int	get_data_p(t_data *data, t_va_argu argu, va_list ap);
int	get_data_per(t_data *data);

#endif