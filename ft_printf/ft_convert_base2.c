/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:12:20 by heson             #+#    #+#             */
/*   Updated: 2022/07/14 18:38:05 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strlen_base(int num, int base_n)
{
	int	cnt;

	cnt = 0;
	if (num <= 0)
	{
		cnt++;
		num = -num;
	}
	while (num > 0)
	{
		num /= base_n;
		cnt++;
	}
	return (cnt);
}

char	*itoa_base(int num, char *base, int base_n)
{
	int		res_len;
	char	*res;
	char	*p;

	res_len = strlen_base(num, base_n);
	res = (char *)malloc(res_len + 1);
	if (!res)
		return (0);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	p = &res[res_len];
	*p-- = '\0';
	if (num == 0)
		*p = base[0];
	while (num > 0)
	{
		*p = base[num % base_n];
		num /= base_n;
		p--;
	}
	return (res);
}
