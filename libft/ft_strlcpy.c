/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:35:20 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/04 15:02:33 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		lenght;

	i = 0;
	lenght = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
		lenght++;
	}
	dst[i] = '\0';
	while (src[lenght] != '\0')
		lenght++;
	return (lenght);
}
