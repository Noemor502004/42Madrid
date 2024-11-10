/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:31:28 by nmorgado          #+#    #+#             */
/*   Updated: 2024/11/10 18:32:07 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mk_result(int *i, char *result)
{
	result = ft_calloc(*i + 1, 1);
	if (!result)
		return (NULL);
	*i = 0;
	return (result);
}

static int	write_result(int temp, char *result, int n, int exponent)
{
	int	i;
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

char	*ft_ltoa(unsigned long n)
{
	int				i;
	unsigned long	temp;
	char			*result;
	unsigned long	exponent;

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
