/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:32:53 by heson             #+#    #+#             */
/*   Updated: 2023/02/15 02:17:02 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_P NULL
# define ERROR_I -1

# include "../headers/stack.h"
# include "../library/libft/libft.h"
# include "../library/printf/headers/ft_printf.h"

void	check_an_argv(char *av, t_list **list);
void	get_sorted_arr(int *nums, int s, int e);
void	print_state(t_stack stk_a, t_stack stk_b);
void	do_free(t_list **lst, t_stack *stk_a, t_stack *stk_b, int **sorted);
void	sort_less_5nums(t_stack *stk_a, t_stack *stk_b, int *sorted);
void	a_to_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);
void	b_to_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);
void	partition_a(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);
void	partition_b(t_stack *stk_a, t_stack *stk_b, int s, int e, int *sorted);

#endif