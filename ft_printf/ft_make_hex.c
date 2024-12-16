/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:05:02 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/16 10:51:44 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_last(char *str_int, unsigned long integer, int cap_bool,
char *string2)
{
	if (integer != 0)
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
			string2 = ft_itoa(integer);
			str_int[ft_strlen(str_int)] = *string2;
			free (string2);
		}
	}
}

int	make_string(char *str_int, unsigned long integer, int cap_bool,
char *string2)
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
			string2 = ft_itoa(rest);
			str_int[++i] = *string2;
			free (string2);
		}
	}
	return (integer);
}

char	*ft_make_hex(unsigned long integer, int cap_bool)
{
	char	*string2;
	char	*str_int;

	str_int = ft_calloc(17, sizeof(char));
	string2 = 0;
	if (!str_int)
		return (0);
	integer = make_string(str_int, integer, cap_bool, string2);
	make_last(str_int, integer, cap_bool, string2);
	str_int = ft_str_reverse(str_int);
	return (str_int);
}
