/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag1_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:06:05 by heson             #+#    #+#             */
/*   Updated: 2022/12/11 20:10:46 by heson            ###   ########.fr       */
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
	else if (argu.flags[BASE] && data->len >= 3)
	{
		p = printed->data;
		*p++ = *(data->data)++;
		*p++ = *(data->data)++;
		data->len -= 2;
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
	t_data	org;
	int		cnt;
	char	*org_data_p;

	org.len = data->len;
	org.data = data->data;
	if (org.data[0] == '-')
		org.len--;
	if (org.data[0] != '0' && (int)(org.len) >= argu.flags[PRECISION])
		return (org.data);
	data->len = argu.flags[PRECISION];
	if (org.data[0] == '-')
		data->len++;
	data->data = (char *)malloc(data->len + 1);
	if (!data->data)
		return (ERROR_P);
	cnt = 0;
	org_data_p = org.data;
	if (org.data[0] == '-')
		data->data[cnt++] = *org_data_p++;
	while (cnt < (int)(data->len - org.len))
		data->data[cnt++] = '0';
	while (cnt < (int)data->len)
		data->data[cnt++] = *org_data_p++;
	data->data[cnt] = '\0';
	free(org.data);
	return (data->data);
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
