/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:15:14 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/08 13:26:44 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi3(int exponent, const char *nptr, int i)
{
	int	bool;

	bool = 0;
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (exponent < 1000000000)
			exponent *= 10;
		else
			bool = 1;
		i++;
	}
	if (bool == 0)
		exponent /= 10;
	return (exponent);
}

static int	ft_atoi2(const char *nptr, size_t i, int exponent)
{
	int	result;

	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result += (nptr[i] - 48) * exponent;
		i++;
		exponent /= 10;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	char	first;
	int		result;
	int		exponent;

	exponent = 1;
	i = 0;
	if (nptr[0] == '-' || nptr[0] == '+' || nptr[0] == '0')
		i++;
	exponent = ft_atoi3(exponent, nptr, i);
	i = 0;
	if (nptr[0] == '-' || nptr[0] == '+' || nptr[0] == '0')
	{
		first = nptr[0];
		i++;
	}
	result = ft_atoi2(nptr, i, exponent);
	if (first == '-')
		result *= -1;
	return (result);
}
