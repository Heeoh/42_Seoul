/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:28 by heson             #+#    #+#             */
/*   Updated: 2022/11/30 13:34:48 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf_type_utils.h"
#include "headers/ft_printf_flag_utils.h"
#include "headers/ft_printf_utils.h"

#include <stdarg.h> // va_start, va_arg, va_copy, va_end
#include <stdlib.h> // free

#include <stdio.h>

int	get_data_c(t_data *data, t_va_argu argu, va_list ap)
{
	char	tmp[2];

	if (argu.type != CHAR)
		return (ERROR_I);
	tmp[0] = (char)va_arg(ap, int);
	tmp[1] = '\0';
	data->len = 1;
	data->data = ft_strndup(tmp, &(data->len));
	if (!data->data && !data->len)
		return (ERROR_I);
	return (data->len);
}

int	get_data_s(t_data *data, t_va_argu argu, va_list ap)
{
	char	*tmp;

	if (argu.type != STR)
		return (ERROR_I);
	tmp = va_arg(ap, char *);
	if (!tmp)
		data->data = ft_strndup("(null)", &(data->len));
	else
		data->data = ft_strndup(tmp, &(data->len));
	if (!data->data)
		return (ERROR_I);
	return (data->len);
}

int	get_data_di(t_data *data, t_va_argu argu, va_list ap)
{
	char	*tmp;

	tmp = ft_itoa(va_arg(ap, int));
	data->data = ft_strndup(tmp, &(data->len));
	if (argu.flags[SIGN])
		data->data = apply_sign_flag(data->data, argu, &(data->len));
	else if (argu.flags[SPACE])
		data->data = apply_space_flag(data->data, argu, &(data->len));
	free(tmp);
	if (!data->data)
		return (ERROR_I);
	return (data->len);
}

int	get_data_u(t_data *data, t_va_argu argu, va_list ap)
{
	char	*tmp;

	if (argu.type != U_INT)
		return (ERROR_I);
	tmp = ft_uitoa(va_arg(ap, unsigned int));
	data->data = ft_strndup(tmp, &(data->len));
	free(tmp);
	if (!data->data)
		return (ERROR_I);
	return (data->len);
}

int	get_data_x(t_data *data, t_va_argu argu, va_list ap)
{
	unsigned int	tmp_n;
	char			*tmp[2];

	tmp_n = va_arg(ap, unsigned int);
	tmp[0] = ft_itoa(tmp_n);
	tmp[1] = ft_convert_base(tmp[0], "0123456789", "0123456789abcdef");
	data->data = ft_strndup(tmp[1], &(data->len));
	if (argu.flags[BASE] && tmp_n != 0)
		data->data = apply_base_flag(data->data, argu, &(data->len));
	free(tmp[0]);
	free(tmp[1]);
	if (!data->data)
		return (ERROR_I);
	if (argu.type == UPPER_X)
		ft_str_toupper(data->data);
	return (data->len);
}

int	get_data_p(t_data *data, t_va_argu argu, va_list ap)
{
	unsigned long long	tmp_n;
	char				*tmp_str[3];

	if (argu.type != POINTER)
		return (ERROR_I);
	tmp_n = va_arg(ap, unsigned long long);
	tmp_str[0] = ft_ulltoa(tmp_n);
	tmp_str[1] = ft_convert_base(tmp_str[0], "0123456789", "0123456789abcdef");
	tmp_str[2] = ft_strndup(tmp_str[1], &(data->len));
	data->len += 2;
	data->data = ft_strjoin("0x", tmp_str[2], data->len);
	free(tmp_str[0]);
	free(tmp_str[1]);
	free(tmp_str[2]);
	if (!data->data)
		return (ERROR_I);
	return (data->len);
}
