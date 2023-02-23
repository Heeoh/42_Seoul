/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:52:42 by heson             #+#    #+#             */
/*   Updated: 2023/02/23 20:42:50 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../library/printf/headers/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>


// int close(t_mlx_vars *vars)
// {
// 	ft_printf("close\n");
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	exit(0);
// }

// // int resize(t_game *g)
// // {
// // 	g->vars->win = vars->win;
// // 	ft_printf("resize\n");
// // 	return (0);
// // }
// void	move(t_game *game, int dir)
// {
// 	int yy[4] = {-1, 0, 1, 0};
// 	int xx[4] = {0, 1, 0, -1};
// 	t_point next;

// 	next.y = game->player.y + yy[dir];
// 	next.x = game->player.x + xx[dir];
// 	if (game->map.map[next.y][next.x] == WALL) {
// 		ft_printf("WALL, cannot move\n");
// 		return ;
// 	}
// 	else if (game->map.map[next.y][next.x] == ITEM)
// 	{
// 		ft_printf("ITEM, get item and ");
// 		game->item_cnt--;
// 		game->map.map[next.y][next.x] = EMPTY;
// 	}
// 	else if (game->map.map[next.y][next.x] == EXIT)
// 	{
// 		if (game->item_cnt == 0) {
// 			ft_printf("EXIT, game finish\n");
// 			close(&(game->vars));
// 		}
// 	}
// 	game->player.y = next.y;
// 	game->player.x = next.x;
// 	game->move_cnt++;
// 	ft_printf("move to (%d, %d)\n", game->player.y, game->player.x);
// }

// int	key_hook(int keycode, t_game *g)
// {
// 	// printf("%d\n", keycode);
// 	if (keycode == KEY_UP)
// 		move(g, UP);
// 	else if (keycode == KEY_DOWN)
// 		move(g, DOWN);
// 	else if (keycode == KEY_LEFT)
// 		move(g, LEFT);
// 	else if (keycode == KEY_RIGHT)
// 		move(g, RIGHT);
// 	else if (keycode == KEY_ESC) {
// 		ft_printf("ESC\n");
// 		close(&(g->vars));
// 	}
// 	return (0);
// }

// void	find_player(t_map *m, t_point *p)
// {
// 	p->y = -1;
// 	while (++p->y < m->height)
// 	{
// 		p->x = -1;
// 		while (++p->x < m->width)
// 		{
// 			if (m->map[p->y][p->x] == PLAYER)
// 				return ;
// 		}
// 	}
// }

// void	init(char *file, t_game *game)
// {
// 	if (!map_parsing(file, &(game->map), &(game->item_cnt)))
// 	{
// 		printf("Error\n");
// 		return ;
// 	}
// 	// for (int i=0; i < game->map.height; i++) {
// 	// 	for (int j=0; j < game->map.width; j++)
// 	// 		printf("%c ", game->map.map[i][j]);
// 	// 	printf("\n");
// 	// }
// 	find_player(&(game->map), &(game->player));
// 	game->map.map[game->player.y][game->player.x] = EMPTY;
// 	game->move_cnt = 0;
// 	// game->vars.mlx = mlx_init();
// 	// game->vars.win = mlx_new_window(game->vars.mlx, 1000, 1000, "test");
// 	// ft_printf("player at (%d, %d)\n", game->player.y, game->player.x);
// }


int	main()
{
	// t_game	game;

	// if (ac != 2)
	// 	return (0);
	// av[2] = 0;
	// init(av[1], &game);

	// mlx_key_hook(vars.win, key_hook, &vars);

	// vars->mlx = mlx_init();
	// vars->win = mlx_new_window(vars->mlx, 1000, 1000, "test");
	// game.vars.mlx = mlx;
	// game.vars.win = win;
	// img = mlx_xpm_file_to_image(vars->mlx, "/Users/heson/Desktop/42/so_long/test.xpm", &img_width, &img_height);
	// img = mlx_xpm_file_to_image(mlx, "imgs/ground.xpm", &img_width, &img_height);
    //xpm 파일을 불러와 이미지로 변환하고 img에 저장해줌
	// mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
    // xpm에서 이미지로 변환한 img를 화면에 (50,50)위치에 띄워줌
	// mlx_hook(vars->mlx, ON_KEYDOWN, 1L<<0, key_hook, vars);
	// mlx_hook(vars->mlx, ON_DESTROY, 0, close, vars);
	// mlx_loop(vars->mlx);

	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "./test.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);

}