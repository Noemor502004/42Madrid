/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:21:24 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/18 17:21:29 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	startcut(char const *s1, char const *set)
{
	int	bolstart;
	int	tempcount;
	int	i;

	i = 0;
	bolstart = 1;
	while (bolstart != 0)
	{
		bolstart = 0;
		tempcount = 0;
		while (set[tempcount] != '\0')
		{
			if (set[tempcount] == s1[i])
				bolstart = 1;
			tempcount++;
		}
		if (bolstart == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	endcut(char const *s1, char const *set)
{
	int	bolend;
	int	tempcount;
	int	j;

	j = ft_strlen(s1) - 1;
	bolend = 1;
	while (bolend != 0)
	{
		bolend = 0;
		tempcount = 0;
		while (set[tempcount] != '\0')
		{
			if (set[tempcount] == s1[j])
				bolend = 1;
			tempcount++;
		}
		if (bolend == 0)
			return (j);
		j--;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*string;

	start = startcut(s1, set);
	end = endcut(s1, set);
	string = ft_calloc(end - start + 2, 1);
	ft_strlcpy(string, s1 + start, end - start + 2);
	string[ft_strlen(string)] = '\0';
	return (string);
}
