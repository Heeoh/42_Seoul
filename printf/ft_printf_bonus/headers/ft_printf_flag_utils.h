/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:17:15 by heson             #+#    #+#             */
/*   Updated: 2022/12/12 18:58:23 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLAG_UTILS_H
# define FT_PRINTF_FLAG_UTILS_H

# include "ft_printf.h"
# include <stdarg.h>

char	*apply_hash_flag(char *str, t_va_argu argu, size_t	*len);
char	*apply_plus_flag(char *str, t_va_argu argu, size_t *len);
char	*apply_space_flag(char *str, t_va_argu argu, size_t *len);
char	*apply_minus_flag(char *str, size_t *len);
char	*apply_zero_flag(t_data	*printed, t_va_argu argu, t_data *data);
char	*apply_precision_flag(char *str, t_va_argu argu, t_data *data);

#endif