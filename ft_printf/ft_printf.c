/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:49:03 by nmorgado          #+#    #+#             */
/*   Updated: 2024/11/10 13:08:46 by nmorgado         ###   ########.fr       */
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

char	*deal_with_it(char const type, va_list args, char *string, int *i)
{
	if (type == 's')
		deal_with_str(args, string, i);
	/*else if (type == 'c')
		deal_with_char(args, string);
	else if (type == 'd')
		deal_with_digit(args, string);
	else if (type == 'i')
		deal_with_int(args, string);
	else if (type == 'p')
		deal_with_void(args, string);
	else if (type == 'u')
		deal_with_unsig(args, string);
	else if (type == 'x')
		deal_with_hex_low(args, string);
	else if (type == 'X')
		deal_with_hex_up(args, string);
	else if (type == '%')
		deal_with_per(args, string);*/
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
