/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:53:30 by nmorgado          #+#    #+#             */
/*   Updated: 2025/02/10 16:49:21 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char *argv)
{
	int		j;

	j = 0;
	while (j < ft_strlen(argv))
	{
		if (argv[j] < '0' || argv[j] > '9')
		{
			write(1, "Error\n", 6);
			_exit(-1);
		}
		j++;
	}
}

void	check_duplicate(t_stack *a, char *argv)
{
	int	j;

	j = 0;
	while (a)
	{
		if (a->num == ft_atoi(argv))
		{
			write(1, "Error\n", 6);
			_exit(-1);
		}
		a = a->next;
	}
}
