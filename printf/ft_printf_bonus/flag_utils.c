/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:06:05 by heson             #+#    #+#             */
/*   Updated: 2022/11/30 18:11:18 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/ft_printf_utils.h"

#include <stdlib.h>

char	*apply_base_flag(char *str, t_va_argu argu, size_t	*len)
{
	char	*res;

	res = NULL;
	if (!(argu.type == UPPER_X || argu.type == LOWER_X))
		return (ERROR_P);
	*len += 2;
	res = ft_strjoin("0x", str, *len);
	free(str);
	return (res);
}

char	*apply_sign_flag(char *str, t_va_argu argu, size_t *len)
{
	char	*res;

	res = str;
	if (!(argu.type == DECIMAL || argu.type == INT))
		return (ERROR_P);
	if (*str != '-')
	{
		*len += 1;
		res = ft_strjoin("+", str, *len);
		free(str);
	}
	return (res);
}

char	*apply_space_flag(char *str, t_va_argu argu, size_t *len)
{
	char	*res;

	res = str;
	if (!(argu.type == DECIMAL || argu.type == INT))
		return (ERROR_P);
	if (*str != '-')
	{
		*len += 1;
		res = ft_strjoin(" ", str, *len);
		free(str);
	}
	return (res);
}

char	*apply_minus_flag(char *str, t_va_argu argu, size_t *len)
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