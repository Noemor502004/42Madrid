/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:28:07 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/18 17:28:15 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mk_result_fake(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
	}
}

static void	write_result_fake(int temp, int fd, int n, int exponent)
{
	int		i;
	int		j;
	char	c;

	j = 1;
	i = 0;
	if (n < 0)
		j = -1;
	while (i <= temp)
	{
		if (i == temp)
			c = n * j + '0';
		else
		{
			c = n / exponent * j + 48;
			n %= exponent;
			exponent /= 10;
		}
		write(fd, &c, 1);
		i++;
	}
}

static void	ft_itoa_fake(int n, int fd)
{
	int		i;
	int		temp;
	int		exponent;

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
	while (temp < i - 1)
	{
		exponent *= 10;
		temp++;
	}
	mk_result_fake(n, fd);
	write_result_fake(temp, fd, n, exponent);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_itoa_fake(n, fd);
}
