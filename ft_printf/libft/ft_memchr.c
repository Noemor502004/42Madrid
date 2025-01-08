/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:31:07 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/18 17:31:10 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*string;

	i = 0;
	a = (unsigned char) c;
	string = (unsigned char *) s;
	while (i < n)
	{
		if (string[i] == a)
		{
			return (&string[i]);
		}
		i++;
	}
	return (0);
}
