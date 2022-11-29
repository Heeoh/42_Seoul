/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:06:05 by heson             #+#    #+#             */
/*   Updated: 2022/11/30 01:26:36 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/ft_printf_utils.h"

#include <stdlib.h>

char	*apply_base_flag(char *str, t_va_argu argu, size_t	*len)
{
	char	*res;

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
