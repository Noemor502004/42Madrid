/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:24:27 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/18 17:24:30 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	lenght;

	i = 0;
	lenght = 0;
	while (src[i] != '\0' && i < (int)size - 1)
	{
		dst[i] = src[i];
		i++;
		lenght++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[lenght] != '\0')
		lenght++;
	return (lenght);
}
