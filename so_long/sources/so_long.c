/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/02/26 04:01:03 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include "../library/libft/libft.h"


int close_mlx_win(void *mlx, void *win)
{
	ft_printf("close\n");
	mlx_destroy_window(mlx, win);
	exit(0);
}

void	change_img(t_game *game, t_point from, t_point to, int dir)
{

	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, from.x * tile_size, from.y * tile_size);
	if (dir == UP)
		mlx_put_image_to_window(game->mlx, game->win, game->img.back, to.x * tile_size, to.y * tile_size);
	else if (dir == DOWN)
		mlx_put_image_to_window(game->mlx, game->win, game->img.front, to.x * tile_size, to.y * tile_size);
	else if (dir == RIGHT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.right, to.x * tile_size, to.y * tile_size);
	else if (dir == LEFT)
		mlx_put_image_to_window(game->mlx, game->win, game->img.left, to.x * tile_size, to.y * tile_size);
}

void	move(t_game *game, int dir)
{
	int yy[4] = {-1, 0, 1, 0};
	int xx[4] = {0, 1, 0, -1};
	t_point cur;
	t_point next;

	cur.y = game->player.y;
	cur.x = game->player.x;
	next.y = cur.y + yy[dir];
	next.x = cur.x + xx[dir];
	if (game->map.board[next.y][next.x] == WALL) {
		// ft_printf("WALL, cannot move\n");
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
			// ft_printf("Collectible items are left.\n");
			return ;
		}
	}
	game->map.board[cur.y][cur.x] = EMPTY;
	game->map.board[next.y][next.x] = PLAYER;
	game->player.y = next.y;
	game->player.x = next.x;
	change_img(game, cur, next, dir);
	game->move_cnt++;
	ft_printf("%d\n", game->move_cnt);
	// ft_printf("%d. move to (%d, %d)\n", game->move_cnt, game->player.y, game->player.x);
	mlx_loop(game->mlx);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == KEY_UP)
		move(g, UP);
	else if (keycode == KEY_DOWN)
		move(g, DOWN);
	else if (keycode == KEY_LEFT)
		move(g, LEFT);
	else if (keycode == KEY_RIGHT)
		move(g, RIGHT);
	else if (keycode == KEY_ESC) {
		// ft_printf("ESC\n");
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
	char	path[4] = "../";

	img->ground = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/ground64.xpm"), &img_width, &img_height);
	img->wall = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/wall.xpm"), &img_width, &img_height);
	img->item = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/apple.xpm"), &img_width, &img_height);
	img->exit = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/exit.xpm"), &img_width, &img_height);
	img->front = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/front.xpm"), &img_width, &img_height);
	img->back = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/back.xpm"), &img_width, &img_height);
	img->right = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/right.xpm"), &img_width, &img_height);
	img->left = mlx_xpm_file_to_image(mlx, ft_strjoin(path, "imgs/left.xpm"), &img_width, &img_height);
}

void	init(t_game *game)
{
	int	h;
	int	w;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * tile_size, game->map.height * tile_size, "Hello world!");
	set_imgs(game->mlx, &(game->img));
	game->item_cnt = 0;
	h = 0;
	while (h < game->map.height)
	{
		w = 0;
		while (w < game->map.width)
		{
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
				mlx_put_image_to_window(game->mlx, game->win, game->img.front, w * tile_size, h * tile_size);
				game->player.y = h;
				game->player.x = w;
			}
			w++;
		}
		h++;
	}
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