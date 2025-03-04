/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:27:19 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/04 15:58:27 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	redimensionate_void(char **string, char *string2, char *string3,
	int p)
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
	if (p == 0)
	{
		(*string)[ft_strlen(*string)] = '0';
		(*string)[ft_strlen(*string)] = 'x';
	}
	ft_strlcat(*string, string3, ft_strlen(*string) + ft_strlen(string3) + 1);
	if (p == 0)
		free(string3);
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
	addres = (unsigned long int)nothing;
	if (addres == 0)
	{
		string3 = "(nil)";
		addres = 1;
	}
	else
	{
		string3 = ft_make_hex(addres, 0);
		addres = 0;
	}
	if (string3 == 0)
	{
		free(*string);
		return (-1);
	}
	string2 = "";
	return (redimensionate_void(string, string2, string3, addres));
}
