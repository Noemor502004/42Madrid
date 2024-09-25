/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:21:52 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/21 18:40:37 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*string;
	char	*string2;

	string = (char *) dest;
	string2 = (char *) src;
	if (ft_strlen(dest) <= ft_strlen(src))
	{
		i = n;
		while (i > 0)
		{
			i--;
			string[i] = string2[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			string[i] = string2[i];
			i++;
		}
	}
	return (dest);
}
