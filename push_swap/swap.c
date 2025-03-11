/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:09:17 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/10 14:49:27 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int b)
{
	t_stack	*temp;

	if (!b)
		write(1, "sa\n", 3);
	else if (b == 1)
		write(1, "sb\n", 3);
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sswap(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(a, 2);
	swap(b, 2);
}
