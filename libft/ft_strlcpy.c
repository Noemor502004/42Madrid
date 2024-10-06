/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:35:20 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/06 20:50:31 by yoomi            ###   ########.fr       */
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
