/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:00:31 by heson             #+#    #+#             */
/*   Updated: 2023/02/20 19:33:32 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

// void	print_map_error()
// {
// 	ft_printf("Error\n");
	
// }

int	map_parsing(int ac, char *av[])
{
	int		fd;
	char	*line;

	if (ac != 1)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd <= 2)
		return (-1);
	line = get_next_line(fd);
	while (line) {
		
	}
}