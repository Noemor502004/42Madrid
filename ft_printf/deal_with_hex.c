/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:09:27 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/17 12:32:27 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	redimensionate_hex(char **string, char *string2, char *str_int)
{
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	if (!string2)
	{
		free(*string);
		return (-1);
	}
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(string2) + ft_strlen(str_int) + 1);
	if (!*string)
	{
		free(string2);
		return (-1);
	}
	ft_strlcpy(*string, string2, 1 + ft_strlen(string2));
	ft_strlcat(*string, str_int, ft_strlen(*string) + ft_strlen(str_int) + 1);
	free(str_int);
	free(string2);
	return (0);
}

int	deal_with_hex(va_list args, char **string, char format)
{
	char					*string2;
	unsigned long int		integer;
	char					*str_int;
	int						cap_bool;

	if (format == 'x')
		cap_bool = 0;
	else
		cap_bool = 1;
	string2 = 0;
	integer = va_arg(args, unsigned int);
	str_int = ft_make_hex(integer, cap_bool);
	if (str_int == 0)
	{
		free(*string);
		return (-1);
	}
	return (redimensionate_hex(string, string2, str_int));
}
