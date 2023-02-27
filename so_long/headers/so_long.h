/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:38:57 by heson             #+#    #+#             */
/*   Updated: 2023/02/28 02:28:32 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../headers/so_long_type.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	print_error_n_exit(char *err_message);
t_point	get_next_point(t_point cur, int dir);
void	set_imgs(void *mlx, t_img *img);
void	put_img(t_game *game, int tile_type, int x, int y);
void	change_img(t_game *game, t_point from, t_point to, int dir);

#endif