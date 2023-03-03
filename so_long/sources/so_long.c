/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/03/03 17:09:27 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/so_long_map.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include "../library/libft/libft.h"

int	close_mlx_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_2d_arr(game->map.board, game->map.height);
	exit(0);
}

void	move(t_game *game, int dir)
{
	t_point	cur;
	t_point	next;

	cur = game->player;
	next = get_next_point(cur, dir);
	if (game->map.board[next.r][next.c] == EXIT && game->item_cnt == 0)
	{
		game->move_cnt++;
		ft_printf("%d\n", game->move_cnt);
		ft_printf("********** CLEAR **********\n");
		ft_printf("Total number of moves is %d\n", game->move_cnt);
		close_mlx_win(game);
	}
	else if (game->map.board[next.r][next.c] == WALL
				|| game->map.board[next.r][next.c] == EXIT)
		return ;
	else if (game->map.board[next.r][next.c] == ITEM)
		game->item_cnt--;
	game->map.board[cur.r][cur.c] = EMPTY;
	game->map.board[next.r][next.c] = PLAYER;
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
		close_mlx_win(g);
	return (0);
}

void	init_game(t_game *g, char *file)
{
	t_point	p;
	char	**ch;
	bool	is_path_found;

	init_map(file, g, &ch);
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx,
			g->map.width * TILESIZE, g->map.height * TILESIZE, "game");
	set_imgs(g->mlx, &(g->img));
	g->move_cnt = 0;
	p.r = -1;
	while (++p.r < g->map.height)
	{
		p.c = -1;
		while (++p.c < g->map.width)
		{
			put_img(g, g->map.board[p.r][p.c], p.c * TILESIZE, p.r * TILESIZE);
			if (g->map.board[p.r][p.c] == PLAYER)
				g->player = p;
		}
	}
	is_path_found = check_path(ch, g->player, g->item_cnt);
	free_2d_arr(ch, g->map.height);
	if (!is_path_found)
		print_error_n_exit("no path available");
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		print_error_n_exit("wrong argument");
	init_game(&game, av[1]);
	mlx_hook(game.win, ON_KEYDOWN, 1L << 0, key_hook, &game);
	mlx_hook(game.win, ON_DESTROY, 0, close_mlx_win, &game);
	mlx_loop(game.mlx);
}
