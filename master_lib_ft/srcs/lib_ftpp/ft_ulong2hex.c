/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulong2hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:52:20 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 21:52:21 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libftpp.h"

char	*ft_ulong2hex(void *prt)
{
	char			*hex_map;
	char			*result;
	int				i;
	unsigned long	n;

	n = (unsigned long)prt;
	if (n == 0)
		return (ft_strdup("(nil)"));
	hex_map = "0123456789abcdef";
	result = ft_calloc(19, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[i] = hex_map[n % 16];
		n /= 16;
		++i;
	}
	result[i++] = 'x';
	result[i++] = '0';
	result[i] = '\0';
	ft_str_reverse(result);
	return (result);
}
