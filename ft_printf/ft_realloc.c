/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:42:09 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/08 10:47:39 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_realloc(char **string, int size)
{
	free(*string);
	*string = ft_calloc(size, sizeof(char));
}
