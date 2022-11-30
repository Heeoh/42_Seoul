/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:17:15 by heson             #+#    #+#             */
/*   Updated: 2022/11/30 15:00:13 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLAG_UTILS_H
# define FT_PRINTF_FLAG_UTILS_H

# include "ft_printf.h"
# include <stdarg.h> // va_start, va_arg, va_copy, va_end

char	*apply_base_flag(char *str, t_va_argu argu, size_t	*len);
char	*apply_sign_flag(char *str, t_va_argu argu, size_t *len);
char	*apply_space_flag(char *str, t_va_argu argu, size_t *len);

#endif