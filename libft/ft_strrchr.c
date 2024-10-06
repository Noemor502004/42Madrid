/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:05:03 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/06 19:11:41 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*pointer;

	i = 0;
	pointer = 0;
	while ((size_t) i <= ft_strlen(s))
	{
		if (s[i] == c)
		{
			pointer = (char *)&s[i];
		}
		i++;
	}
	return ((char *) pointer);
}
