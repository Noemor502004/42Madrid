/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:53:55 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/27 17:59:17 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	push_swap(int number, ...)
{
	
}

int	main(int argc, char *argv[])
{
	int	*array;
	int	i;
	int	j;

	j = 0;
	i = 1;
	array = (int *)ft_calloc(1, sizeof(int));
	if (argc < 2)
		_exit(0);
	while (*argv[i] != '\0')
	{
		check_int(argv, i);
		check_duplicate(array, argv, i);
		array[j - 1] = ft_atoi(*argv[i]);
		i++;
	}
}
