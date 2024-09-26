/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:05:03 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/26 16:12:50 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*pointer;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			pointer = &s[i];
		}
		i++;
	}
	return ((char *) pointer);
}
