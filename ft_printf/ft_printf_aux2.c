/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:27:19 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/12 11:05:20 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	redimensionate_hex(char **string, char *string2, char *str_int)
{
	string2 = ft_calloc(ft_strlen(*string) + 1, sizeof(char));
	if (!string2)
	{
		free(*string);
		return (-1);
	}
	ft_strlcpy(string2, *string, ft_strlen(*string) + 1);
	ft_realloc(string, ft_strlen(string2) + ft_strlen(str_int) + 1);
	if (!*string)
	{
		free(string2);
		return (-1);
	}
	ft_strlcpy(*string, string2, 1 + ft_strlen(string2));
	ft_strlcat(*string, str_int, ft_strlen(*string) + ft_strlen(str_int) + 1);
	free(string2);
	return (0);
}

int	redimensionate_it(char **string, char *string2, char *type)
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