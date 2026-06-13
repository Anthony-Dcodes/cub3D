/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:30:28 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 21:52:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	handle_sc_formats(char format_specifier, va_list *args);
int	common_print(char *str);
int	handle_diu_formats(char format_specifier, va_list *args);
int	handle_xxp_formats(char format_specifier, va_list *args);
