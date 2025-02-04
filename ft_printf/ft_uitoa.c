/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:31:28 by nmorgado          #+#    #+#             */
/*   Updated: 2025/02/03 18:44:19 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*mk_result(int *i, char *result)
{
	result = ft_calloc(*i + 1, 1);
	if (!result)
		return (NULL);
	*i = 0;
	return (result);
}

static int	write_result(unsigned int temp, char *result, int n,
	unsigned int exponent)
{
	unsigned int	i;
	int	j;

	j = 1;
	i = 0;
	while (i <= temp)
	{
		if (i == temp)
			result[i] = n * j + '0';
		else
		{
			result[i] = n / exponent * j + 48;
			n %= exponent;
			exponent /= 10;
		}
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	int				i;
	unsigned int	temp;
	char			*result;
	unsigned int	exponent;

	i = 0;
	temp = n;
	if (n == 0)
		i++;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	exponent = 1;
	result = 0;
	while (temp < (unsigned int)i - 1)
	{
		exponent *= 10;
		temp++;
	}
	result = mk_result(&i, result);
	if (result)
		i = write_result(temp, result, n, exponent);
	return (result);
}
