/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:23:15 by heson             #+#    #+#             */
/*   Updated: 2022/10/19 16:23:16 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

# define ERROR_P NULL
# define ERROR_I -1
# define TRUE 1
# define FALSE 0

enum e_type {
	INIT = 0,
	C = 'c',
	S = 's',
	P = 'p',
	D = 'd',
	I = 'i',
	U = 'u',
	LOW_X = 'x',
	UP_X = 'X',
	TYPE_N = 8
};

enum e_type	g_types[8] = {C, S, P, D, I, U, LOW_X, UP_X};

typedef struct s_va_argu {
    char				*pos;
    enum e_type			type;
    int					field_width;
	char				*ep;
	struct s_va_argu	*next;
} t_va_argu;

typedef struct s_argu_lst {
    t_va_argu	*head;
    t_va_argu	*last;
    size_t		size;
} t_argu_lst;

void	check_flag(){}

t_va_argu	*add_node(t_argu_lst *lst, char *pos)
{
	t_va_argu	*new_node;

	new_node = (t_va_argu *)malloc(sizeof(t_va_argu));
	if (!new_node)
		return (ERROR_P);
	new_node->pos = pos;
	new_node->field_width = 0;
	new_node->type = INIT;
	new_node->next = NULL;

	if (lst->head == NULL)
		lst->head = new_node;
	else
		lst->last->next = new_node;

	return new_node;;
}

char	*check_format(char *p, t_va_argu *node)
{
	if (p && *p)
	{
		while ('0' <= *p && *p <= '9')
		{
			node->field_width += node->field_width * 10 + (*p - '0');
			p++;
		}
		for (int i = 0; i < TYPE_N; i++)
		{
			if (g_types[i] == *p)
			{
				node->type = g_types[i];
				break;
			}
		}
		if (node->type == INIT)
			return (ERROR_P);
		node->ep = p;
		return (p);
	}
	else
		return (ERROR_P);
}

int	find_va_argu(const char *str, t_argu_lst *lst)
{
	char	*p;

	p = (char *)str;
	while (p && *p)
	{
		if (*p == '%')
		{
			if (*(p+1) == '%')
				p++;
			else
			{
				lst->size++;
				lst->last = add_node(lst, p);
				if (lst->last == ERROR_P) // malloc error
					return (ERROR_I);
				p = check_format(++p, lst->last);
				if (!p) // format error
					return (ERROR_I);
			}
		}
		p++;
	}
	return (TRUE);
}

#include <stdio.h>

void print_format(t_va_argu *node, va_list ap)
{
	printf("\nformat, field_width: %d, type: %c\n", node->field_width, node->type);
	
	
}

int my_print(const char *str, t_argu_lst *lst, va_list ap)
{
	char		*str_p;
	t_va_argu	*lst_p;

	str_p = (char *)str;
	lst_p = lst->head;
	while (str_p && *str_p)
	{
		if (lst_p && str_p == lst_p->pos)
		{
			print_format(lst_p, ap);
			str_p = lst_p->ep;
			lst_p = lst_p->next;
		}
		else if (*str_p == '%')
			write(1, str_p++, 1);
		else
			write(1, str_p, 1);
		str_p++;
	}
	return (str_p - str);
}

int	ft_printf(const char *str, ...)
{
	va_list 	ap;
	t_argu_lst	lst;
	int			res;

	lst.head = NULL;
	lst.last = NULL;
	if (find_va_argu(str, &lst) == ERROR_I)
	{
		write(1, "error\n", 6);
		return (ERROR_I);
	}

	va_start(ap, str);
	res = my_print(str, &lst, ap);
	return (res);
	
}

int main() {
	ft_printf("hello\nd%3d c%10c s%17s p%1004p u%u i%i x%x X%X %%", 1);
}