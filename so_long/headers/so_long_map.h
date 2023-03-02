/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:53 by heson             #+#    #+#             */
/*   Updated: 2023/03/02 13:37:32 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MAP_H
# define SO_LONG_MAP_H

# include "../headers/so_long_type.h"
# include "../library/libft/libft.h"

void	init_map(char *file, t_map *map, t_point *player);
bool	check_file_type(char *file);
bool	check_map_format(t_list *lines, int height, int width, int **pec);
bool	check_path(char **ch, t_point cur, int item_cnt);


#endif