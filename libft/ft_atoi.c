/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:15:14 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/27 18:15:57 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_atoi(const char *nptr)
{
	size_t	i;
	char	firstChar;
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
	result = 0;
	if (nptr[0] == '-' || nptr[0] == '+' || nptr[0] == '0')
	{
		firstChar = nptr[0];
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result += (nptr[i] - 48) * exponent;
		i++;
		exponent /= 10;
	}
	if (firstChar == '-')
		result *= -1;
	return (result);
}
