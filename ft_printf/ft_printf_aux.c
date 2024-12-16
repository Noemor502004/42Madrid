/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:05:54 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/15 19:49:22 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "unistd.h"
#include "ft_printf.h"

void	str_write(char *string2, int i, char **string, char *string3)
{
	while (string2[i] != '\0')
	{
		(*string)[ft_strlen(*string)] = string2[i];
		i++;
	}
	i = 0;
	while (string3[i] != '\0')
	{
		(*string)[ft_strlen(*string)] = string3[i];
		i++;
	}
}

int	deal_with_str(va_list args, char **string)
{
	char	*string2;
	char	*string3;
	int		i;
	int		size_str3;

	i = 0;
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	if (!string2)
	{
		free(*string);
		return (-1);
	}
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	string3 = va_arg(args, char *);
	size_str3 = ft_strlen(string3);
	ft_realloc(string, ft_strlen(*string) + size_str3 + 1);
	if (!*string)
	{
		free(string2);
		return (-1);
	}
	str_write(string2, i, string, string3);
	free(string2);
	return (0);
}

int	chr_write(char **string, int size, char *string2, char charac)
{
	ft_realloc(string, size + 2);
	if (!*string)
	{
		free(string2);
		return (-1);
	}
	ft_strlcpy(*string, string2, size + 1);
	(*string)[ft_strlen(*string)] = charac;
	free(string2);
	return (0);
}

int	deal_with_char(va_list args, char **string, int perbool)
{
	char	*string2;
	char	charac;
	int		charac_int;
	int		size;

	size = ft_strlen(*string);
	string2 = ft_calloc(size + 1, sizeof(char));
	if (!string2)
	{
		free(*string);
		return (-1);
	}
	ft_strlcpy(string2, *string, size + 1);
	if (perbool == 0)
	{
		charac_int = va_arg(args, int);
		charac = charac_int;
	}
	else
		charac = '%';
	return (chr_write(string, size, string2, charac));
}

int	write_int(char **string, int size, char *str_int, char *string2)
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

int	deal_with_unsig(va_list args, char **string)
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
	integer = va_arg(args, unsigned int);
	if (integer >= 0)
		str_int = ft_itoa(integer);
	else
		str_int = ft_ltoa(4294967296 + integer);
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
	ft_strlcpy(*string, string2, size + 1);
	ft_strlcat(*string, str_int, ft_strlen(str_int) + size + 1);
	free(str_int);
	free(string2);
	return (0);
}

char	*make_hex(unsigned long integer, int cap_bool)
{
	char	*string2;
	char	*str_int;
	int		i;
	int		rest;

	i = -1;
	str_int = ft_calloc(17, sizeof(char));
	if (!str_int)
		return (0);
	while (integer >= 16)
	{
		rest = integer % 16;
		integer /= 16;
		if (rest >= 10)
		{
			if (cap_bool)
				rest += 55;
			else
				rest += 87;
			str_int[++i] = rest;
		}
		else
		{
			string2 = ft_itoa(rest);
			str_int[++i] = *string2;
			free (string2);
		}
	}
	if (integer != 0)
	{
		if (integer >= 10)
		{
			if (cap_bool)
				integer += 55;
			else
				integer += 87;
			str_int[++i] = integer;
		}
		else
		{
			string2 = ft_itoa(integer);
			str_int[++i] = *string2;
			free (string2);
		}
	}
	str_int = ft_str_reverse(str_int);
	return (str_int);
}
