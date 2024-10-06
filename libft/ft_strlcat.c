/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:48:16 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/06 18:53:22 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		lenght;

	if (dst == 0 || size == 0)
		return (0);
	j = 0;
	i = ft_strlen(dst);
	lenght = ft_strlen(dst) + ft_strlen(src) - 1;
	while (i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lenght);
}
