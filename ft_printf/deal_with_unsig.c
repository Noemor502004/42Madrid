/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_unsig.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 09:07:09 by nmorgado          #+#    #+#             */
/*   Updated: 2025/02/03 18:50:45 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calloc_checks(char *str_int, char *string2, char **string, int size)
{
	if (!str_int)
	{
		free(string2);
		free(*string);
		return (-1);
	}
	ft_realloc(string, size + ft_strlen(str_int) + 1);
	if (!*string)
	{
		free(string2);
		free(str_int);
		return (-1);
	}
	return (0);
}

int	deal_with_unsig(va_list args, char **string)
{
	char			*string2;
	unsigned int	integer;
	char			*str_int;
	int				size;

	size = ft_strlen(*string);
	string2 = ft_calloc(size + 1, sizeof(char));
	if (!string2)
	{
		free(*string);
		return (-1);
	}
	ft_strlcpy(string2, *string, size + 1);
	integer = va_arg(args, unsigned int);
	str_int = ft_uitoa(integer);
	calloc_checks(str_int, string2, string, size);
	ft_strlcpy(*string, string2, size + 1);
	ft_strlcat(*string, str_int, ft_strlen(str_int) + size + 1);
	free(str_int);
	free(string2);
	return (0);
}
