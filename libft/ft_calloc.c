/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:51:02 by yoomi             #+#    #+#             */
/*   Updated: 2024/09/29 19:27:01 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
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