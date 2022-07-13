/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:19:54 by heson             #+#    #+#             */
/*   Updated: 2022/07/07 13:19:59 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hello\0world";
    char str2[] = "hello\0sorld";

    printf("res: %d, ", strncmp(str1, str2, 20));
    printf("ft: %d\n", ft_strncmp(str1, str2, 20));
    printf("res: %d, ", strncmp(str1, str2, 5));
    printf("ft: %d\n", ft_strncmp(str1, str2, 5));
}
