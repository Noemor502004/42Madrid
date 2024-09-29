/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:05:00 by yoomi             #+#    #+#             */
/*   Updated: 2024/09/29 19:33:55 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**mk_string(char const *s, char c, char **string, int i)
{
	int	j;

	j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j++;
		}
		i++;
	}
	string = ft_calloc(j, 1);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i + 1] == '\0')
		{
			string[j] = ft_calloc(i - ft_strlen(string[j - 1] + 1), 1);
			j++;
		}
		i++;
	}
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	string = 0;
	string = mk_string(s, c, string, i);
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			string[j][k] = s[i];
			k++;
		}
		else
		{
			string[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	return (string);
}
