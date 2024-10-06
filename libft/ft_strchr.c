/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:34:30 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/06 18:50:48 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*pointer;

	i = 0;
	while ((size_t) i <= ft_strlen(s))
	{
		if (s[i] == c)
		{
			pointer = &s[i];
			return ((char *) pointer);
		}
		i++;
	}
	return (0);
}
