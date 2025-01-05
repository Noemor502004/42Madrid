/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:18:47 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/05 12:30:27 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	whileread_resul(char *read_resul, int *i, char *ret_string, char **rest)
{
	int	bool;

	bool = 0;
	if (read_resul[*i] == '\n')
	{
		bool = 1;
		ret_string[fake_strlen(ret_string)] = read_resul[*i];
		*rest = fake_calloc(fake_strlen(read_resul + ++(*i)) + 1,
				sizeof(char));
		if (!(*rest))
		{
			free(ret_string);
			free(read_resul);
			free(ret_string);
			return (-1);
		}
		while (read_resul[*i] != '\0')
			(*rest)[fake_strlen(*rest)] = read_resul[(*i)++];
		(*rest)[fake_strlen(*rest)] = '\0';
	}
	else
		ret_string[fake_strlen(ret_string)] = read_resul[*i];
	(*i)++;
	return (bool);
}

char	*whilebool(char **read_resul, char **ret_string, int fd, char **rest)
{
	int		bool;
	int		temp_bool;
	int		i;
	char	*temp_ret_string;

	i = 0;
	bool = 0;
	while (!bool)
	{
		*read_resul = fake_calloc(11, sizeof(char));
		if (!(*read_resul))
		{
			free(*ret_string);
			return (NULL);
		}
		if (read(fd, *read_resul, 10) == 0 && fake_strlen(*read_resul) == 0)
		{
			if (*ret_string && fake_strlen(*ret_string) == 0)
				free(*ret_string);
			else if (!ret_string)
				free(*ret_string);
			else
				return (*ret_string);
			return (NULL);
		}
		while ((*read_resul)[i] != '\0')
		{
			temp_bool = whileread_resul(*read_resul, &i, *ret_string, rest);
			if (temp_bool == -1)
				return (NULL);
			else if (temp_bool > bool)
				bool = temp_bool;
		}
		temp_ret_string = fake_calloc(fake_strlen(*ret_string) + 1,
				sizeof(char));
		if (!temp_ret_string)
		{
			free(*read_resul);
			free(*ret_string);
			return (NULL);
		}
		fake_strlcpy(temp_ret_string, *ret_string,
			fake_strlen(*ret_string) + 1);
		free(*ret_string);
		*ret_string = fake_calloc((i + 1 + fake_strlen(temp_ret_string)),
				sizeof(char));
		if (!(*ret_string))
		{
			free(temp_ret_string);
			free(*read_resul);
			return (NULL);
		}
		fake_strlcpy(*ret_string, temp_ret_string,
			fake_strlen(temp_ret_string) + 1);
		free(temp_ret_string);
		free(*read_resul);
		i = 0;
	}
	return (*ret_string);
}

char	*get_next_line(int fd)
{
	char		*ret_string;
	char		*read_resul;
	static char	*rest;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (rest)
	{
		while (rest[i] != '\0' && rest[i] != '\n')
			i++;
		if (rest[i] != '\n')
			i++;
		if (rest[i] == '\n')
			ret_string = fake_calloc(i + 2, sizeof(char));
		else
			ret_string = fake_calloc(i + 13, sizeof(char));
		if (!ret_string)
			return (NULL);
		i = 0;
		while (rest[i] != '\0')
		{
			ret_string[i] = rest[i];
			if (rest[i] == '\n')
			{
				i++;
				while (rest[i] != '\0')
				{
					rest[j] = rest[i];
					i++;
					j++;
				}
				rest[j] = '\0';
				return (ret_string);
			}
			else
				i++;
		}
		free(rest);
	}
	else
	{
		ret_string = fake_calloc(11, sizeof(char));
		if (!ret_string)
			return (NULL);
	}
	if (whilebool(&read_resul, &ret_string, fd, &rest) == NULL)
		return (NULL);
	return (ret_string);
}
