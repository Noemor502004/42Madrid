/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:51:02 by yoomi             #+#    #+#             */
/*   Updated: 2024/10/04 15:01:41 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = malloc(nmemb * size);
	while (i < nmemb * size)
	{
		pointer[i] = 0;
		i++;
	}
	return (pointer);
}
