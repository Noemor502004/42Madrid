/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:35:07 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/05 13:22:24 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	fake_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

size_t	fake_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lenght;

	i = 0;
	lenght = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
			lenght++;
		}
		dst[i] = '\0';
	}
	while (src[lenght] != '\0')
		lenght++;
	return (lenght);
}

void	*fake_calloc(size_t nmemb, size_t size)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	while (i < nmemb * size)
	{
		pointer[i] = 0;
		i++;
	}
	return (pointer);
}

int	resize_ret_string(char **temp_ret_string, char **ret_string,
char **read_resul, int i)
{
	*temp_ret_string = fake_calloc(fake_strlen(*ret_string) + 1,
			sizeof(char));
	if (!(*temp_ret_string))
	{
		free(*read_resul);
		free(*ret_string);
		return (-1);
	}
	fake_strlcpy(*temp_ret_string, *ret_string,
		fake_strlen(*ret_string) + 1);
	free(*ret_string);
	*ret_string = fake_calloc((i + 1 + fake_strlen(*temp_ret_string)),
			sizeof(char));
	if (!(*ret_string))
	{
		free(*temp_ret_string);
		free(*read_resul);
		return (-1);
	}
	fake_strlcpy(*ret_string, *temp_ret_string,
		fake_strlen(*temp_ret_string) + 1);
	free(*temp_ret_string);
	free(*read_resul);
	return (0);
}
