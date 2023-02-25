/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:00:31 by heson             #+#    #+#             */
/*   Updated: 2023/02/26 00:49:56 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_type.h"
#include "../headers/get_next_line.h"
#include "../library/libft/libft.h"
#include <fcntl.h> // open
#include "../library/printf/headers/ft_printf.h"

// void	move(t_game *game, int dir);

// bool	check_path(t_point cur, int item_cnt, char **ch)
// {
// 	int	d;

// 	if (m->map[cur.y][cur.x] == EXIT)
// 		return (item_cnt == 0);
	
// 	d = 0;
// 	while (d < DIR_CNT)
// 	{
// 		if (move(m, ))
// 	}
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

char	*strndup_without_newline(char* str, int size)
{
	str[size] = '\0';
	return (ft_strdup(str));
}

int	check_format_n_init_map(t_list *lines, t_map *map)
{
	int		*pei_cnt;
	int		h;
	bool	is_mid;

	map->height = ft_lstsize(lines);
	map->width = ft_strlen(lines->content) - 1;
	map->board = (char **)malloc(sizeof(char *) * map->height);
	pei_cnt = (int *)ft_calloc(3, sizeof(int));
	h = 0;
	while (lines)
	{
		is_mid = !(h == 0 || h == map->height - 1);
		if (!check_line(lines->content, map->width, is_mid, &pei_cnt))
			return (ERROR_B);
		map->board[h++] = strndup_without_newline((char *)lines->content, map->width);
		lines = lines->next;
	}
	if (!pei_cnt[0] || !pei_cnt[1] || !pei_cnt[2]
		|| pei_cnt[0] > 1 || pei_cnt[1] > 1)
		return (ERROR_B);
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
	close(fd);
	return (line_lst);
}

bool	map_parsing(char *file, t_map *map)
{
	int		fd;
	t_list	*line_lst;

	// 파일 확장자 검사 .ber 인지
	fd = open(file, O_RDONLY);
	line_lst = read_map(fd);
	if (!line_lst)
		return (ERROR_B);
	if (!check_format_n_init_map(line_lst, map))
	{
		ft_lstclear(&line_lst, free);
		return (ERROR_B);
	}
	ft_lstclear(&line_lst, free);
	return (true);
}
