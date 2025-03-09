/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:04:51 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/09 13:24:14 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int b)
{
	t_stack	*last;
	t_stack	*original_stack;

	original_stack = *stack;
	if (!b)
		write(1, "ra\n", 3);
	else if (b == 1)
		write(1, "rb\n", 3);
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	original_stack->next = NULL;
}

void	rrotate(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate(a, 2);
	rotate(b, 2);
}
