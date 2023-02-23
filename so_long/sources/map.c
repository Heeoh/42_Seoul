/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:00:31 by heson             #+#    #+#             */
/*   Updated: 2023/02/23 20:24:24 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_type.h"
#include "../headers/get_next_line.h"
#include "../library/libft/libft.h"
#include <fcntl.h> // open
#include "../library/printf/headers/ft_printf.h"

// void	check_path(t_map *m, char **ch)
// {
	
// }

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

int	init_map(t_list *lines, t_map *m, int *item_cnt)
{
	int *pei_cnt;
	int	y;
	bool is_mid;

	m->height = ft_lstsize(lines);
	m->width = ft_strlen(lines->content) - 1;
	m->map = (char **)malloc(sizeof(char *) * m->height);
	pei_cnt = (int *)ft_calloc(3, sizeof(int));
	y = 0;
	while (lines)
	{
		is_mid = !(y == 0 || y == m->height - 1);
		if (!check_line(lines->content, m->width, is_mid, &pei_cnt))
			return (ERROR_B);
		((char *)lines->content)[m->width] = '\0';
		m->map[y++] = ft_strdup(lines->content);
		lines = lines->next;
	}
	if (!pei_cnt[0] || !pei_cnt[1] || !pei_cnt[2]
		|| pei_cnt[0] > 1 || pei_cnt[1] > 1)
		return (ERROR_B);
	*item_cnt = pei_cnt[2];
	return (true);
}

t_list	*read_map(int fd)
{
	t_list	*line_lst;
	t_list	*new;
	char	*line;

	if (fd <= 2)
		return (ERROR_P);
	line_lst = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = ft_lstnew(line);
		ft_lstadd_back(&line_lst, new);
	}
	return (line_lst);
}

bool map_parsing(char *file, t_map *map, int *item_cnt)
{
	int fd;
	t_list	*line_lst;

	fd = open(ft_strjoin("map/", file), O_RDONLY);
	line_lst = read_map(fd);
	if (!line_lst)
		return (ERROR_B);
	if (!init_map(line_lst, map, item_cnt))
	{
		// do_free(line_lst, map);
		return (ERROR_B);
	}
	return (true);
}
