/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:23:01 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/20 18:04:31 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	i;

	string = s;
	i = 0;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}
