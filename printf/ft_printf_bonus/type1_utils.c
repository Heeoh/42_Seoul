/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:28 by heson             #+#    #+#             */
/*   Updated: 2022/12/07 21:33:42 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf_type_utils.h"
#include "headers/ft_printf_flag_utils.h"
#include "headers/ft_printf_utils.h"

#include <stdlib.h> // free

int	get_data_di(t_data *data, t_va_argu argu, va_list ap)
{
	char	*tmp;

	tmp = ft_itoa(va_arg(ap, int));
	data->data = ft_strndup(tmp, &(data->len));
	if (argu.flags[PRECISION] != -1)
		data->data = apply_precision_flag(data->data, argu, data);
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
	if (argu.flags[PRECISION])
		data->data = apply_precision_flag(data->data, argu, data);
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
	if (argu.flags[PRECISION])
		data->data = apply_precision_flag(data->data, argu, data);
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
