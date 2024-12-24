/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:18:47 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/24 12:14:20 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*ret_string;
	char		*read_resul;
	static char	*rest;
	char		*temp_ret_string;
	int			bool;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (rest)
	{
		while (rest[i] != '\0' || rest[i] != '\n')
			i++;
		if (rest[i] != '\n')
			i++;
		ret_string = malloc(i * sizeof(char));
		if (!ret_string)
			return (NULL);
		i = 0;
		while (rest[i] != '\0')
		{
			ret_string[i] = rest[i];
			if (rest[i] == '\n')
			{
				i++;
				while (rest[i] == '\0')
				{
					rest[j] = rest[i];
					i++;
					j++;
				}
				rest[j] = '\0';
				return (ret_string);
			}
		}
		free(rest);
	}
	else
	{
		ret_string = malloc(11 * sizeof(char));
		if (!ret_string)
			return (NULL);
	}
	i = 0;
	bool = 0;
	while (!bool)
	{
		read_resul = malloc(11 * sizeof(char));
		if (!read_resul)
		{
			free(ret_string);
			return (NULL);
		}
		if (read(fd, read_resul, 10) == 0 && fake_strlen(read_resul) == 0)
		{
			free(ret_string);
			free(read_resul);
			return (NULL);
		}
		while (read_resul[i] != '\0')
		{
			if (read_resul[i] == '\n')
			{
				temp_ret_string = malloc(fake_strlen(ret_string) + 1);
				if (!temp_ret_string)
				{
					free(read_resul);
					free(ret_string);
					return (NULL);
				}
				fake_strlcpy(temp_ret_string, ret_string,
					fake_strlen(ret_string));
				free(ret_string);
				ret_string = malloc((i + 1 + fake_strlen(temp_ret_string))
						* sizeof(char));
				if (!ret_string)
				{
					free(temp_ret_string);
					free(read_resul);
					return (NULL);
				}
				fake_strlcpy(ret_string, temp_ret_string,
					fake_strlen(temp_ret_string) + 1);
				free(temp_ret_string);
				bool = 1;
				ret_string[fake_strlen(ret_string)] = read_resul[i];
				i++;
				rest = malloc(fake_strlen(read_resul + i) * sizeof(char));
				if (!rest)
				{
					free(ret_string);
					free(read_resul);
					free(ret_string);
					return (NULL);
				}
				while (read_resul[i] != '\0')
				{
					rest[fake_strlen(rest)] = read_resul[i];
					i++;
				}
				rest[i] = '\0';
			}
			else
				ret_string[fake_strlen(ret_string)] = read_resul[i];
			i++;
		}
		free(read_resul);
		i = 0;
	}
	return (ret_string);
}
//Hola que
//tal
//bien
//Hola que\nt
//al\nbien#EOF
