/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:41:16 by nmorgado          #+#    #+#             */
/*   Updated: 2025/01/08 16:12:16 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*fake_calloc(size_t nmemb, size_t size);

void	fake_realloc(char **string, int size);

size_t	fake_strlen(const char *a);

size_t	fake_strlcpy(char *dst, const char *src, size_t size);

int		resize_ret_string(char **temp_ret_string, char **ret_string,
			char **read_resul, int i);

void	*fake_memmove(void *dest, const void *src, size_t n);
#endif