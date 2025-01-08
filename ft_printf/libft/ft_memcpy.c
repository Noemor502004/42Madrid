/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:30:27 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/24 18:17:42 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*string;
	char		*string2;

	string = (char *) src;
	string2 = (char *) dest;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		string2[i] = string[i];
		i++;
	}
	return (dest);
}
