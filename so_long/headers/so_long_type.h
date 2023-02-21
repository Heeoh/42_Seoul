/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:18 by heson             #+#    #+#             */
/*   Updated: 2023/02/21 16:35:14 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPE_H
# define SO_LONG_TYPE_H

# include <stdbool.h> // bool

# define ERROR_B false
# define ERROR_I -1
# define ERROR_P NULL

enum e_type {
	EMPTY = '0',
	WALL = '1',
	ITEM = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	char	**map;
	int	width;
	int	height;
}		t_map;

typedef struct s_game
{
	t_map	map;
	t_point	player;
	int		item_cnt;
}	t_game;

#endif