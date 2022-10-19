/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:52:30 by heson             #+#    #+#             */
/*   Updated: 2022/10/20 01:14:07 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* utils */
size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t *size);
char	*ft_itoa(int n);

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

char	*ft_strndup(const char *s1, size_t *size)
{
	char	*res;
	size_t	i;

	if (!size)
		*size = ft_strlen(s1);
	res = (char *)malloc(*size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (((char *)s1)[i] && i < *size)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// itoa
int	get_num_len(int num)
{
	int	cnt;

	cnt = 0;
	if (num <= 0)
		cnt++;
	while (num != 0)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	unsigned int	res_len;
	char			*res;
	char			*p;

	res_len = get_num_len(n);
	res = (char *)malloc(res_len + 1);
	if (!res)
		return (NULL);
	p = res + res_len;
	*p-- = '\0';
	if (n == 0)
		*p = '0';
	else if (n < 0)
		*res = '-';
	while (n != 0)
	{
		*p-- = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (res);
}



void	check_flag(){}

char	*check_format(char *p, t_va_argu *argu)
{
	argu->field_width = 0;
	argu->type = TYPE_INIT;
	if (p && *p)
	{
		while ('0' <= *p && *p <= '9')
		{
			argu->field_width += argu->field_width * 10 + (*p - '0');
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

char	*get_data(char type, va_list ap, size_t *data_len)
{
	char	*data;

	data_len = NULL;
	if (type == 'c')
	{
		*data_len = 1;
		data = ft_strndup(va_arg(ap, char*), data_len);
	}
	else if (type == 's')
	{
		data = ft_strndup(va_arg(ap, char*), data_len);
	}
	else if (type == 'd')
		data = ft_strndup(ft_itoa(va_arg(ap, int)), data_len);
	
	return (data);
}

int print_format(t_va_argu *argu_info, va_list ap)
{
	// printf("\nformat, field_width: %d, type: %c\n", node->field_width, node->type);
	size_t	data_len;
	size_t	printed_len;
	char	*data;

	data = get_data(argu_info->type, ap, &data_len);	
	printf("%s, %lu\n", data, data_len);
	
	return (TRUE);
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
	
	return (printed_len);
	
}

int main() {
	// ft_printf("hello\nd%3d c%10c s%17s p%1004p u%u i%i x%x X%X %%", 1);
	ft_printf("hello\nd %d c %c s %s", 123, 'a', "end");
}