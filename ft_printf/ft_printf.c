/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:49:03 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/04 16:57:13 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	redimensionate_it(char **string, char *string2, char *type)
{
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(type + 1) + ft_strlen(*string) + 3);
	if (!string)
	{
		free(string2);
		return (-1);
	}
	ft_strlcpy(*string, string2, ft_strlen(string2) + 1);
	free(string2);
	return (0);
}

static int	deal_with_it(char const *type, va_list args, char **string,
int *nul_char)
{
	char	*string2;
	char	*type_cpy;
	int		error;

	error = 0;
	if (*type == 's')
		error = deal_with_str(args, string);
	else if (*type == 'c')
		error = deal_with_char(args, string, 0, nul_char);
	else if (*type == 'd' || *type == 'i')
		error = deal_with_int(args, string);
	else if (*type == 'p')
		error = deal_with_void(args, string);
	else if (*type == 'u')
		error = deal_with_unsig(args, string);
	else if (*type == 'x')
		error = deal_with_hex(args, string, 0);
	else if (*type == 'X')
		error = deal_with_hex(args, string, 1);
	else if (*type == '%')
		error = deal_with_char(args, string, 1, nul_char);
	if (error == -1)
		return (error);
	type_cpy = (char *)type;
	return (string2 = "", redimensionate_it(string, string2, type_cpy));
}

int	ft_printf(char const *type, ...)
{
	va_list	args;
	char	*string;
	int		size;
	int		nul_char;

	if (type == NULL)
		return (-1);
	nul_char = 0;
	va_start(args, type);
	string = ft_calloc(ft_strlen(type), sizeof(char));
	while (*type != '\0')
	{
		if (*type == '%')
		{
			if (deal_with_it(++type, args, &string, &nul_char) == -1)
				return (-1);
		}
		else
			string[ft_strlen(string)] = *type;
		type++;
	}
	size = ft_strlen(string);
	string[size] = '\0';
	write(1, string, size);
	return (va_end(args), free(string), size + nul_char);
}
