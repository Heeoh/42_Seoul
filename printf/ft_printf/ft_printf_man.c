/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_man.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:52:30 by heson             #+#    #+#             */
/*   Updated: 2022/12/12 16:35:20 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/ft_printf_utils.h"
#include "headers/ft_printf_type_utils.h"
#include "headers/ft_printf_format_utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

char	g_types[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
int		(*g_to_string_by_type[TYPE_N])(t_data *, t_va_argu, va_list)
	= {get_data_c, get_data_s, get_data_p,
	get_data_di, get_data_di, get_data_u,
	get_data_x, get_data_x};

const char	*check_format(const char *p, t_va_argu *argu)
{
	init_format(argu);
	if (p && *p)
	{
		if ('1' <= *p && *p <= '9')
		{
			argu->field_width = *p++ - '0';
			while ('0' <= *p && *p <= '9')
				argu->field_width = (argu->field_width * 10) + (*p++ - '0');
		}
		argu->type = checker(p, g_types, TYPE_N);
		if (argu->type != TYPE_N)
			return (p);
	}
	return (ERROR_P);
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

int	print_by_format(t_va_argu argu_info, va_list ap)
{
	t_data			argu_data;
	unsigned int	printed_len;
	unsigned int	cnt;
	char			*data_p;

	if (get_data(&argu_data, argu_info, ap) == ERROR_I)
		return (ERROR_I);
	if (argu_info.field_width > (int)argu_data.len)
		printed_len = argu_info.field_width;
	else
		printed_len = argu_data.len;
	cnt = 0;
	data_p = argu_data.data;
	while (cnt < printed_len)
	{
		if (cnt < printed_len - argu_data.len)
			write(1, " ", 1);
		else
			write(1, data_p++, 1);
		cnt++;
	}
	free(argu_data.data);
	return (printed_len);
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
			else if (argu.type != TYPE_INIT && argu.type != TYPE_N)
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

// 	// int mine = ft_printf("\001\002\007\v\010\f\r\n");
// 	int ans = printf("\001\002\007\v\010\f\r\n");
// 	printf("ans: %d", ans);
// 	// printf("a: %d, m: %d\n", mine, ans);

// 	while(1);
// }
