/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:05:10 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/09 13:31:31 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack, int b)
{
	t_stack	*last;
	t_stack	*last_minus_one;

	if (!b)
		write(1, "rra\n", 3);
	else if (b == 1)
		write(1, "rrb\n", 3);
	last = *stack;
	while (last->next != NULL)
	{
		last_minus_one = last;
		last = last->next;
	}
	last_minus_one->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrrotate(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	reverse_rotate(a, 2);
	reverse_rotate(b, 2);
}
