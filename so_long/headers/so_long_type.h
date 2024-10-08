/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:18 by heson             #+#    #+#             */
/*   Updated: 2023/03/05 16:58:56 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPE_H
# define SO_LONG_TYPE_H

# include <stdbool.h>

# define ERROR_B 0
# define ERROR_I -1
# define ERROR_P NULL

# define TILESIZE 64

# define ON_KEYDOWN 2
# define ON_DESTROY 17

enum e_keycode {
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_ESC = 53
};

enum e_tile_type {
	EMPTY = '0',
	WALL = '1',
	ITEM = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

enum e_direction {
	UP = 0,
	RIGHT,
	DOWN,
	LEFT,
	DIR_CNT
};

typedef struct s_point {
	int	c;
	int	r;
}	t_point;

typedef struct s_map {
	char	**board;
	int		width;
	int		height;
}		t_map;

typedef struct s_img {
	void	*ground;
	void	*wall;
	void	*item;
	void	*exit;
	void	*front;
	void	*back;
	void	*right;
	void	*left;
}	t_img;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_point		player;
	int			item_cnt;
	int			move_cnt;
}	t_game;

#endif