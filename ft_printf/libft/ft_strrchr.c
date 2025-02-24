/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:21:54 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/25 15:51:05 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*pointer;

	i = 0;
	pointer = 0;
	while ((size_t) i <= ft_strlen(s))
	{
		if (s[i] == c % 256)
		{
			pointer = (char *)&s[i];
		}
		i++;
	}
	return ((char *) pointer);
}
