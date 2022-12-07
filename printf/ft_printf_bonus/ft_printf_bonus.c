/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:39:33 by heson             #+#    #+#             */
/*   Updated: 2022/12/07 21:37:44 by heson            ###   ########.fr       */
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

char	g_types[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};
char	g_flags[6] = {'-', '0', '.', '#', '+', ' '};
int		(*g_to_string_by_type[TYPE_N])(t_data *, t_va_argu, va_list)
	= {get_data_c, get_data_s, get_data_p,
	get_data_di, get_data_di, get_data_u,
	get_data_x, get_data_x};

const char	*check_format(const char *p, t_va_argu *argu)
{
	int	flag_i;
	int tmp;
	int is_precision_on;

	init_format(argu);
	is_precision_on = FALSE;
	if (*p == '%')
		return (p);
	while (p && *p)
	{
		while ('1' <= *p && *p <= '9')
		{
			tmp = *p++ - '0';
			while ('0' <= *p && *p <= '9')
				tmp = (tmp * 10) + (*p++ - '0');
			if (is_precision_on)
				argu->flags[PRECISION] = tmp;
			else
				argu->field_width = tmp;
			continue ;
		}
		flag_i = checker(p, g_flags, 6);
		if (flag_i != ERROR_I && flag_i != 6)
		{
			argu->flags[flag_i] = TRUE;
			if (flag_i == PRECISION)
			{
				is_precision_on = TRUE;
				argu->flags[flag_i] = 0;
				if (*(p + 1) == '0')
					p++;
			}
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
	if (argu_info.flags[NEGATIVE_FW])
	{
		apply_minus_flag(printed->data, &(printed->len));
		p = printed->data;
	}
	else if (argu_info.flags[ZERO])
	{
		apply_zero_flag(printed, argu_info, &argu_data);
		p = printed->data + (printed->len - argu_data.len);
	}
	else
	{
		p = printed->data;
		cnt = printed->len;
		while (cnt-- > (int)argu_data.len)
			*p++ = ' ';
		p = printed->data + (printed->len - argu_data.len);
	}
	data_p = argu_data.data;
	while (argu_data.len--)
		*p++ = *data_p++;
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
	
// 	int mine = ft_printf("%.d\n", 0);
// 	int ans = printf("%.d\n", 0);
// 	printf("%d, %d\n", mine, ans);

// 	// while(1);
// }
