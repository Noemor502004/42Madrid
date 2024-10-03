/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:41:35 by yoomi             #+#    #+#             */
/*   Updated: 2024/10/03 16:52:52 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mk_result(int *n, int *i, char *result, int *temp)
{
	if (*n < 0)
	{
		*i += 1;
		result = ft_calloc(*i + 1, 1);
		result[0] = '-';
		*n *= -1;
		*i = 1;
		*temp += 1;
	}
	else
	{
		result = ft_calloc(*i + 1, 1);
		*i = 0;
	}
	return (result);
}

static int	write_result(int temp, char *result, int n, int exponent)
{
	int	i;

	if (result[0] == '-')
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	while (i <= temp)
	{
		result[i] = n / exponent + 48;
		n %= exponent;
		exponent /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		temp;
	char	*result;
	int		exponent;

	i = 0;
	temp = n;
	if (temp < 0)
		temp *= -1;
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	exponent = 1;
	result = 0;
	while (temp < i - 1)
	{
		exponent *= 10;
		temp++;
	}
	result = mk_result(&n, &i, result, &temp);
	i = write_result(temp, result, n, exponent);
	result[i] = '\0';
	return (result);
}
