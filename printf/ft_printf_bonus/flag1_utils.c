/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag1_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:06:05 by heson             #+#    #+#             */
/*   Updated: 2022/12/12 21:31:20 by heson            ###   ########.fr       */
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
	p = printed->str;
	while (cnt--)
		*p++ = '0';
	if (argu.flags[SPACE] || argu.flags[PLUS] || data->str[0] == '-')
	{
		printed->str[0] = data->str[0];
		(data->str)++;
		data->len--;
	}
	else if (argu.flags[HASH] && data->len >= 3)
	{
		p = printed->str;
		*p++ = *(data->str)++;
		*p++ = *(data->str)++;
		data->len -= 2;
	}
	return (printed->str + (printed->len - data->len));
}

char	*precision_str(size_t len, t_data *data)
{
	char	*new_data;
	char	*data_p;
	int		cnt;

	if (len >= data->len)
		return (data->str);
	new_data = (char *)malloc(len + 1);
	if (!new_data)
		return (ERROR_P);
	cnt = 0;
	data_p = data->str;
	while (cnt < (int)len)
		new_data[cnt++] = *data_p++;
	new_data[cnt] = '\0';
	data->len = len;
	free (data->str);
	return (new_data);
}

char	*precision_diux(t_va_argu argu, t_data *data)
{
	t_data	org;
	char	*new_p;

	org.len = data->len;
	org.str = data->str;
	if (org.str[0] == '-')
		argu.flags[PRECISION]++;
	if (org.str[0] != '0' && (int)org.len >= argu.flags[PRECISION])
		return (org.str);
	data->len = argu.flags[PRECISION];
	data->str = (char *)malloc(data->len + 1);
	if (!data->str)
		return (ERROR_P);
	new_p = data->str + data->len;
	while (new_p >= data->str && (int)org.len >= 0 && org.str[org.len] != '-')
		*new_p-- = org.str[org.len--];
	while (new_p >= data->str)
		*new_p-- = '0';
	if (org.str[0] == '-')
		data->str[0] = '-';
	free(org.str);
	return (data->str);
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
