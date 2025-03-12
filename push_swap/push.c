/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:19:43 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/12 13:17:08 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b, int c)
{
	t_stack	*temp;

	if (!c)
		write(1, "pa\n", 3);
	else if (c == 1)
		write(1, "pb\n", 3);
	if (c == 0 && !(*a))
		return ;
	else if (c == 1 && !(*b))
		return ;
	if (c == 0)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
	}
	else if (c == 1)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
	}
}
