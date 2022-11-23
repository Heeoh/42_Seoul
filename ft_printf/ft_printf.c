/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:52:30 by heson             #+#    #+#             */
/*   Updated: 2022/11/23 19:26:53 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include "headers/ft_printf_utils.h"
#include "headers/ft_printf_type_utils.h"

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

char	g_types[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};
int		(*g_to_string_by_type[TYPE_N])(t_data *, t_va_argu, va_list)
	= {get_data_c, get_data_s, get_data_p,
	get_data_diu, get_data_diu, get_data_diu,
	get_data_x, get_data_x};

// void	check_flag(){}

char	*check_format(char *p, t_va_argu *argu)
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
		if (argu->type == TYPE_INIT)
			return (ERROR_P);
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

size_t	get_printed_len(t_va_argu argu_info, t_data argu_data)
{
	if (argu_info.field_width > (int)argu_data.len)
		return (argu_info.field_width);
	else
		return (argu_data.len);
}

int	get_printed_data(t_data *printed, t_va_argu argu_info, t_data argu_data)
{
	char	*p;
	char	*data_p;
	int		cnt;

	printed->len = get_printed_len(argu_info, argu_data);
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

int	print_format(t_va_argu argu_info, va_list ap)
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

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			printed_len;
	char		*str_p;
	t_va_argu	argu;

	printed_len = 0;
	str_p = (char *)str;
	va_start(ap, str);
	while (*str_p)
	{
		if (*str_p == '%' && *(str_p + 1) != '%')
		{
			str_p = check_format(++str_p, &argu);
			if (!str_p)
				return (ERROR_I);
			printed_len += print_format(argu, ap);
		}
		else if (*str_p == '%')
		{
			write(1, str_p++, 1);
			printed_len++;
		}
		else
		{
			write(1, str_p, 1);
			printed_len++;
		}
		str_p++;
	}
	return (printed_len);
}

// #include <limits.h>

// int main() {
// 	// int tmp = 10;
// 	// ft_printf("%c, %s, %d, %i, %u, %x, %X, %p\n", 'a', "abc", 123, 1234, 12345, 15, 15, &tmp);
// 	// printf("%c, %s, %d, %i, %u, %x, %X, %p\n", 'a', "abc", 123, 1234, 12345, 15, 15, &tmp);

// 	// ft_printf("| %c|\n", '1');
// 	// printf("| %c|\n", '1');	

// 	// ft_printf("%s\n", (char*)0);
// 	// printf("%s\n", (char*)0);

// 	ft_printf("|%p| |%p|\n", LONG_MAX, LONG_MIN);
// 	printf("|%p| |%p|\n", LONG_MAX, LONG_MIN);
// 	printf("%s\n", ft_convert_base(ft_ulltoa(LONG_MIN), "0123456789", "0123456789abcdef"));

// 	// ft_printf(" %d, %d, %d, %d, %d, %d \n", -1, -9, -10, -14, -15, -16);
// 	// printf(" %d, %d, %d, %d, %d, %d \n", -1, -9, -10, -14, -15, -16);

// 	// printf("%s\n", ft_itoa(-1));
// 	// while(1);
// }