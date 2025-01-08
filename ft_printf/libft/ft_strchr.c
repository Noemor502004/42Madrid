/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:26:34 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/25 15:50:24 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*pointer;

	i = 0;
	while ((size_t) i <= ft_strlen(s))
	{
		if (s[i] == c % 256)
		{
			pointer = &s[i];
			return ((char *) pointer);
		}
		i++;
	}
	return (0);
}
