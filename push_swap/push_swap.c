/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:55 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/10 15:30:08 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*void	push_swap(int number, ...)
{
	
}*/

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *lastA;
	t_stack *newA;
	//t_stack *b;
	int		i;

	if (argc < 2)
		_exit(0);
	a = (t_stack *)ft_calloc(1, sizeof(a));
	newA = (t_stack *)ft_calloc(1, sizeof(a));
	if (!a)
		return (free(a), -1);
	i = 1;
	while (i < argc)
	{
		check_int(argv[i]);
		check_duplicate(&a, argv[i]);
		if (i == 1)
		{
			a->num = ft_atoi(argv[i]);
			a->next = NULL;
			lastA = a;
		}
		else
		{
			newA->num = ft_atoi(argv[i]);
			newA->next = NULL;
			lastA->next = newA;
			lastA = lastA->next;
		}
		i++;
	}
	//push(&a, &b, 1);
	//push(&a, &b, 1);
	while(a)
	{
		printf("%i\n", a->num);
		a = a->next;
	}
	printf("\n");
	/*while(b)
	{
		printf("%i\n", b->num);
		b = b->next;
	}*/
}
/*
1
6
8
3
5
9
4
2
*/
