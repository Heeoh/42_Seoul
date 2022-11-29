/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:19:31 by heson             #+#    #+#             */
/*   Updated: 2022/11/29 13:51:52 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stddef.h>

# define ERROR_P NULL
# define ERROR_I -1
# define TRUE 1
# define FALSE 0

size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, size_t *size);
char	*ft_strjoin(char const *s1, char const *s2, size_t len);
char	*ft_ulltoa(unsigned long long n);
char	*ft_uitoa(unsigned long n);
char	*ft_itoa(long n);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	ft_str_toupper(char *str, size_t len);

#endif