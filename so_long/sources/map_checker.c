/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:57:43 by heson             #+#    #+#             */
/*   Updated: 2023/02/27 16:09:58 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/so_long_map.h"

bool	check_file_type(char *file)
{
	char	**file_dir_split;
	char	**file_name_split;
	int		i;

	file_dir_split = ft_split(file, '/');
	i = 0;
	while (file_dir_split[i])
		i++;
	if (i < 1)
		return (ERROR_B);
	file_name_split = ft_split(file_dir_split[i - 1], '.');
	i = 0;
	while (file_name_split[i])
		i++;
	if (i != 2 || ft_strncmp(file_name_split[i - 1], "ber", 4) != 0)
		return (ERROR_B);
	return (true);
}

bool	check_path(char **ch, t_point cur, int item_cnt)
{	
	int		d;
	t_point	next;
	bool	is_found;

	is_found = false;
	d = -1;
	while (++d < DIR_CNT && !is_found)
	{
		next = get_next_point(cur, d);
		if (ch[next.y][next.x] == WALL)
			continue ;
		if (ch[next.y][next.x] == EXIT)
			return (item_cnt == 0);
		if (ch[next.y][next.x] == ITEM)
			item_cnt--;
		ch[next.y][next.x] = WALL;
		is_found = check_path(ch, next, item_cnt);
		ch[next.y][next.x] = EMPTY;
	}
	return (is_found);
}

bool	check_line(char *line, int width, bool is_mid, int **pei_cnt)
{
	int		i;

	i = -1;
	while (++i < width)
	{
		if (!is_mid)
		{
			if (line[i] != WALL)
				return (ERROR_B);
			continue ;
		}
		if (!(line[i] == WALL || line[i] == EMPTY
				|| line[i] == PLAYER || line[i] == EXIT || line[i] == ITEM))
			return (ERROR_B);
		if (line[i] == PLAYER)
			(*pei_cnt)[0]++;
		else if (line[i] == EXIT)
			(*pei_cnt)[1]++;
		else if (line[i] == ITEM)
			(*pei_cnt)[2]++;
	}
	if (!(line[0] == WALL && line[width - 1] == WALL)
		|| !(line[width] == '\0' || line[width] == '\n'))
		return (ERROR_B);
	return (true);
}

bool	check_map_format(t_list *lines, int height, int width)
{
	int		*pei_cnt;
	int		h;
	bool	is_mid;

	pei_cnt = (int *)ft_calloc(3, sizeof(int));
	h = 0;
	while (lines)
	{
		is_mid = !(h == 0 || h == height - 1);
		if (!check_line(lines->content, width, is_mid, &pei_cnt))
			return (ERROR_B);
		((char *)lines->content)[width] = '\0';
		h++;
		lines = lines->next;
	}
	if (!pei_cnt[0] || !pei_cnt[1] || !pei_cnt[2]
		|| pei_cnt[0] > 1 || pei_cnt[1] > 1)
		return (ERROR_B);
    return (true);
}
