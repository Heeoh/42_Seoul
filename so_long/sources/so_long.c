/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/02/20 19:14:51 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>


int close(t_vars *vars)
{
	ft_printf("close\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int resize(t_vars *vars)
{
	vars->win = vars->win;
	ft_printf("resize\n");
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	// printf("%d\n", keycode);
	if (keycode == 13)
		ft_printf("up\n");
	else if (keycode == 1)
		ft_printf("down\n");
	else if (keycode == 0)
		ft_printf("left\n");
	else if (keycode == 2)
		ft_printf("right\n");
	else if (keycode == 53) {
		ft_printf("ESC\n");
		close(vars);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	// t_vars	vars;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 640, 480, "test");
	// // mlx_key_hook(vars.win, key_hook, &vars);
	// mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, key_hook, &vars);
	// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	// mlx_hook(vars.win, 25, 1L<<18, resize, &vars);
	// mlx_loop(vars.mlx);

	map_parsing(int ac, char *av[]);
}