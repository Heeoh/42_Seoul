/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:53:48 by heson             #+#    #+#             */
/*   Updated: 2023/01/29 20:52:48 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/stack.h"
#include "header/operations.h"
#include "header/push_swap.h"

#include <stdio.h>

int main()
{
    t_stack stk_a;
    t_stack stk_b;

    int input[10] = {24, 8, 42, 75, 29, 77, 38, 57, 30, 19};
    init_stack(&stk_a, 10);
    init_stack(&stk_b, 10);
    
    for (int i=0; i<10; i++)
        push_top(&stk_a, input[i]);

    do_operation(RRA, &stk_a, &stk_b);

    printf("\n========stack A========\n");
    while (!isEmpty(stk_a)) {
        printf("%d\n", get_top(stk_a)); pop_top(&stk_a);
    }

    printf("\n========stack B========\n");
    while (!isEmpty(stk_b)) {
        printf("%d\n", get_top(stk_b)); pop_top(&stk_b);
    }

}