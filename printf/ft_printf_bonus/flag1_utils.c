/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag1_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:06:05 by heson             #+#    #+#             */
/*   Updated: 2022/12/07 21:36:41 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/ft_printf_utils.h"

#include <stdlib.h>

char	*apply_minus_flag(char *str, size_t *len)
{
	int		cnt;
	char	*p;

	cnt = *len;
	p = str;
	while (cnt--)
		*p++ = ' ';
	return (str);
}

char	*apply_zero_flag(t_data	*printed, t_va_argu argu, t_data *data)
{
	int		cnt;
	char	*p;

	cnt = printed->len;
	p = printed->data;
	while (cnt--)
		*p++ = '0';
	if (argu.flags[SPACE] || argu.flags[SIGN] || data->data[0] == '-')
	{
		*(printed->data) = *(data->data);
		(data->data)++;
		data->len--;
	}
	return (printed->data);
}

char	*precision_str(size_t len, t_data *data)
{
	char	*new_data;
	char	*data_p;
	int		cnt;

	if (len >= data->len)
		return (data->data);
	new_data = (char *)malloc(len + 1);
	if (!new_data)
		return (ERROR_P);
	cnt = 0;
	data_p = data->data;
	while (cnt < (int)(len - data->len))
		new_data[cnt++] = ' ';
	while (cnt < (int)len)
		new_data[cnt++] = *data_p++;
	new_data[cnt] = '\0';
	data->len = len;
	free (data->data);
	return (new_data);
}

char	*precision_diux(t_va_argu argu, t_data *data)
{
	size_t	len;
	char	*new_data;
	int		cnt;
	char	*data_p;

	len = data->len;
	if (data->data[0] == '-')
		len--;
	if (data->data[0] != '0' && (int)len >= argu.flags[PRECISION])
		return (data->data);
	cnt = 0;
	data_p = data->data;
	data->len = argu.flags[PRECISION]; 
	if (data->data[0] == '-')
		data->len++;
	new_data = (char *)malloc(data->len + 1);
	if (!new_data)
		return (ERROR_P);
	if (data->data[0] == '-')
		new_data[cnt++] = *data_p++;
	while (cnt < (int)(data->len - len))
		new_data[cnt++] = '0';
	while (cnt < (int)data->len)
		new_data[cnt++] = *data_p++;
	new_data[cnt] = '\0';	
	free(data->data);
	return (new_data);
}

char	*apply_precision_flag(char *str, t_va_argu argu, t_data *data)
{
	if (argu.type == CHAR || argu.type == POINTER)
		return (ERROR_P);
	else if (argu.type == STR)
		return (precision_str(argu.flags[PRECISION], data));
	else
		return (precision_diux(argu, data));
	return (str);
}