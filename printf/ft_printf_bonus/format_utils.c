/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:41:08 by heson             #+#    #+#             */
/*   Updated: 2022/12/11 18:52:09 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include <unistd.h>

void	init_format(t_va_argu *argu)
{
	int	i;

	argu->type = TYPE_INIT;
	argu->field_width = 0;
	i = 0;
	while (i < 6)
		argu->flags[i++] = FALSE;
	argu->flags[PRECISION] = -1;
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
		argu->type = TYPE_INIT;
	else if (argu->flags[BASE]
		&& !(t == LOWER_X || t == UPPER_X))
		argu->flags[BASE] = FALSE;
	else if ((argu->flags[SIGN] || argu->flags[SPACE])
		&& !(t == DECIMAL || t == INT))
	{
		argu->flags[SIGN] = FALSE;
		argu->flags[SPACE] = FALSE;
	}
	else if ((argu->flags[NEGATIVE_FW] || argu->flags[PRECISION] != -1)
		&& argu->flags[ZERO])
		argu->flags[ZERO] = FALSE;
	else if (argu->flags[ZERO]
		&& (t == CHAR || t == STR || t == POINTER))
		argu->flags[ZERO] = FALSE;
	return (right_sign);
}
