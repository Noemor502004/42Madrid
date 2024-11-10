/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:22:14 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/25 16:22:17 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_2(char *point, const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		k = i;
		if (big[k] == lit[j])
		{
			point = (char *) &big[i];
			while (big[k] == lit[j] && j < ft_strlen(lit) && k < len)
			{
				k++;
				j++;
			}
			if (j == ft_strlen(lit))
				return (point);
			else
				point = 0;
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pointer;

	if (ft_strlen(little) == 0)
	{
		pointer = (char *) big;
		return (pointer);
	}
	else
		pointer = 0;
	return (ft_2(pointer, big, little, len));
}
