/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:38:57 by heson             #+#    #+#             */
/*   Updated: 2023/03/05 16:58:45 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../headers/so_long_type.h"

void	print_error_n_exit(char *err_message);
t_point	get_next_point(t_point cur, int dir);
void	set_imgs(void *mlx, t_img *img);
void	put_img(t_game *game, int tile_type, int x, int y);
void	change_img(t_game *game, t_point from, t_point to, int dir);

#endif