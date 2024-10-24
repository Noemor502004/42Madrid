/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:21:00 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/24 17:13:39 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			i;

	if (start >= ft_strlen(s))
	{
		string = ft_calloc(1, sizeof(char));
		string[0] = '\0';
		return (string);
	}
	if (len > ft_strlen(s) - start)
		string = ft_calloc(ft_strlen(s) - start + 1, 1);
	else
		string = ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		string[i] = s[start];
		i++;
		start++;
	}
	string[i] = '\0';
	return (string);
}
