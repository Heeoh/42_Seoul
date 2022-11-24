/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:52:30 by heson             #+#    #+#             */
/*   Updated: 2022/11/24 16:59:28 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/ft_printf_utils.h"
#include "headers/ft_printf_type_utils.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

char	g_types[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};
int		(*g_to_string_by_type[TYPE_N])(t_data *, t_va_argu, va_list)
	= {get_data_c, get_data_s, get_data_p,
	get_data_diu, get_data_diu, get_data_diu,
	get_data_x, get_data_x};

const char	*check_format(const char *p, t_va_argu *argu)
{
	t_types	i;

	argu->field_width = 0;
	argu->type = TYPE_INIT;
	if (p && *p)
	{
		while ('0' <= *p && *p <= '9')
		{
			argu->field_width = (argu->field_width * 10) + (*p - '0');
			p++;
		}
		i = TYPE_INIT;
		while (++i < TYPE_N)
		{
			if (g_types[i] == *p)
			{
				argu->type = i;
				break ;
			}
		}
		return (p);
	}
	return (ERROR_P);
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
	t_data	argu_data;
	t_data	printed_data;
	char	*p;

	if (get_data(&argu_data, argu_info, ap) == ERROR_I)
		return (ERROR_I);
	if (get_printed_data(&printed_data, argu_info, argu_data) == ERROR_I)
		return (ERROR_I);
	free(argu_data.data);
	p = printed_data.data;
	while (*p)
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
			if (argu.type != TYPE_INIT)
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
	// ft_printf("\f%d'V%cynht{W%cTG_(bg #\Q%cRX=@Z\nxuO%c(tc5\t{?0&%X9U_^%x3%i*%xS.Q-{JT.D", 392921044, 243115705, -1695961344, 1546056842, 1536353446, -1407275744, -753939550, 1263629710, -571117417);
	// printf("\f%d'V%cynht{W%cTG_(bg #\Q%cRX=@Z\nxuO%c(tc5\t{?0&%X9U_^%x3%i*%xS.Q-{JT.D", 392921044, 243115705, -1695961344, 1546056842, 1536353446, -1407275744, -753939550, 1263629710, -571117417);
	
	int mine = ft_printf("m: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	int ans = printf("a: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("%d, %d\n", ans, mine);

	usleep(1);
	
	mine = ft_printf("m: %c %c %c\n", 0, '0', '1');
	ans = printf("a: %c %c %c\n", 0, '0', '1');
	printf("%d, %d\n", ans, mine);

	// while(1);
}