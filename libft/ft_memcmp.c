/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:30:49 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/22 17:55:13 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	size_t		i;

	i = 0;
	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (string1[i] > string2[i]) // || string2[i] == '\0')
			return (1);
		if (string2[i] > string1[i]) // || string1[i] == '\0')
			return (-1);
		i++;
	}
	return (0);
}
