/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:55 by nmorgado          #+#    #+#             */
/*   Updated: 2025/02/10 17:49:22 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	push_swap(int number, ...)
{
	
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		i;

	if (argc < 2)
		_exit(0);
	a = (t_stack *)ft_calloc(1, sizeof(a));
	if (!a)
		return (free(a), -1);
	i = argc - 2;
	while (i > 0)
	{
		check_int(argv, i);
		check_duplicate(a, argv, i);
		a->num = ft_atoi(*argv[i]);
		i--;
	}
}
/*
1
6
8
3
5
9


*/