/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/03/01 15:40:09 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/so_long_map.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include "../library/libft/libft.h"

int	close_mlx_win(void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	exit(0);
}

void	move(t_game *game, int dir)
{
	t_point	cur;
	t_point	next;

	cur = game->player;
	next = get_next_point(cur, dir);
	if (game->map.board[next.row][next.col] == EXIT && game->item_cnt == 0)
	{
		ft_printf("*-------------------*\n");
		ft_printf("|    !! CLEAR !!    |\n");
		ft_printf("*-------------------*\n");
		ft_printf("Total number of moves is %d\n", game->move_cnt);
		close_mlx_win(game->mlx, game->win);
	}
	else if (game->map.board[next.row][next.col] == WALL
				|| game->map.board[next.row][next.col] == EXIT)
		return ;
	else if (game->map.board[next.row][next.col] == ITEM)
		game->item_cnt--;
	game->map.board[cur.row][cur.col] = EMPTY;
	game->map.board[next.row][next.col] = PLAYER;
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
	t_point	i;

	init_map(file, &(game->map), &ch);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map.width * tile_size, game->map.height * tile_size, "game");
	set_imgs(game->mlx, &(game->img));
	game->item_cnt = 0;
	game->move_cnt = 0;
	i.row = -1;
	while (++i.row < game->map.height)
	{
		i.col = -1;
		while (++i.col < game->map.width)
		{
			put_img(game, game->map.board[i.row][i.col], 
				i.col * tile_size, i.row * tile_size);
			if (game->map.board[i.row][i.col] == ITEM)
				game->item_cnt++;
			else if (game->map.board[i.row][i.col] == PLAYER)
				game->player = i;
		}
	}
	if (!check_path(ch, game->player, game->item_cnt))
		print_error_n_exit("no path to clear");
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		return (0);
	init(&game, av[1]);
	mlx_hook(game.win, ON_KEYDOWN, 1L << 0, key_hook, &game);
	mlx_hook(game.win, ON_DESTROY, 0, close_mlx_win, &game);
	mlx_loop(game.mlx);
}
