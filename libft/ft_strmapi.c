/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoomi <yoomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:22:08 by yoomi             #+#    #+#             */
/*   Updated: 2024/10/03 21:52:05 by yoomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;

	i = 0;
	string = ft_calloc(ft_strlen(s), 1);
	while (s[i] != '\0')
	{
		string[i] = s[i];
		string[i] = f(i, string[i]);
		i++;
	}
	return (string);
}
