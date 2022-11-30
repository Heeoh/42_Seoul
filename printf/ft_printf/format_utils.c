/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:41:08 by heson             #+#    #+#             */
/*   Updated: 2022/11/30 13:31:22 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

void	init_format(t_va_argu *argu)
{
	int	i;

	argu->type = TYPE_INIT;
	argu->field_width = 0;
	i = 0;
	while (i < 6)
		argu->flags[i++] = FALSE;
}

int	checker(const char *p, char *target, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (target[i] == *p)
			break ;
	}
	return (i);
}

const char	*check_right_format(t_va_argu *argu, const char *right_sign)
{
	t_types	t;

	t = argu->type;
	if (t == TYPE_N)
		return (ERROR_P);
	if (argu->flags[BASE]
		&& !(t == LOWER_X || t == UPPER_X))
		return (ERROR_P);
	if ((argu->flags[SIGN] || argu->flags[SPACE])
		&& !(t == DECIMAL || t == INT))
		return (ERROR_P);
	if (argu->flags[ZERO]
		&& (t == CHAR || t == STR || t == POINTER))
		return (ERROR_P);
	return (right_sign);
}
