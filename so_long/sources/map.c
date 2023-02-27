/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:00:31 by heson             #+#    #+#             */
/*   Updated: 2023/02/28 02:27:09 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/so_long_map.h"
#include "../headers/get_next_line.h"
#include <fcntl.h>

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

void	init_map(char *file, t_map *map, char ***ch)
{
	t_list	*line_lst;
	t_list	*lst_p;
	int		h;

	if (!check_file_type(file))
		print_error_n_exit("wrong filename or directory");
	if (!read_map(open(file, O_RDONLY), &line_lst))
		print_error_n_exit("file read error");
	map->height = ft_lstsize(line_lst);
	map->width = ft_strlen(line_lst->content) - 1;
	if (!check_map_format(line_lst, map->height, map->width))
		print_error_n_exit("invalid map format");
	map->board = (char **)malloc(sizeof(char *) * map->height);
	*ch = (char **)malloc(sizeof(char *) * map->height);
	lst_p = line_lst;
	h = -1;
	while (++h < map->height && lst_p)
	{
		map->board[h] = ft_strdup((char *)lst_p->content);
		(*ch)[h] = ft_strdup((char *)lst_p->content);
		lst_p = lst_p->next;
	}
	ft_lstclear(&line_lst, free);
}
