/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:38:24 by nmorgado          #+#    #+#             */
/*   Updated: 2025/03/09 14:23:35 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		deal_with_hex(va_list args, char **string, char format);

int		deal_with_void(va_list args, char **string);

int		ft_printf(char const *type, ...);

int		deal_with_str(va_list args, char **string);

int		deal_with_char(va_list args, char **string, int perbool, int *nul_char);

int		deal_with_int(va_list args, char **string);

int		deal_with_unsig(va_list args, char **string);

int		redimensionate_hex(char **string, char *string2, char *str_int);

char	*ft_uitoa(unsigned int n);

int		ft_printf(char const *type, ...);

void	ft_realloc(char **string, int size);

char	*ft_str_reverse(char *str_int);

char	*ft_make_hex(unsigned long int integer, int cap_bool);
#endif