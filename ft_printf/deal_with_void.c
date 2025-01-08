/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:27:19 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/08 10:48:06 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	redimensionate_void(char **string, char *string2, char *string3)
{
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	if (!string2)
	{
		free(*string);
		return (-1);
	}
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(string2) + ft_strlen(string3) + 3);
	if (!*string)
	{
		free(string2);
		return (-1);
	}
	ft_strlcat(*string, string2, 1 + ft_strlen(string2) + ft_strlen(*string));
	(*string)[ft_strlen(*string)] = '0';
	(*string)[ft_strlen(*string)] = 'x';
	ft_strlcat(*string, string3, ft_strlen(*string) + ft_strlen(string3) + 1);
	free(string2);
	return (0);
}

int	deal_with_void(va_list args, char **string)
{
	void			*nothing;
	char			*string2;
	unsigned long	addres;
	char			*string3;

	nothing = va_arg(args, void *);
	addres = (unsigned long)nothing;
	string3 = ft_make_hex(addres, 0);
	if (string3 == 0)
	{
		free(*string);
		return (-1);
	}
	string2 = "";
	return (redimensionate_void(string, string2, string3));
}
