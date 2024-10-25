/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:30:49 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/25 16:22:52 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	size_t				i;

	i = 0;
	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (string1[i] > string2[i])
			return (1);
		if (string2[i] > string1[i])
			return (-1);
		i++;
	}
	return (0);
}
