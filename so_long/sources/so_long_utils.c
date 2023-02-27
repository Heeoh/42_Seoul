/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:00:13 by heson             #+#    #+#             */
/*   Updated: 2023/02/28 02:27:35 by heson            ###   ########.fr       */
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
	int		ver[4];
	int		hor[4];
	t_point	next;

	ver[0] = -1;
	ver[1] = 0;
	ver[2] = 1;
	ver[3] = 0;
	hor[0] = 0;
	hor[1] = 1;
	hor[2] = 0;
	hor[3] = -1;
	next.row = cur.row + ver[dir];
	next.col = cur.col + hor[dir];
	return (next);
}

void	set_imgs(void *mlx, t_img *img)
{
	int		h;
	int		w;

	img->ground = mlx_xpm_file_to_image(mlx, "./imgs/ground64.xpm", &h, &w);
	img->wall = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &h, &w);
	img->item = mlx_xpm_file_to_image(mlx, "./imgs/apple.xpm", &h, &w);
	img->exit = mlx_xpm_file_to_image(mlx, "./imgs/exit.xpm", &h, &w);
	img->front = mlx_xpm_file_to_image(mlx, "./imgs/front.xpm", &h, &w);
	img->back = mlx_xpm_file_to_image(mlx, "./imgs/back.xpm", &h, &w);
	img->right = mlx_xpm_file_to_image(mlx, "./imgs/right.xpm", &h, &w);
	img->left = mlx_xpm_file_to_image(mlx, "./imgs/left.xpm", &h, &w);
}

void	put_img(t_game *game, int tile_type, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
	if (tile_type == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x, y);
	else if (tile_type == ITEM)
		mlx_put_image_to_window(game->mlx, game->win, game->img.item, x, y);
	else if (tile_type == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
	else if (tile_type == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->img.front, x, y);
}

void	change_img(t_game *game, t_point from, t_point to, int dir)
{
	int	y;
	int	x;

	y = from.row * tile_size;
	x = from.col * tile_size;
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
	y = to.row * tile_size;
	x = to.col * tile_size;
	if (dir == UP)
		mlx_put_image_to_window(game->mlx, game->win, game->img.back, x, y);
	else if (dir == DOWN)
		mlx_put_image_to_window(game->mlx, game->win, game->img.front, x, y);
	else if (dir == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.right, x, y);
	else if (dir == LEFT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.left, x, y);
}
