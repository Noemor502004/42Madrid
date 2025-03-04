/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:05:02 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/04 16:29:12 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_last(char *str_int, unsigned int integer, int cap_bool)
{
	if (integer >= 10)
	{
		if (cap_bool)
			integer += 55;
		else
			integer += 87;
		str_int[ft_strlen(str_int)] = integer;
	}
	else
	{
		integer += '0';
		str_int[ft_strlen(str_int)] = integer;
	}
}

int	make_string(char *str_int, unsigned long int integer, int cap_bool)
{
	int	i;
	int	rest;

	i = -1;
	while (integer >= 16)
	{
		rest = integer % 16;
		integer /= 16;
		if (rest >= 10)
		{
			if (cap_bool)
				rest += 55;
			else
				rest += 87;
			str_int[++i] = rest;
		}
		else
		{
			rest += '0';
			str_int[++i] = rest;
		}
	}
	return (integer);
}

char	*ft_make_hex(unsigned long int integer, int cap_bool)
{
	char	*str_int;

	str_int = ft_calloc(17, sizeof(char));
	if (!str_int)
		return (0);
	integer = make_string(str_int, integer, cap_bool);
	make_last(str_int, integer, cap_bool);
	str_int = ft_str_reverse(str_int);
	return (str_int);
}
