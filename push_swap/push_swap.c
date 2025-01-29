/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:55 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/28 16:56:27 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	push_swap(int number, ...)
{
	
}

int	main(int argc, char *argv[])
{
	int	*a;
	int	i;
	int	j;

	j = 0;
	i = 1;
	a = (int *)ft_calloc(ft_strlen(argv), sizeof(int));
	if (argc < 2)
		_exit(0);
	while (*argv[i] != '\0')
	{
		check_int(argv, i);
		check_duplicate(a, argv, i);
		a[j - 1] = ft_atoi(*argv[i]);
		i++;
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