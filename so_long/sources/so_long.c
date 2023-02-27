/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/02/27 16:35:35 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include "../library/libft/libft.h"

int	close_mlx_win(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	ft_printf("the end\n");
	exit(0);
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

void	put_img(t_game *game, int tile_type, int pixel_x, int pixel_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, pixel_x, pixel_y);
	if (tile_type == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, pixel_x, pixel_y);
	else if (tile_type == ITEM)
		mlx_put_image_to_window(game->mlx, game->win, game->img.item, pixel_x, pixel_y);
	else if (tile_type == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, pixel_x, pixel_y);
	else if (tile_type == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->img.front, pixel_x, pixel_y);
}

void	change_img(t_game *game, t_point from, t_point to, int dir)
{
	int	pixel_x;
	int pixel_y;

	pixel_x = from.x * tile_size;
	pixel_y = from.y * tile_size;
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, pixel_x, pixel_y);
	pixel_x = to.x * tile_size;
	pixel_y = to.y * tile_size;
	if (dir == UP)
		mlx_put_image_to_window(game->mlx, game->win, game->img.back, pixel_x, pixel_y);
	else if (dir == DOWN)
		mlx_put_image_to_window(game->mlx, game->win, game->img.front, pixel_x, pixel_y);
	else if (dir == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.right, pixel_x, pixel_y);
	else if (dir == LEFT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.left, pixel_x, pixel_y);
}

void	move(t_game *game, int dir)
{
	t_point	cur;
	t_point	next;

	cur = game->player;
	next = get_next_point(cur, dir);
	if (game->map.board[next.y][next.x] == EXIT && game->item_cnt == 0)
	{
		ft_printf("*-------------------*\n");
		ft_printf("|    !! CLEAR !!    |\n");
		ft_printf("*-------------------*\n");
		ft_printf("Total number of moves is %d\n", game->move_cnt);
		close_mlx_win(game->mlx, game->win);
	}
	else if (game->map.board[next.y][next.x] == WALL || game->map.board[next.y][next.x] == EXIT)
		return ;
	else if (game->map.board[next.y][next.x] == ITEM)
		game->item_cnt--;
	game->map.board[cur.y][cur.x] = EMPTY;
	game->map.board[next.y][next.x] = PLAYER;
	game->player = next;
	change_img(game, cur, next, dir);
	game->move_cnt++;
	ft_printf("%d\n", game->move_cnt);
	mlx_loop(game->mlx);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		move(g, UP);
	else if (keycode == KEY_S)
		move(g, DOWN);
	else if (keycode == KEY_A)
		move(g, LEFT);
	else if (keycode == KEY_D)
		move(g, RIGHT);
	else if (keycode == KEY_ESC)
		close_mlx_win(g->mlx, g->win);
	return (0);
}

void	init(t_game *game, char *file)
{
	char	**ch;
	int	h;
	int	w;

	ch = NULL;
	map_parsing(file, &(game->map), ch);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * tile_size, game->map.height * tile_size, "game");
	set_imgs(game->mlx, &(game->img));
	game->item_cnt = 0;
	game->move_cnt = 0;
	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			put_img(game, game->map.board[h][w], w * tile_size, h * tile_size);
			if (game->map.board[h][w] == ITEM)
				game->item_cnt++;
			else if (game->map.board[h][w] == PLAYER)
			{
				game->player.y = h;
				game->player.x = w;
			}
			w++;
		}
		h++;
	}
	check_path(ch, game->player, game->item_cnt);
}

int	main(int ac, char *av[])
{
	t_game	game;
	

	if (ac != 2)
		return (0);
	
	init(&game, av[1]);
	mlx_hook(game.win, ON_KEYDOWN, 1L<<0, key_hook, &game);
	mlx_hook(game.win, ON_DESTROY, 0, close_mlx_win, &game);
	mlx_loop(game.mlx);

	// system("leaks so_long");
}