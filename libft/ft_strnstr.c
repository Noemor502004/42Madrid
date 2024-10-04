/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:54:24 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/04 15:02:44 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr2(char *point, const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		if (big[i] == lit[j])
		{
			point = (char *) &big[i];
			while (big[i] == lit[j] && j < ft_strlen(lit) && i < len)
			{
				i++;
				j++;
			}
			if (j == ft_strlen(lit))
				return (point);
			else
			{
				point = 0;
			}
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
	return (ft_strnstr2(pointer, big, little, len));
}
