/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xxp_formats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:18:12 by advorace          #+#    #+#             */
/*   Updated: 2026/06/15 13:51:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "libftpp.h"

static void	to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		++i;
	}
}

int	handle_xxp_formats(char format_specifier, va_list *args)
{
	int		x_num;
	int		y_num;
	char	*x_str;
	void	*prt;

	if (format_specifier == 'x')
	{
		x_num = va_arg(*args, int);
		return (common_print(ft_int2hex(x_num)));
	}
	else if (format_specifier == 'X')
	{
		y_num = va_arg(*args, int);
		x_str = ft_int2hex(y_num);
		to_upper(x_str);
		return (common_print(x_str));
	}
	else if (format_specifier == 'p')
	{
		prt = va_arg(*args, void *);
		return (common_print(ft_ulong2hex(prt)));
	}
	return (-1);
}
