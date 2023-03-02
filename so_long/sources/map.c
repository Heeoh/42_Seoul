/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:00:31 by heson             #+#    #+#             */
/*   Updated: 2023/03/02 19:03:41 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/so_long_map.h"
#include "../headers/get_next_line.h"
#include <fcntl.h>

void	free_arr2(char **arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
		free(&(*arr)[i++]);
	free(*arr);
}

bool	read_map(int fd, t_list **line_lst)
{
	t_list	*new;
	char	*line;

	if (fd <= 2)
		print_error_n_exit("file open error");
	*line_lst = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = ft_lstnew(line);
		ft_lstadd_back(line_lst, new);
	}
	close(fd);
	if (!*line_lst)
		return (ERROR_B);
	return (true);
}

void	init_map(char *file, t_map *map, t_point *player)
{
	t_list	*line_lst;
	t_list	*lst_p;
	int		*pec_info;
	char	**ch;
	int		h;

	if (!check_file_type(file))
		print_error_n_exit("wrong filename or directory");
	if (!read_map(open(file, O_RDONLY), &line_lst))
		print_error_n_exit("file read error");
	map->height = ft_lstsize(line_lst);
	map->width = ft_strlen(line_lst->content) - 1;
	if (!check_map_format(line_lst, map->height, map->width, &pec_info))
		print_error_n_exit("invalid map format");
	map->board = (char **)malloc(sizeof(char *) * map->height);
	ch = (char **)malloc(sizeof(char *) * map->height);
	lst_p = line_lst;
	h = -1;
	while (++h < map->height && lst_p)
	{
		map->board[h] = ft_strdup((char *)lst_p->content);
		(ch)[h] = ft_strdup((char *)lst_p->content);
		lst_p = lst_p->next;
	}
	player->r = pec_info[3];
	player->c = pec_info[4];
	if (!check_path(ch, *player, pec_info[2]))
		print_error_n_exit("no path available");
	free(pec_info);
	free_arr2(ch);
	ft_lstclear(&line_lst, free);
}
