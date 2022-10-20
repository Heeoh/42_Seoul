/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:59:50 by heson             #+#    #+#             */
/*   Updated: 2022/10/20 15:32:45 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc, free

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

char	*ft_strndup(const char *s1, size_t *size)
{
	char	*res;
	size_t	i;

	if (!size || !*size)
		*size = ft_strlen(s1);
	res = (char *)malloc(*size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (((char *)s1)[i] && i < *size)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}


// itoa
int	get_num_len(unsigned long long num)
{
	int	cnt;

	cnt = 0;
	if (num <= 0)
		cnt++;
	while (num != 0)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

unsigned long	ft_abs(unsigned long long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(unsigned long long n)
{
	size_t	res_len;
	char	*res;
	char	*p;

	res_len = get_num_len(n);
	res = (char *)malloc(res_len + 1);
	if (!res)
		return (NULL);
	p = res + res_len;
	*p-- = '\0';
	if (n == 0)
		*p = '0';
	else if (n < 0)
		*res = '-';
	while (n != 0)
	{
		*p-- = n % 10 + '0';
		n /= 10;
	}
	return (res);
}