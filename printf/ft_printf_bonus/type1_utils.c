/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type1_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:43:28 by heson             #+#    #+#             */
/*   Updated: 2022/12/12 21:03:02 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf_type_utils.h"
#include "headers/ft_printf_flag_utils.h"
#include "headers/ft_printf_utils.h"

#include <stdlib.h> // free

int	get_data_di(t_data *data, t_va_argu argu, va_list ap)
{
	char	*tmp;

	if (!(argu.type == DECIMAL || argu.type == INT))
		return (ERROR_I);
	tmp = ft_itoa(va_arg(ap, int));
	data->str = ft_strndup(tmp, &(data->len));
	if (argu.flags[PRECISION] != -1)
		data->str = apply_precision_flag(data->str, argu, data);
	if (argu.flags[PLUS])
		data->str = apply_plus_flag(data->str, argu, &(data->len));
	else if (argu.flags[SPACE])
		data->str = apply_space_flag(data->str, argu, &(data->len));
	free(tmp);
	if (!data->str)
		return (ERROR_I);
	return (data->len);
}

int	get_data_u(t_data *data, t_va_argu argu, va_list ap)
{
	char	*tmp;

	if (argu.type != U_INT)
		return (ERROR_I);
	tmp = ft_uitoa(va_arg(ap, unsigned int));
	data->str = ft_strndup(tmp, &(data->len));
	if (argu.flags[PRECISION] != -1)
		data->str = apply_precision_flag(data->str, argu, data);
	free(tmp);
	if (!data->str)
		return (ERROR_I);
	return (data->len);
}

int	get_data_x(t_data *data, t_va_argu argu, va_list ap)
{
	unsigned int	tmp_n;
	char			*tmp[2];

	if (!(argu.type == LOWER_X || argu.type == UPPER_X))
		return (ERROR_I);
	tmp_n = va_arg(ap, unsigned int);
	tmp[0] = ft_itoa(tmp_n);
	tmp[1] = ft_convert_base(tmp[0], "0123456789", "0123456789abcdef");
	data->str = ft_strndup(tmp[1], &(data->len));
	if (argu.flags[PRECISION] != -1)
		data->str = apply_precision_flag(data->str, argu, data);
	if (argu.flags[HASH] && tmp_n != 0)
		data->str = apply_hash_flag(data->str, argu, &(data->len));
	free(tmp[0]);
	free(tmp[1]);
	if (!data->str)
		return (ERROR_I);
	if (argu.type == UPPER_X)
		ft_str_toupper(data->str);
	return (data->len);
}
