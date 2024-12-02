/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorgado <nmorgado@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:38:24 by nmorgado          #+#    #+#             */
/*   Updated: 2024/12/02 12:44:19 by nmorgado         ###   ########.fr       */
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

#endif