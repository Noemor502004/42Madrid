/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:26:57 by nmorgado          #+#    #+#             */
/*   Updated: 2024/10/21 18:30:37 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_split(char **result)
{
	int	i;

	i = -1;
	while (result[i])
	{
		free(result[i++]);
	}
	free(result);
}

static	int	make_string(const char *s, char c, char **result)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i])
			{
				free_split(result);
				return (-1);
			}
			i++;
		}
		else
			s++;
	}
	return (i);
}

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char		**result;
	int			i;
	int			wc;

	wc = ft_count_words(s, c);
	result = malloc((wc + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = make_string(s, c, result);
	if (i == -1)
		return (NULL);
	result[i] = NULL;
	return (result);
}
