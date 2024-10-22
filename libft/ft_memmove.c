/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:30:07 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/22 17:31:28 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*string;
	char	*string2;

	string = (char *) dest;
	string2 = (char *) src;
	if (ft_strlen(dest) <= ft_strlen(src))
	{
		i = n;
		while (i > 0)
		{
			i--;
			string[i] = string2[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			string[i] = string2[i];
			i++;
		}
	}
	return (dest);
}
