/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:49:03 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/16 09:28:11 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	redimensionate_it(char **string, char *string2, char *type)
{
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(type + 1) + ft_strlen(*string) + 1);
	if (!string)
	{
		free(string2);
		return (-1);
	}
	ft_strlcpy(*string, string2, ft_strlen(string2) + 1);
	free(string2);
	return (0);
}

static int	deal_with_it(char const *type, va_list args, char **string)
{
	char	*string2;
	char	*type_cpy;
	int		error;

	if (*type == 's')
		error = deal_with_str(args, string);
	else if (*type == 'c')
		error = deal_with_char(args, string, 0);
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
		error = deal_with_char(args, string, 1);
	if (error == -1)
		return (error);
	type_cpy = (char *)type;
	string2 = "";
	return (redimensionate_it(string, string2, type_cpy));
}

int	ft_printf(char const *type, ...)
{
	va_list	args;
	char	*string;

	va_start(args, type);
	string = ft_calloc(ft_strlen(type), sizeof(char));
	while (*type != '\0')
	{
		if ((*type == '%') && (*(type + 1) == 's' || *(type + 1) == 'c'
				|| *(type + 1) == 'p' || *(type + 1) == 'd'
				|| *(type + 1) == 'i' || *(type + 1) == 'u'
				|| *(type + 1) == 'x' || *(type + 1) == 'x'
				|| *(type + 1) == 'X' || *(type + 1) == '%'))
		{
			if (deal_with_it(++type, args, &string) == -1)
				return (-1);
		}
		else
			string[ft_strlen(string)] = *type;
		if (*type != '\0')
			type++;
	}
	string[ft_strlen(string)] = '\0';
	write(1, string, ft_strlen(string));
	free(string);
	return (ft_strlen(string));
}
