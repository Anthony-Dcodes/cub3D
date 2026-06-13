/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sc_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:26:01 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 21:06:13 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"

int	handle_sc_formats(char format_specifier, va_list *args)
{
	char	*str;
	char	ch;

	if (format_specifier == 's')
	{
		str = va_arg(*args, char *);
		if (!str)
			return (common_print(ft_strdup("(null)")));
		return (common_print(ft_strdup(str)));
	}
	if (format_specifier == 'c')
	{
		ch = (char)va_arg(*args, int);
		ft_putchar_fd(ch, 1);
		return (1);
	}
	return (-1);
}
