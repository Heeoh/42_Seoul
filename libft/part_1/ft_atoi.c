/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:08:49 by heson             #+#    #+#             */
/*   Updated: 2022/07/13 15:44:06 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	char			*p;
	int				sign;
	unsigned int	absolute_num;

	p = (char *)str;
	sign = 1;
	while (*p && *p == ' ')
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
		sign = -1;
		p++;
	}
	absolute_num = 0;
	while (*p && '0' <= *p && *p <= '9')
	{
		absolute_num = absolute_num * 10 + (*p - '0');
		p++;
	}
	return (absolute_num * sign);
}
