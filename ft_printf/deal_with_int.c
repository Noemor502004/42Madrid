/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:05:54 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/16 09:29:00 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	write_int(char **string, int size, char *str_int, char *string2)
{
	ft_realloc(string, size + ft_strlen(str_int) + 1);
	if (!*string)
	{
		free(str_int);
		free(string2);
		return (-1);
	}
	ft_strlcpy(*string, string2, size + 1);
	ft_strlcat(*string, str_int, ft_strlen(str_int) + size + 1);
	free(str_int);
	free(string2);
	return (0);
}

int	deal_with_int(va_list args, char **string)
{
	char	*string2;
	int		integer;
	char	*str_int;
	int		size;

	size = ft_strlen(*string);
	string2 = ft_calloc(size + 1, sizeof(char));
	if (!string2)
	{
		free(*string);
		return (-1);
	}
	ft_strlcpy(string2, *string, size + 1);
	integer = va_arg(args, int);
	str_int = ft_itoa(integer);
	if (!str_int)
	{
		free(string2);
		free(*string);
		return (-1);
	}
	return (write_int(string, size, str_int, string2));
}
