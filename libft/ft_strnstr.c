/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:54:24 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/26 18:27:10 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*pointer;

	j = 0;
	i = 0;
	if (ft_strlen(little) == 0)
	{
		pointer = (char *) big;
		return (pointer);
	}
	
	j = 0;
	i = 0;
	while (i < len)
	{
		if (big[i] == little[j])
		{
			pointer = (char *) &big[i];
			while (big[i] == little[j] && j < ft_strlen(little) && i < len)
			{
				i++;
				j++;
			}
			if (j == ft_strlen(little))
				return (pointer);
			else
			{
				j = 0;
				pointer = 0;
			}
		}
		i++;
	}
	return (0);
}
