/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:09:11 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 15:17:08 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = 0;
	return (b);
}
