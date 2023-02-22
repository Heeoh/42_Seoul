/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:18 by heson             #+#    #+#             */
/*   Updated: 2023/02/22 19:38:27 by heson            ###   ########.fr       */
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

enum e_keycode {
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	KEY_ESC = 53
};

enum e_direction {
	UP = 0,
	RIGHT,
	DOWN,
	LEFT
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

typedef struct s_mlx_vars {
	void	*mlx;
	void	*win;
}	t_mlx_vars;


typedef struct s_game
{
	t_mlx_vars	vars;
	t_map		map;
	t_point		player;
	int			item_cnt;
	int			move_cnt;
}	t_game;

#endif