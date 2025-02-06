/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_letters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 08:50:24 by nmorgado          #+#    #+#             */
/*   Updated: 2025/02/04 15:56:50 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_write(char *string2, int i, char **string, char *string3)
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
		return (free(*string), -1);
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	string3 = va_arg(args, char *);
	if (string3 == NULL)
		string3 = "(null)";
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

static int	chr_write(char **string, int size, char *string2, char charac)
{
	ft_realloc(string, size + 2);
	if (!*string)
	{
		free(string2);
		return (-1);
	}
	ft_strlcpy(*string, string2, size + 1);
	(*string)[ft_strlen(*string)] = charac;
	if (charac == 0)
	{
		write(1, *string, ft_strlen(*string) + 1);
		free(*string);
		*string = ft_calloc(1, sizeof(char));
	}
	free(string2);
	return (0);
}

int	deal_with_char(va_list args, char **string, int perbool, int *nul_char)
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
		if (charac_int == 0)
			*nul_char += ft_strlen(*string) + 1;
		charac = charac_int;
	}
	else
		charac = '%';
	return (chr_write(string, size, string2, charac));
}
