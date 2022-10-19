/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:52:30 by heson             #+#    #+#             */
/*   Updated: 2022/10/19 16:24:50 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(){}

char	*check_format(char *p, t_va_argu *argu)
{
	argu->field_width = 0;
	argu->type = INIT;
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
		if (argu->type == INIT)
			return (ERROR_P);
		return (p);
	}
	else
		return (ERROR_P);
}

#include <stdio.h>

void print_format(t_va_argu *node, va_list ap)
{
	printf("\nformat, field_width: %d, type: %c\n", node->field_width, node->type);
	
	
}

int	ft_printf(const char *str, ...)
{
	va_list 	ap;
    int			res;
    char		*str_p;
    t_va_argu   *argu;

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
            print_format(argu, ap);
		}
		else if (*str_p == '%')
			write(1, str_p++, 1);
		else
			write(1, str_p, 1);
		str_p++;
    }
	
	return (str_p - str);
	
}

int main() {
	ft_printf("hello\nd%3d c%10c s%17s p%1004p u%u i%i x%x X%X %%", 1);
}