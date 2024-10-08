/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:48:16 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/08 13:03:07 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		lenght;
	int		n;

	if (size == 0)
		n = 0;
	else
		n = size;
	j = 0;
	i = ft_strlen(dst);
	if (n > (int)ft_strlen(dst))
		lenght = ft_strlen(dst) + ft_strlen(src);
	else
		lenght = n + ft_strlen(src);
	while (i < n - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < n)
		dst[i] = '\0';
	return (lenght);
}
