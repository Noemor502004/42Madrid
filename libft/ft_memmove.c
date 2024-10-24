/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:30:07 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/24 18:13:29 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*string;
	char	*string2;

	string = (char *) dest;
	string2 = (char *) src;
	if (dest > src && n != 0 && string2 != string)
	{
		i = n;
		while (i > 0)
		{
			i--;
			string[i] = string2[i];
		}
	}
	else if (n != 0 && string2 != string)
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
