/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:38:24 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/16 09:14:42 by nmorgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		deal_with_hex(va_list args, char **string, int cap_bool);

int		deal_with_void(va_list args, char **string);

int		ft_printf(char const *type, ...);

int		deal_with_str(va_list args, char **string);

int		deal_with_char(va_list args, char **string, int perbool);

int		deal_with_int(va_list args, char **string);

int		deal_with_unsig(va_list args, char **string);

int		redimensionate_hex(char **string, char *string2, char *str_int);

#endif