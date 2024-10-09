/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:05:00 by yoomi             #+#    #+#             */
/*   Updated: 2024/10/09 11:07:57 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			string[j] = ft_calloc(k + 1, sizeof(char));
			string[j][ft_strlen(string[j])] = '\0';
			j++;
			k = 0;
		}
		i++;
		if (s[i] != c)
			k++;
		string[j] = "\0";
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
	j++;
	string = ft_calloc(j, sizeof(char *));
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
