/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:53:30 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/12 13:35:50 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char *argv)
{
	size_t		j;

	j = 0;
	while (j < ft_strlen(argv))
	{
		if (argv[j] < '0' || argv[j] > '9')
		{
			write(1, "Error\n", 7);
			_exit(-1);
		}
		j++;
	}
	if (ft_atoi(argv) < INT_MIN || ft_atoi(argv) > INT_MAX)
	{
		write(1, "Error\n", 7);
		_exit(-1);
	}
}

void	check_duplicate(t_stack **a, char *argv)
{
	t_stack	*stack;

	stack = *a;
	while (stack)
	{
		if (stack->num == ft_atoi(argv))
		{
			write(1, "Error\n", 7);
			_exit(-1);
		}
		stack = stack->next;
	}
}

int	check_order(t_stack *a)
{
	t_stack	*temp_a;

	temp_a = a;
	while (temp_a != NULL)
	{
		if (temp_a->num > temp_a->next->num)
			return (0);
		else
			temp_a = temp_a->next;
	}
	return (1);
}
