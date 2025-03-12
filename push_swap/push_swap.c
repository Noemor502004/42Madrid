/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:55 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/12 13:35:11 by nmorgado         ###   ########.fr       */
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
	t_stack	*last_a;
	t_stack	*new_a;
	t_stack	*b;
	int		i;

	if (argc < 2)
		_exit(0);
	a = (t_stack *)ft_calloc(1, sizeof(a));
	if (!a)
		return ;
	b = (t_stack *)ft_calloc(1, sizeof(b));
	if (!b)
		return (free(a), -1);
	new_a = (t_stack *)ft_calloc(1, sizeof(new_a));
	if (!new_a)
		return (free(a), free(b), -1);
	i = 1;
	while (i < argc)
	{
		check_int(argv[i]);
		check_duplicate(&a, argv[i]);
		if (i == 1)
		{
			a->num = ft_atoi(argv[i]);
			a->next = NULL;
			last_a = a;
		}
		else
		{
			new_a->num = ft_atoi(argv[i]);
			new_a->next = NULL;
			last_a->next = new_a;
			last_a = last_a->next;
			new_a = (t_stack *)ft_calloc(1, sizeof(a));
			if (!new_a)
				freeAll();
		}
		i++;
	}
	push(&a, &b, 1);
	push(&a, &b, 1);
	push(&b, &a, 0);
	push(&b, &a, 0);
	reverse_rotate(&a, 0);
	while(a)
	{
		printf("%i\n", a->num);
		a = a->next;
	}
	printf("\nb\n");
	while(b)
	{
		printf("%i\n", b->num);
		b = b->next;
	}
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
