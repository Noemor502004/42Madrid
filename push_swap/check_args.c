/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:53:30 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/28 16:47:22 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_int(char *argv[], int i)
{
	int	j;
	int	numb;

	numb = ft_atoi(*argv[i]);
	if (numb > 2147483647 || numb < -2147483648)
	{
		write(1, "Error\n", 6);
		_exit(-1);
	}
	j = 0;
	while (argv[i][j] != '\0')
	{
		if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
		{
			write(1, "Error\n", 6);
			_exit(-1);
		}
	}
}

void	check_duplicate(int *array, char *argv[], int i)
{
	int	j;

	j = 0;
	while (j < i - 1)
	{
		if (array[j] == ft_atoi(*argv[i]))
		{
			write(1, "Error\n", 6);
			_exit(-1);
		}
		j++;
	}
}
