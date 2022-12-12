/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:39:33 by heson             #+#    #+#             */
/*   Updated: 2022/12/12 17:32:15 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/ft_printf_utils.h"
#include "headers/ft_printf_flag_utils.h"
#include "headers/ft_printf_type_utils.h"
#include "headers/ft_printf_format_utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

char	g_types[TYPE_N] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
char	g_flags[FLAG_N] = {'-', '0', '.', '#', '+', ' '};
int		(*g_to_string_by_type[TYPE_N])(t_data *, t_va_argu, va_list)
	= {get_data_c, get_data_s, get_data_p,
	get_data_di, get_data_di, get_data_u,
	get_data_x, get_data_x};

const char	*check_format(const char *p, t_va_argu *argu)
{
	int	flag_i;

	init_format(argu);
	while (p && *p)
	{
		flag_i = checker(p, g_flags, FLAG_N);
		if (flag_i != FLAG_N)
		{
			argu->flags[flag_i] = TRUE;
			if (flag_i == PRECISION)
			{
				p = atoi_iter(++p, &argu->flags[PRECISION]);
				continue ;
			}
			p++;
			continue ;
		}
		if (!argu->field_width)
			p = atoi_iter(p, &argu->field_width);
		argu->type = checker(p, g_types, TYPE_N);
		if (argu->type != TYPE_N)
			return (check_right_format(argu, p));
	}
	return (check_right_format(argu, p));
}

int	get_data(t_data *data, t_va_argu argu, va_list ap)
{
	int	ret;

	data->len = 0;
	if (argu.type == PERCENT)
		ret = get_data_per(data);
	else
		ret = g_to_string_by_type[argu.type](data, argu, ap);
	return (ret);
}

int	get_printed_data(t_data *printed, t_va_argu argu_info, t_data argu_data)
{
	char	*p;
	int		cnt;

	printed->len = argu_data.len;
	if (argu_info.field_width > (int)argu_data.len)
		printed->len = argu_info.field_width;
	printed->data = (char *)malloc(printed->len + 1);
	if (!printed->data)
		return (ERROR_I);
	if (argu_info.flags[NEGATIVE_FW])
		p = apply_minus_flag(printed->data, &(printed->len));
	else if (argu_info.flags[ZERO])
		p = apply_zero_flag(printed, argu_info, &argu_data);
	else
	{
		p = printed->data;
		cnt = printed->len;
		while (cnt-- > (int)argu_data.len)
			*p++ = ' ';
	}	
	cnt = 0;
	while (cnt < (int)argu_data.len)
		*p++ = argu_data.data[cnt++];
	*(printed->data + printed->len) = '\0';
	return (printed->len);
}

int	print_by_format(t_va_argu argu_info, va_list ap)
{
	t_data			argu_data;
	t_data			printed_data;
	unsigned int	cnt;
	char			*p;

	if (get_data(&argu_data, argu_info, ap) == ERROR_I)
		return (ERROR_I);
	if (get_printed_data(&printed_data, argu_info, argu_data) == ERROR_I)
		return (ERROR_I);
	free(argu_data.data);
	p = printed_data.data;
	cnt = 0;
	while (cnt++ < printed_data.len)
		write(1, p++, 1);
	free(printed_data.data);
	return (printed_data.len);
}

int	ft_printf(const char *str_p, ...)
{
	va_list		ap;
	int			printed_len;
	t_va_argu	argu;

	printed_len = 0;
	va_start(ap, str_p);
	while (*str_p)
	{
		if (*str_p == '%')
		{
			str_p = check_format(++str_p, &argu);
			if (!str_p)
				return (ERROR_I);
			else if (argu.type != TYPE_INIT)
			{
				printed_len += print_by_format(argu, ap);
				str_p++;
				continue ;
			}
		}
		write(1, str_p++, 1);
		printed_len++;
	}
	return (printed_len);
}

// #include <limits.h>
// #include <stdio.h>

// int main() {
// 	int mine = ft_printf("%12+d\n", 123);
// 	int ans = printf("%12+d\n", 123);
// 	printf("%d, %d\n", mine, ans);

// 	// while(1);
// }
