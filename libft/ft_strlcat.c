/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:48:16 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/25 16:48:23 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		lenght;

	j = 0;
	i = ft_strlen(dst);
	lenght = ft_strlen(dst) + ft_strlen(src);
	while (i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lenght);
}
