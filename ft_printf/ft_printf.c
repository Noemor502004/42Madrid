/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:49:03 by nmorgado          #+#    #+#             */
/*   Updated: 2024/11/11 13:13:46 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "unistd.h"

void	ft_realloc(char *string, int size)
{
	free(string);
	string = ft_calloc(size, sizeof(char));
}

void	deal_with_str(va_list args, char *string, int *i)
{
	char	*string2;
	char	*string3;
	size_t	size;
	int		size_str3;

	size = ft_strlen(string - *i);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, string - *i, size + 1);
	string3 = va_arg(args, char *);
	size_str3 = ft_strlen(string3);
	ft_realloc(string - *i, size + size_str3 + 1);
	*i += size_str3;
	while (*string2 != '\0')
	{
		*string = *string2;
		string2++;
		string++;
	}
	while (*string3 != '\0')
	{
		*string = *string3;
		string3++;
		string++;
	}
	free(string2);
	free(string3);
}

void	deal_with_char(va_list args, char *string, int *i, int perbool)
{
	char	*string2;
	char	charac;
	int		charac_int;
	int		size;

	size = ft_strlen(string - *i);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, string - *i, size + 1);
	if (perbool == 0)
	{
		charac_int = va_arg(args, int);
		charac = charac_int;
	}
	else
		charac = '%';
	ft_realloc(string - *i, size + 2);
	ft_strlcpy(string, string2, size + 1);
	*(string + *i) = charac;
	free(string2);
}

void	deal_with_int(va_list args, char *string, int *i)
{
	char	*string2;
	int		integer;
	char	*str_int;
	int		size;

	string -= *i + 1;
	size = ft_strlen(string /*- *i*/);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, string - *i, size + 1);
	integer = va_arg(args, int);
	str_int = ft_itoa(integer);
	ft_realloc(string - *i, size + ft_strlen(str_int) + 1);
	ft_strlcpy(string, string2, size + 1);
	ft_strlcat(string, str_int, ft_strlen(str_int) + size + 1);
	i += ft_strlen(str_int);
	free(str_int);
	free(string2);
}
//Por arreglar
void	deal_with_unsig(va_list args, char *string, int *i)
{
	char	*string2;
	int		integer;
	char	*str_int;
	int		size;

	size = ft_strlen(string - *i);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, string - *i, size + 1);
	integer = va_arg(args, int);
	if (integer >= 0)
		str_int = ft_itoa(integer);
	else
		str_int = ft_ltoa(4294967295 + integer);
	ft_realloc(string - *i, size + ft_strlen(str_int) + 1);
	ft_strlcpy(string, string2, size + 1);
	ft_strlcat(string, str_int, ft_strlen(str_int) + size + 1);
	i += ft_strlen(str_int);
	free(str_int);
	free(string2);
}

char	*make_hex(char *string2, int *integer, int *rest, int cap_bool)
{
	char	*str_int;
	int		i;

	i = -1;
	str_int = ft_calloc(10, sizeof(char));
	while (*integer >= 16)
	{
		*rest = *integer % 16;
		*integer /= 16;
		if (*rest >= 10)
		{
			if (cap_bool)
				*rest += 55;
			else
				*rest += 87;
			str_int[++i] = *rest;
		}
		else
		{
			string2 = ft_itoa(*rest);
			str_int[++i] = *string2;
			free (string2);
		}
	}
	return (str_int);
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

void	deal_with_hex(va_list args, char *string, int *i, int cap_bool)
{
	char	*string2;
	int		integer;
	char	*str_int;
	int		rest;

	string2 = 0;
	integer = va_arg(args, int);
	str_int = make_hex(string2, &integer, &rest, cap_bool);
	if (integer > 9)
	{
		if (cap_bool)
			rest = integer + 55;
		else
			rest = integer + 87;
		*str_int = rest;
	}
	else
	{
		string2 = ft_itoa(integer);
		str_int[ft_strlen(str_int)] = *string2;
		free(string2);
	}
	str_int = str_reverse(str_int);
	string2 = ft_calloc(ft_strlen(string - *i) + 1, sizeof(char));
	ft_strlcpy(string2, string - *i, ft_strlen(string - *i) + 1);
	ft_realloc(string - *i, ft_strlen(string2) + ft_strlen(str_int) + 1);
	ft_strlcpy(string, string2, 1 + ft_strlen(string2));
	ft_strlcat(string, str_int, ft_strlen(string) + ft_strlen(str_int) + 1);
	free(string2);
	*i += ft_strlen(str_int);
}

int	deal_with_it(char const *type, va_list args, char *string, int *i)
{
	char	*string2;

	if (*type == 's')
		deal_with_str(args, string, i);
	else if (*type == 'c')
		deal_with_char(args, string, i, 0);
	else if (*type == 'd' || *type == 'i')
		deal_with_int(args, string, i);
	/*else if (type == 'p')
		deal_with_void(args, string);*/
	//Por arreglar
	/*else if (type == 'u')
		deal_with_unsig(args, string, i);*/
	else if (*type == 'x')
		deal_with_hex(args, string, i, 0);
	else if (*type == 'X')
		deal_with_hex(args, string, i, 1);
	else if (*type == '%')
		deal_with_char(args, string, i, 1);
	string2 = ft_calloc(ft_strlen(string) + 1, sizeof(char));
	ft_strlcpy(string2, string, ft_strlen(string) + 1);
	string = ft_calloc(*i + ft_strlen(type) + 1, sizeof(char));
	ft_strlcpy(string, string2, ft_strlen(string2) + 1);
	free(string2);
	return (--*i);
}

int	ft_printf(char const *type, ...)
{
	va_list	args;
	char	*string;
	int		i;

	i = 0;
	va_start(args, type);
	string = ft_calloc(ft_strlen(type), sizeof(char));
	while (*type != '\0')
	{
		if ((*type == '%') && (*(type + 1) == 's' || *(type + 1) == 'c'
				|| *(type + 1) == 'p' || *(type + 1) == 'd'
				|| *(type + 1) == 'i' || *(type + 1) == 'u'
				|| *(type + 1) == 'x' || *(type + 1) == 'x'
				|| *(type + 1) == 'X' || *(type + 1) == '%'))
			string += deal_with_it(++type, args, string, &i);
		else
			*string = *type;
		string++;
		if (*type != '\0')
			type++;
		i++;
	}
	*string = '\0';
	write(1, string - i, ft_strlen(string - i + 1) + 1);
	free(string);
	return (ft_strlen(string - i));
}
