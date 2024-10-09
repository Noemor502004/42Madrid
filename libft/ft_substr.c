/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:45:40 by yoomi             #+#    #+#             */
/*   Updated: 2024/10/09 09:05:07 by nmorgado         ###   ########.fr       */
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
