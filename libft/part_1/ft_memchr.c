/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:10:01 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 15:26:01 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	char	*p;

	p = (char *)s;
	while (p - (char *)s < n)
	{
		if (*p == c)
			return (p);
		if (!*p)
			return (0);
		p++;
	}
	return (0);
}
