/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:40:13 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/04 15:02:09 by nmorgado         ###   ########.fr       */
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
	while (i < n)
	{
		string2[i] = string[i];
		i++;
	}
	return (dest);
}
