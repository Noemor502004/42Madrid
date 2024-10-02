/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:05:00 by yoomi             #+#    #+#             */
/*   Updated: 2024/10/02 22:22:43 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static	char	**write_string(char	const *s, char c, char **string)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			string[j][k] = s[i];
			k++;
		}
		else if (s[i + 1] != c && i != 0 && (size_t) i != ft_strlen(s) - 1)
		{
			string[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	return (string);
}

static	char	**mk_string2(char const *s, char c, char **string)
{
	int	k;
	int	i;
	int	j;

	k = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && i != 0
				&& (size_t) i != ft_strlen(s) - 1) || s[i + 1] == '\0')
		{
			string[j] = ft_calloc(i - k, 1);
			j++;
			k = i;
		}
		i++;
	}
	return (string);
}

static	char	**mk_string(char const *s, char c, char **string, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && i != 0
				&& (size_t) i != ft_strlen(s) - 1) || s[i + 1] == '\0')
		{
			j++;
		}
		i++;
	}
	string = ft_calloc(j, 1);
	return (mk_string2(s, c, string));
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	char	*string2;
	int		i;

	i = 0;
	string = 0;
	string2 = ft_strtrim(s, &c);
	string = mk_string(string2, c, string, i);
	return (write_string(string2, c, string));
}
