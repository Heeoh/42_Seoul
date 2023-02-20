/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:18 by heson             #+#    #+#             */
/*   Updated: 2023/02/20 21:31:36 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum e_type {
	EMPTY = '0',
	WALL = '1',
	ITEM = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	int	**map;
	int	width;
	int	hegiht;
}		t_map;

typedef struct s_game
{
	t_map	map;
	t_point	player;
	int		item_cnt;
}	t_game;