/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:00:31 by heson             #+#    #+#             */
/*   Updated: 2023/02/26 21:45:33 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_type.h"
#include "../headers/get_next_line.h"
#include "../library/libft/libft.h"
#include <fcntl.h> // open
#include "../library/printf/headers/ft_printf.h"

// extern void	move(t_game *game, int dir);

bool	can_move2next(char **board, t_point cur, t_point *next, int dir)
{
	int		yy[4] = {-1, 0, 1, 0};
	int		xx[4] = {0, 1, 0, -1};

	next->y = cur.y + yy[dir];
	next->x = cur.x + xx[dir];
	if (board[next->y][next->x] == EXIT && game->item_cnt == 0)
	{
		ft_printf("*-------------------*\n");
		ft_printf("|    !! CLEAR !!    |\n");
		ft_printf("*-------------------*\n");
		ft_printf("Total number of moves is %d\n", game->move_cnt);
		close_mlx_win(game->mlx, game->win);
	}
	else if (game->map.board[next.y][next.x] == WALL || game->map.board[next.y][next.x] == EXIT)
		return ;
	else if (game->map.board[next.y][next.x] == ITEM)
		game->item_cnt--;
}

bool	check_path(char **ch, t_point cur, int item_cnt)
{
	int		yy[4] = {-1, 0, 1, 0};
	int		xx[4] = {0, 1, 0, -1};	
	int		d;
	t_point	next;
	bool	is_found;

	if (ch[cur.y][cur.x] == EXIT)
		return (item_cnt == 0);
	else if (ch[cur.y][cur.x] == ITEM)
		item_cnt--;

	is_found = false;
	d = 0;
	while (d < DIR_CNT && !is_found)
	{
		next.y = cur.y + yy[d];
		next.x = cur.x + xx[d];
		if (ch[next.y][next.x] == WALL)
			continue;
		else
			is_found = check_path(g, item_cnt - 1, next, ch);
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

int	check_format_n_init_map(t_list *lines, t_map *map)
{
	int		*pei_cnt;
	int		h;
	bool	is_mid;
	char	**ch;

	map->height = ft_lstsize(lines);
	map->width = ft_strlen(lines->content) - 1;
	map->board = (char **)malloc(sizeof(char *) * map->height);
	ch = (char **)malloc(sizeof(char *) * map->height); 
	pei_cnt = (int *)ft_calloc(3, sizeof(int));
	h = 0;
	while (lines)
	{
		is_mid = !(h == 0 || h == map->height - 1);
		if (!check_line(lines->content, map->width, is_mid, &pei_cnt))
			return (ERROR_B);
		((char *)lines->content)[map->width] = '\0';
		map->board[h] = ft_strdup((char *)lines->content);
		ch[h] = lines->content;
		h++;
		lines = lines->next;
	}
	if (!pei_cnt[0] || !pei_cnt[1] || !pei_cnt[2]
		|| pei_cnt[0] > 1 || pei_cnt[1] > 1)
		return (ERROR_B);
	
	check_path()
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

bool	map_parsing(char *file, t_map *map)
{
	int		fd;
	t_list	*line_lst;
	
	if (!check_file_type(file))
	{
		ft_printf("file type error\n");
		return (ERROR_B);
	}
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
