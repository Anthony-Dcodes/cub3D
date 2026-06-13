/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:40:52 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 21:04:23 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

static int	print_helper(char format, va_list *args)
{
	int	total;

	total = 0;
	if (ft_strchr("sc", format))
		total += handle_sc_formats(format, args);
	else if (ft_strchr("diu", format))
		total += handle_diu_formats(format, args);
	else if (ft_strchr("xXp", format))
		total += handle_xxp_formats(format, args);
	return (total);
}

static int	print_char_helper(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

// static int	print_2char_helper(char c, char v)
// {
// 	ft_putchar_fd(c, 1);
// 	ft_putchar_fd(v, 1);
// 	return (2);
// }

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_printed;
	int		i;

	va_start(args, format);
	total_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			++i;
			if (ft_strchr("scdiuxXp", format[i]))
				total_printed += print_helper(format[i], &args);
			else
				total_printed += print_char_helper(format[i - 1]);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			total_printed += print_char_helper(format[++i]);
		else
			total_printed += print_char_helper(format[i]);
		++i;
	}
	va_end(args);
	return (total_printed);
}
