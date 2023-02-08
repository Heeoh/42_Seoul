/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:32:53 by heson             #+#    #+#             */
/*   Updated: 2023/02/08 14:28:35 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0
# define ERROR_P 0
# define ERROR_I -1

#include "../headers/stack.h"
#include "../library/libft/libft.h"


t_list	*parsing(int ac, char *av[]);
void	ft_quick_sort(int *nums, int s, int e);
void	a_to_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);
void	insertion_sort(t_stack *stk_a, t_stack *stk_b);




#endif