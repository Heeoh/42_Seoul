/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:57:43 by heson             #+#    #+#             */
/*   Updated: 2023/03/03 16:50:25 by heson            ###   ########.fr       */
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
	free_2d_arr(file_dir_split, i);
	i = 0;
	while (file_name_split[i])
		i++;
	if (i != 2 || ft_strncmp(file_name_split[i - 1], "ber", 4) != 0)
	{
		free_2d_arr(file_name_split, i);
		return (ERROR_B);
	}
	free_2d_arr(file_name_split, i);
	return (true);
}

bool	check_line(char *line, int width, bool is_mid, int **pec)
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
			(*pec)[0]++;
		else if (line[i] == EXIT)
			(*pec)[1]++;
		else if (line[i] == ITEM)
			(*pec)[2]++;
	}
	if (!(line[0] == WALL && line[width - 1] == WALL)
		|| !(line[width] == '\0' || line[width] == '\n'))
		return (ERROR_B);
	return (true);
}

bool	check_map_format(t_list *lines, int height, int width, int *item_cnt)
{
	int		h;
	bool	is_mid;
	int		*pec;
	bool	is_succesful;

	is_succesful = true;
	pec = (int *)ft_calloc(3, sizeof(int));
	h = 0;
	while (lines && is_succesful)
	{
		is_mid = !(h == 0 || h == height - 1);
		is_succesful = check_line(lines->content, width, is_mid, &pec);
		((char *)lines->content)[width] = '\0';
		h++;
		lines = lines->next;
	}
	if (is_succesful && (!pec[0] || !pec[1] || !pec[2]
			|| pec[0] > 1 || pec[1] > 1))
		is_succesful = ERROR_B;
	*item_cnt = pec[2];
	free(pec);
	return (is_succesful);
}

bool	check_path(char **ch, t_point cur, int item_cnt)
{	
	int			d;
	t_point		next;
	static bool	is_found;
	static int	cnt;

	if (cnt == item_cnt + 1)
		return (true);
	if (ch[cur.r][cur.c] == EXIT && cnt == item_cnt)
		return (true);
	else if (ch[cur.r][cur.c] == EXIT)
		return (is_found);
	ch[cur.r][cur.c] = 'V';
	d = -1;
	while (++d < DIR_CNT && !is_found)
	{
		next = get_next_point(cur, d);
		if (ch[next.r][next.c] == WALL || ch[next.r][next.c] == 'V')
			continue ;
		if (ch[next.r][next.c] == ITEM)
			cnt++;
		is_found = check_path(ch, next, item_cnt);
	}
	return (is_found);
}
