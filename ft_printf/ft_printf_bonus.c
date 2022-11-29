/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:39:33 by heson             #+#    #+#             */
/*   Updated: 2022/11/30 01:27:21 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/ft_printf_utils.h"
#include "headers/ft_printf_type_utils.h"
#include "headers/ft_printf_format_utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

char	g_types[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};
char	g_flags[6] = {'-', '0', '.', '#', '+', ' '};
int		(*g_to_string_by_type[TYPE_N])(t_data *, t_va_argu, va_list)
	= {get_data_c, get_data_s, get_data_p,
	get_data_di, get_data_di, get_data_u,
	get_data_x, get_data_x};

const char	*check_format(const char *p, t_va_argu *argu)
{
	int	flag_i;

	if (*p == '%')
		return (p);
	init_format(argu);
	while (p && *p)
	{
		if ('1' <= *p && *p <= '9')
		{
			argu->field_width = *p++ - '0';
			while ('0' <= *p && *p <= '9')
				argu->field_width = (argu->field_width * 10) + (*p++ - '0');
			continue ;
		}
		flag_i = checker(p, g_flags, 6);
		if (flag_i != ERROR_I && flag_i != 6)
		{
			argu->flags[flag_i] = TRUE;
			p++;
			continue ;
		}
		break ;
	}
	argu->type = checker(p, g_types, TYPE_N);
	return (check_right_format(argu, p));
}

int	get_data(t_data *data, t_va_argu argu, va_list ap)
{
	data->len = 0;
	if (g_to_string_by_type[argu.type](data, argu, ap) == ERROR_I)
		return (ERROR_I);
	return (data->len);
}

int	get_printed_data(t_data *printed, t_va_argu argu_info, t_data argu_data)
{
	char	*p;
	char	*data_p;
	int		cnt;

	if (argu_info.field_width > (int)argu_data.len)
		printed->len = argu_info.field_width;
	else
		printed->len = argu_data.len;
	printed->data = (char *)malloc(printed->len + 1);
	if (!printed->data)
		return (ERROR_I);
	p = printed->data;
	cnt = printed->len;
	while (cnt-- > (int)argu_data.len)
		*p++ = ' ';
	data_p = argu_data.data;
	while (cnt-- >= 0)
		*p++ = *data_p++;
	*p = '\0';
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

#include <limits.h>
#include <stdio.h>

int main() {

	// int mine = ft_printf("%%\n");
	// int ans = printf("%%\n");
	// printf("a: %d, m: %d\n", mine, ans);

	ft_printf("%+d\n", 15);
	ft_printf("% d\n", 15);
	ft_printf("%#X, %X\n", 15, 15);
	// ft_printf("%+10d\n", 123);
	// ft_printf("% d\n", 123);
	// ft_printf("%-10d\n", 123);
	// ft_printf("%010d\n", 123);
	// ft_printf("%.10d\n", 123);

	// while(1);
}