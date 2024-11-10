/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:49:03 by nmorgado          #+#    #+#             */
/*   Updated: 2024/11/10 18:38:35 by nmorgado         ###   ########.fr       */
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
}

void	deal_with_int(va_list args, char *string, int *i)
{
	char	*string2;
	int		integer;
	char	*str_int;
	int		size;

	size = ft_strlen(string - *i);
	string2 = ft_calloc(size + 1, sizeof(char));
	ft_strlcpy(string2, string - *i, size + 1);
	integer = va_arg(args, int);
	str_int = ft_itoa(integer);
	ft_realloc(string - *i, size + ft_strlen(str_int) + 1);
	ft_strlcpy(string, string2, size + 1);
	ft_strlcat(string, str_int, ft_strlen(str_int) + size + 1);
	i += ft_strlen(str_int);
	free(str_int);
}
//Por arreglar
void	deal_with_unsig(va_list args, char *string, int *i)
{
	char			*string2;
	int	integer;
	char			*str_int;
	int				size;

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
}

char	*deal_with_it(char const type, va_list args, char *string, int *i)
{
	if (type == 's')
		deal_with_str(args, string, i);
	else if (type == 'c')
		deal_with_char(args, string, i, 0);
	else if (type == 'd')
		deal_with_int(args, string, i);
	else if (type == 'i')
		deal_with_int(args, string, i);
	/*else if (type == 'p')
		deal_with_void(args, string);*/
	//Por arreglar
	else if (type == 'u')
		deal_with_unsig(args, string, i);
	//En hexadecimal, en lugar de usar 2 funciones diferentes, podria usar un booleano
	/*else if (type == 'x')
		deal_with_hex_low(args, string);
	else if (type == 'X')
		deal_with_hex_up(args, string);*/
	else if (type == '%')
		deal_with_char(args, string, i, 1);
	return (string + *i);
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
			string = deal_with_it(*(++type), args, string, &i);
		else
			*string = *type;
		string++;
		if (*type != '\0')
			type++;
		i++;
	}
	write(1, string - i, ft_strlen(string - i));
	return (ft_strlen(string));
}
