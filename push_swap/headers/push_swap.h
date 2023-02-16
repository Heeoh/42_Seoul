/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:32:53 by heson             #+#    #+#             */
/*   Updated: 2023/02/16 02:48:39 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../headers/stack.h"
# include "../library/libft/libft.h"
# include "../library/printf/headers/ft_printf.h"

# define ERROR_P NULL
# define ERROR_I -1

typedef struct s_two_stks{
	t_stack	a;
	t_stack	b;
}	t_two_stks;

void	check_an_argv(char *av, t_list **list);
void	get_sorted_arr(int *nums, int s, int e);
void	print_state(t_two_stks stk);
void	do_free(t_list **lst, t_two_stks *stk, int **sorted);
void	print_error(void);

#endif