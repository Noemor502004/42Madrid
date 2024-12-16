/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:38:24 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/16 08:41:44 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_AUX_PRIVATE_H
# define FT_PRINTF_AUX_PRIVATE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		deal_with_hex(va_list args, char **string, int cap_bool);

int		deal_with_void(va_list args, char **string);

int		deal_with_it(char const *type, va_list args, char **string);

int		ft_printf(char const *type, ...);

int		deal_with_str(va_list args, char **string);

int		deal_with_char(va_list args, char **string, int perbool);

int		deal_with_int(va_list args, char **string);

int		deal_with_unsig(va_list args, char **string);

char	*make_hex(unsigned long integer, int cap_bool);

int		redimensionate_hex(char **string, char *string2, char *str_int);

int		redimensionate_void(char **string, char *string2, char *string3);

int		redimensionate_it(char **string, char *string2, char *type);

void	str_write(char *string2, int i, char **string, char *string3);

int		chr_write(char **string, int size, char *string2, char charac);

int		write_int(char **string, int size, char *str_int, char *string2);

#endif