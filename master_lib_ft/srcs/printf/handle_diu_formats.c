/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diu_formats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:50:42 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 21:49:30 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft.h"
#include "libftpp.h"

int	handle_diu_formats(char format_specifier, va_list *args)
{
	int				num_d;
	unsigned int	num_u;
	char			*str;

	if (format_specifier == 'd' || format_specifier == 'i')
	{
		num_d = va_arg(*args, int);
		str = ft_uint2str(num_d);
		return (common_print(str));
	}
	else if (format_specifier == 'u')
	{
		num_u = va_arg(*args, unsigned int);
		str = ft_uint2str(num_u);
		return (common_print(str));
	}
	return (-1);
}
