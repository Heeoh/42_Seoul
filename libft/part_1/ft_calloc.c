/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:09:23 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 15:18:30 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*res;
	unsigned int	arr_size;
	char			*p;

	arr_size = count * size;
	res = (char *)malloc(arr_size);
	if (!res)
	{
		free(res);
		return (NULL);
	}
	p = res;
	while (arr_size--)
		*p++ = 0;
	return (res);
}
