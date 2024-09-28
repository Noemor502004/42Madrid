/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:15:14 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/28 15:04:22 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static	int	ft_atoi2(const char *nptr, size_t i, int exponent)
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
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		exponent *= 10;
		i++;
	}
	exponent /= 10;
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
