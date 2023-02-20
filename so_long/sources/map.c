/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:00:31 by heson             #+#    #+#             */
/*   Updated: 2023/02/20 21:51:44 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/type.h"
#include "../headers/get_next_line.h"
#include "../library/libft/libft.h"
#include <stdbool.h>




// void	print_map_error()
// {
// 	ft_printf("Error\n");
	
// }
bool	check_point(char ch, bool is_mid)
{
	if (!is_mid)
		return (ch == WALL);
	if (ch == WALL || ch == EMPTY)
		return (true);
	if (ch == PLAYER || ch == EXIT || ch == COLLECTIBLE)
		return (true);
	return (false);
}

bool	check_line(char *line, int width, bool is_mid)
{
	bool	is_right;
	int		i;

	is_right = true;
	i = -1;
	while (++i < width && is_right)
		is_right = check_point(line[i]);
	if (!is_right)
		return (false);
	if (line[width] != '\0')
		return (false);
	if (!(line[0] == WALL && line[width - 1] == WALL))
		return (false);
	return (true);
}

t_list	*read_map(int fd)
{
	t_list	*line_lst;
	t_list	*new;
	char	*line;

	if (fd <= 2)
		return (NULL);
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

int	map_parsing(int ac, char *av[], t_game *game)
{
	t_list	*line_lst;
	t_list	*lst_p;
	t_map	map;
	int		h;

	if (ac != 1)
		return (-1);
	line_lst = read_map(open(av[1], O_RDONLY));
	if (!line_lst)
		return (-1);
	map.hegiht = ft_lstsize(line_lst);
	map.width = ft_strlen(line_lst->content);
	map.map = (char **)malloc(sizeof(char *) * height);
	lst_p = line_lst;
	while (lst_p)
	{
		if (check_line(map.width))
	}
	
	width = ft_strlen(line);
	while (line) {
		
	}
}