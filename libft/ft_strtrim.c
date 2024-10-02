/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:40:35 by yoomi             #+#    #+#             */
/*   Updated: 2024/10/02 12:38:12 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char    *ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		bolStart;
	int		bolEnd;
	int		tempCount;
	int		start;
	int		end;
	char	*string;

	bolStart = 1;
	bolEnd = 1;
	i = 0;
	j = ft_strlen(s1) - 1;
	while(bolStart != 0)
	{
		bolStart = 0;
		tempCount = 0;
		while(set[tempCount] != '\0')
		{
			if (set[tempCount] == s1[i])
				bolStart = 1;
			tempCount++;
		}
		if (bolStart == 0)
			start = i;
		i++;
	}
	while(bolEnd != 0)
	{
		bolEnd = 0;
		tempCount = 0;
		while(set[tempCount] != '\0')
		{
			if (set[tempCount] == s1[j])
				bolEnd = 1;
			tempCount++;
		}
		if (bolEnd == 0)
			end = j;
		j--;
	}
	string = ft_calloc(end - start + 2, 1);
	ft_strlcpy(string, s1 + start, end + 2);
	string[ft_strlen(string)] = '\0';
	return (string);
}
