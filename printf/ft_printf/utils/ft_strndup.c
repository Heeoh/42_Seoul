/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:18:56 by heson             #+#    #+#             */
/*   Updated: 2022/11/24 17:05:39 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_utils.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t *size)
{
	char	*res;
	size_t	i;

	if (!*size)
		*size = ft_strlen(s1);
	res = (char *)malloc(*size + 1);
	if (!res)
		return (ERROR_P);
	i = 0;
	while (i < *size)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>

// int main() {
// 	char	tmp[2];
// 	size_t	len = 1;

// 	tmp[0] = 0;
// 	tmp[1] = '\0';

// 	char *res = ft_strndup(tmp, &len);
// 	printf("%s\n", res);

// }