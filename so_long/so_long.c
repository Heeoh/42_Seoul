/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/02/18 16:35:29 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int close(t_vars *vars)
{
	printf("close\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	// printf("%d\n", keycode);
	if (keycode == 13)
		printf("up\n");
	else if (keycode == 1)
		printf("down\n");
	else if (keycode == 0)
		printf("left\n");
	else if (keycode == 2)
		printf("right\n");
	else if (keycode == 53) {
		printf("ESC\n");
		close(vars);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "test");
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, key_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	mlx_loop(vars.mlx);
}