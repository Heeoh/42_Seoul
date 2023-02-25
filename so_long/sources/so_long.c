/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/02/25 21:00:54 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include "../library/libft/libft.h"
// #include <fcntl.h> // open


int close_mlx_win(void *mlx, void *win)
{
	ft_printf("close\n");
	mlx_destroy_window(mlx, win);
	exit(0);
}

void	move(t_game *game, int dir)
{
	int yy[4] = {-1, 0, 1, 0};
	int xx[4] = {0, 1, 0, -1};
	t_point next;

	next.y = game->player.y + yy[dir];
	next.x = game->player.x + xx[dir];
	if (game->map.board[next.y][next.x] == WALL) {
		ft_printf("WALL, cannot move\n");
		return ;
	}
	else if (game->map.board[next.y][next.x] == ITEM)
		game->item_cnt--;
	else if (game->map.board[next.y][next.x] == EXIT)
	{
		if (game->item_cnt == 0)
			close_mlx_win(game->mlx, game->win);
		else
		{
			ft_printf("Collectible items are left.\n");
			return ;
		}
	}
	game->map.board[game->player.y][game->player.x] = EMPTY;
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, game->player.x * tile_size, game->player.y * tile_size);
	game->map.board[next.y][next.x] = PLAYER;
	game->player.y = next.y;
	game->player.x = next.x;
	mlx_put_image_to_window(game->mlx, game->win, game->img.player, game->player.x * tile_size, game->player.y * tile_size);
	game->move_cnt++;
	ft_printf("move to (%d, %d)\n", game->player.y, game->player.x);
	mlx_loop(game->mlx);
}

int	key_hook(int keycode, t_game *g)
{
	// printf("%d\n", keycode);
	if (keycode == KEY_UP)
		move(g, UP);
	else if (keycode == KEY_DOWN)
		move(g, DOWN);
	else if (keycode == KEY_LEFT)
		move(g, LEFT);
	else if (keycode == KEY_RIGHT)
		move(g, RIGHT);
	else if (keycode == KEY_ESC) {
		ft_printf("ESC\n");
		close_mlx_win(g->mlx, g->win);
	}
	return (0);
}

void	find_player(t_map *m, t_point *p)
{
	p->y = -1;
	while (++p->y < m->height)
	{
		p->x = -1;
		while (++p->x < m->width)
		{
			if (m->board[p->y][p->x] == PLAYER)
				return ;
		}
	}
}

void	set_imgs(void *mlx, t_img *img)
{
	int img_width;
	int	img_height;
	char	path[4] = "./";

	img->ground = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/ground.xpm"), &img_width, &img_height);
	img->wall = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/wall.xpm"), &img_width, &img_height);
	img->item = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/item.xpm"), &img_width, &img_height);
	img->exit = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/exit.xpm"), &img_width, &img_height);
	img->player = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/player.xpm"), &img_width, &img_height);
}

void	init(t_game *game)
{
	int	h;
	int	w;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * 32, game->map.height * 32, "Hello world!");
	set_imgs(game->mlx, &(game->img));
	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
			// if (game->map.board[h][w] == EMPTY)
			mlx_put_image_to_window(game->mlx, game->win, game->img.ground, w * tile_size, h * tile_size);
			if (game->map.board[h][w] == WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, w * tile_size, h * tile_size);
			else if (game->map.board[h][w] == ITEM)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img.item, w * tile_size, h * tile_size);
				game->item_cnt++;
			}
			else if (game->map.board[h][w] == EXIT)
				mlx_put_image_to_window(game->mlx, game->win, game->img.exit, w * tile_size, h * tile_size);
			else if (game->map.board[h][w] == PLAYER)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img.player, w * tile_size, h * tile_size);
				game->player.y = h;
				game->player.x = w;
			}
			w++;
		}
		h++;
	}
	// find_player(&(game->map), &(game->player));
	// game->map.map[game->player->y][game->player->x] = EMPTY;
	game->move_cnt = 0;

}


int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		return (0);
	if (!map_parsing(av[1], &(game.map)))
	{
		printf("Error\n");
		return (0);
	}
	for (int i=0; i<game.map.height; i++) {
		for (int j = 0; j< game.map.width; j++) {
			ft_printf("%c", game.map.board[i][j]);
		}
		ft_printf("\n");
	}
	
	init(&game);
	mlx_hook(game.win, ON_KEYDOWN, 1L<<0, key_hook, &game);
	mlx_hook(game.win, ON_DESTROY, 0, close, &game);
	mlx_loop(game.mlx);

	// system("leaks so_long");
}