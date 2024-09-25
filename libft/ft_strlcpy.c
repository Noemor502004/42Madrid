/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:35:20 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/21 17:36:50 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

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