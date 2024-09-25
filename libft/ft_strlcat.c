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

//#include <stdio.h>
//#include <string.h>

/*void	ft_strlcat3(int size, int *j, char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[*j] != '\0' && i < size)
	{
		dest[i] = src[*j];
		i++;
		*j += 1;
	}
	dest[i] = '\0';
	while (src[*j] != '\0')
	{
		*j += 1;
	}
	*j += 1;
}

void	ft_strlcat2(int size, int *j, char *dest, char *src)
{
	dest[size - 1] = '\0';
	while (dest[size] != '\0')
	{
		dest[size] = 0;
		size++;
	}
	while (src[*j] != '\0')
	{
		*j += 1;
	}
	*j += 1;
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	k = i;
	if (i > size)
		ft_strlcat2(size, &j, dest, src);
	else
	{
		ft_strlcat3(size, &j, dest, src);
	}
	return (k + j);
}
*/
int ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    int j;
    int lenght;

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
/*
int	main()
{
	int	i;

	i = 0;
	char array[60] = "Buenas";
	printf("%i", ft_strlcat(array, "Hola", 3));
	while (array[i] != '\0')
	{
		printf("%c", array[i]);
		i++;
	}
	printf("%s", array);
}
*/
