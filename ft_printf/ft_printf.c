/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:49:03 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/02 09:27:58 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "unistd.h"

void	ft_realloc(char **string, int size)
{
	free(*string);
	*string = ft_calloc(size, sizeof(char));
}

void	deal_with_str(va_list args, char **string)
{
	char	*string2;
	char	*string3;
	int		i;
	int		size_str3;

	i = 0;
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	string3 = va_arg(args, char *);
	size_str3 = ft_strlen(string3);
	ft_realloc(string, ft_strlen(*string) + size_str3 + 1);
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
	free(string2);
}

void	deal_with_char(va_list args, char **string, int perbool)
{
	char	*string2;
	char	charac;
	int		charac_int;
	int		size;

	size = ft_strlen(*string);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, *string, size + 1);
	if (perbool == 0)
	{
		charac_int = va_arg(args, int);
		charac = charac_int;
	}
	else
		charac = '%';
	ft_realloc(string, size + 2);
	ft_strlcpy(*string, string2, size + 1);
	(*string)[ft_strlen(*string)] = charac;
	free(string2);
}

void	deal_with_int(va_list args, char **string)
{
	char	*string2;
	int		integer;
	char	*str_int;
	int		size;

	size = ft_strlen(*string);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, *string, size + 1);
	integer = va_arg(args, int);
	str_int = ft_itoa(integer);
	ft_realloc(string, size + ft_strlen(str_int) + 1);
	ft_strlcpy(*string, string2, size + 1);
	ft_strlcat(*string, str_int, ft_strlen(str_int) + size + 1);
	free(str_int);
	free(string2);
}
//Por arreglar
void	deal_with_unsig(va_list args, char **string)
{
	char	*string2;
	int		integer;
	char	*str_int;
	int		size;

	size = ft_strlen(*string);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, *string, size + 1);
	integer = va_arg(args, int);
	if (integer >= 0)
		str_int = ft_itoa(integer);
	else
		str_int = ft_ltoa(4294967295 + integer);
	ft_realloc(string, size + ft_strlen(str_int) + 1);
	ft_strlcpy(*string, string2, size + 1);
	ft_strlcat(*string, str_int, ft_strlen(str_int) + size + 1);
	free(str_int);
	free(string2);
}

char	*str_reverse(char *str_int)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = ft_strlen(str_int) - 1;
	while (i < j)
	{
		aux = str_int[i];
		str_int[i] = str_int[j];
		str_int[j] = aux;
		i++;
		j--;
	}
	return (str_int);
}

char	*make_hex(unsigned long integer, int cap_bool)
{
	char	*string2;
	char	*str_int;
	int		i;
	int		rest;

	i = -1;
	str_int = ft_calloc(17, sizeof(char));
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
	str_int = str_reverse(str_int);
	return (str_int);
}

void	deal_with_hex(va_list args, char **string, int cap_bool)
{
	char	*string2;
	int		integer;
	char	*str_int;

	string2 = 0;
	integer = va_arg(args, int);
	str_int = make_hex(integer, cap_bool);
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(string2) + ft_strlen(str_int) + 1);
	ft_strlcpy(*string, string2, 1 + ft_strlen(string2));
	ft_strlcat(*string, str_int, ft_strlen(*string) + ft_strlen(str_int) + 1);
	free(string2);
}

void	deal_with_void(va_list args, char **string)
{
	void			*nothing;
	char			*string2;
	unsigned long	addres;
	char			*string3;

	nothing = va_arg(args, void *);
	addres = (unsigned long)nothing;
	string3 = make_hex(addres, 0);
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(string2) + ft_strlen(string3) + 3);
	ft_strlcat(*string, string2, 1 + ft_strlen(string2) + ft_strlen(*string));
	(*string)[ft_strlen(*string)] = '0';
	(*string)[ft_strlen(*string)] = 'x';
	ft_strlcat(*string, string3, ft_strlen(*string) + ft_strlen(string3) + 1);
	free(string2);
}

int	deal_with_it(char const *type, va_list args, char **string)
{
	char	*string2;

	if (*type == 's')
		deal_with_str(args, string);
	else if (*type == 'c')
		deal_with_char(args, string, 0);
	else if (*type == 'd' || *type == 'i')
		deal_with_int(args, string);
	else if (*type == 'p')
		deal_with_void(args, string);
	//Por arreglar
	/*else if (*type == 'u')
		deal_with_unsig(args, string, i);*/
	else if (*type == 'x')
		deal_with_hex(args, string, 0);
	else if (*type == 'X')
		deal_with_hex(args, string, 1);
	else if (*type == '%')
		deal_with_char(args, string, 1);
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(type + 1) + ft_strlen(*string) + 1);
	ft_strlcpy(*string, string2, ft_strlen(string2) + 1);
	free(string2);
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
			deal_with_it(++type, args, &string);
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
