/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:53:30 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/27 17:59:27 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_int(char *argv[], int i)
{
	int	j;

	if (ft_strlen(*argv[i]) > 10
		|| (ft_strlen(*argv[i]) == 10 && *argv[9] > 55))
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
