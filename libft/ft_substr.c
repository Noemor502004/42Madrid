/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:21:00 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/22 20:38:38 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			i;
	unsigned int	j;

	if (start >= ft_strlen(s))
	{
		string = malloc(1);
		string[0] = '\0';
		return (string);
	}
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && s[start + i] != '\0')
	{
		string[i] = s[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
