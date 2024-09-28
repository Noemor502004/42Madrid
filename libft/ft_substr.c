/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:45:40 by yoomi             #+#    #+#             */
/*   Updated: 2024/09/28 18:00:35 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			i;
	unsigned	int	j;

	string = malloc((int) len);
	i = 0;
	j = start - 1;
	while (i < len)
	{
		string[i] = s[j];
		i++;
		j++;
	}
	return (string);
}
