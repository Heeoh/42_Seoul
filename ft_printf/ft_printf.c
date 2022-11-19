/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:52:30 by heson             #+#    #+#             */
/*   Updated: 2022/11/19 22:10:51 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char g_types[8] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};

/* utils */
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t *size);
char	*ft_itoa(unsigned long long n);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);


// void	check_flag(){}

char	*check_format(char *p, t_va_argu *argu)
{
	argu->field_width = 0;
	argu->type = TYPE_INIT;
	if (p && *p)
	{
		while ('0' <= *p && *p <= '9')
		{
			argu->field_width = (argu->field_width * 10) + (*p - '0');
			p++;
		}
		for (int i = 0; i < TYPE_N; i++)
		{
			if (g_types[i] == *p)
			{
				argu->type = g_types[i];
				break;
			}
		}
		if (argu->type == TYPE_INIT)
			return (ERROR_P);
		return (p);
	}
	else
		return (ERROR_P);
}

#include <stdio.h>

// char	*get_number_data(char type, va_list ap)
// {

// }

t_data	*get_data(t_va_argu *argu, va_list ap)
{
	t_data	*data;
	char	tmp[2];
	unsigned long long	tmp_n;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ERROR_P);
	data->len = 0;
	if (argu->type == 'c')
	{
		data->len = 1;
		tmp[0] = (char)va_arg(ap, int);
		tmp[1] = '\0';
		data->data = ft_strndup(tmp, &(data->len));
	}
	else if (argu->type == 's')
		data->data = ft_strndup(va_arg(ap, char*), &(data->len));
	else if (argu->type == 'd' || argu->type == 'i')
		data->data = ft_strndup(ft_itoa(va_arg(ap, int)), &(data->len));
	else if (argu->type == 'x')
		data->data = ft_strndup(ft_convert_base(ft_itoa(va_arg(ap, unsigned int)), "0123456789", "0123456789abcdef"), &(data->len));
	else if (argu->type == 'X')
		data->data = ft_strndup(ft_convert_base(ft_itoa(va_arg(ap, unsigned int)), "0123456789", "0123456789ABCDEF"), &(data->len));
	else if (argu->type == 'p') {
		tmp_n = va_arg(ap, unsigned long long);
		data->data = ft_strndup(ft_convert_base(ft_itoa(tmp_n), "0123456789", "0123456789abcdef"), &(data->len));
	}
	if (!data->data)
		return (ERROR_P);
	return (data);
}

size_t	get_printed_len(t_va_argu *argu_info, t_data *argu_data) {
	if (argu_info->field_width > (int)argu_data->len) return (argu_info->field_width);
	else return (argu_data->len);
}

char	*get_printed_data(t_va_argu *argu_info, t_data *argu_data) {
	int		printed_len;
	char	*printed_data;
	char	*p;
	char	*data_p;

	printed_len = get_printed_len(argu_info, argu_data);
	printed_data = (char *)malloc(printed_len + 1);
	if (!printed_data) // malloc error
		return (ERROR_P);
	p = printed_data;
	while (printed_len-- > (int)argu_data->len)
		*p++ = ' ';
	data_p = argu_data->data;
	while (printed_len-- >= 0)
		*p++ = *data_p++;
	*p = '\0';
	return (printed_data);
}

int print_format(t_va_argu *argu_info, va_list ap)
{
	// printf("\nformat, field_width: %d, type: %c\n", node->field_width, node->type);
	// size_t	printed_len;
	char	*printed_data;
	t_data	*argu_data;
	int 	return_val;

	argu_data = get_data(argu_info, ap);	
	if (!argu_data)
		return (ERROR_I);
	printed_data = get_printed_data(argu_info, argu_data);
	if (!printed_data)
		return (ERROR_I);
	while (*printed_data) 
		write(1, printed_data++, 1);
	// printf("%s, %lu, |%s|\n", argu_data->data, argu_data->len, printed_data);
	
	return_val = argu_data->len;
	if (argu_data->data) free(argu_data->data);
	if (argu_data) free(argu_data);
	if (printed_data) free(printed_data);
	return (argu_data->len);
}

int	ft_printf(const char *str, ...)
{
	va_list 	ap;
    int			printed_len;
    char		*str_p;
    t_va_argu   *argu;

	printed_len = 0;
    str_p = (char *)str;
    va_start(ap, str);
    argu = (t_va_argu *)malloc(sizeof(t_va_argu));
	if (!argu) // malloc error
		return (ERROR_I);
    while (*str_p)
    {
        if (*str_p == '%' && *(str_p+1) != '%')
		{
			str_p = check_format(++str_p, argu);
            if (!str_p)
            {
                printf("error\n");
                return (ERROR_I);
            }
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
	
	if (argu) free(argu);
	return (printed_len);
	
}

// int main() {
// 	ft_printf("%%\nabcd\nggg\t\n%d\n", 123);
// 	while(1);
// }