/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:00:13 by heson             #+#    #+#             */
/*   Updated: 2023/02/27 16:13:33 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h> // exit

void	print_error_n_exit(char *err_message)
{
	ft_printf("Error\n: %s\n", err_message);
	exit(0);
}

t_point	get_next_point(t_point cur, int dir)
{
	int		yy[4];
	int		xx[4];
	t_point	next;

	yy[0] = -1;
	yy[1] = 0;
	yy[2] = 1;
	yy[3] = 0;
	xx[0] = 0;
	xx[1] = 1;
	xx[2] = 0;
	xx[3] = -1;
	next.y = cur.y + yy[dir];
	next.x = cur.x + xx[dir];
	return (next);
}
