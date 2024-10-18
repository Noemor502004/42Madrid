/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:21:00 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/18 17:21:03 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			i;
	unsigned int	j;

	string = malloc((int) len + 1);
	i = 0;
	j = (int) start;
	while (i < len)
	{
		string[i] = s[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
