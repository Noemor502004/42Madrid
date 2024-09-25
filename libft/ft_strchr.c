/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:34:30 by nmorgado          #+#    #+#             */
/*   Updated: 2024/09/25 18:34:32 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;
	const char	*pointer;

	i = 0;
	while (s[i] != '\0')
	{
		if(s[i] == c)
		{
			pointer = &s[i];
			return ((char *) pointer);
		}
		i++;
	}
		return (0);
	
}