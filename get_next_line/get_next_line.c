/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:18:47 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/23 19:20:39 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*ret_string;
	char		*read_resul;
	static char	*rest;
	int			bool;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (rest)
	{
		while (rest[i] != 0)
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
	rest = malloc(11 * sizeof(char));
	i = 0;
	bool = 0;
	while (!bool)
	{
		read_resul = malloc(11 * sizeof(char));
		read(fd, read_resul, 10);
		while (read_resul[i] != '\0')
		{
			if (read_resul[i] == '\n')
			{
				bool = 1;
				ret_string[i] = read_resul[i];
				i++;
				while (read_resul[i] != '\0')
				{
					rest[i] = read_resul[i];
					i++;
				}
			}
			else
			{
				ret_string[i] = read_resul[i];
			}
			i++;
		}
		free(read_resul);
	}
	return (ret_string);
}
//Hola que
//tal
//bien
//Hola que\nt
//al\nbien#EOF
