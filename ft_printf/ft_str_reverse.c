/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:47:11 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/08 10:47:43 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_reverse(char *string)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(string) - 1;
	while (i < j)
	{
		c = string[i];
		string[i] = string[j];
		string[j] = c;
		i++;
		j--;
	}
	return (string);
}
