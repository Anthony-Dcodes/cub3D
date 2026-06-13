/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:52:08 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 21:52:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpp.h"
#include "libft.h"
#include <stddef.h>

char	*ft_int2hex(int num)
{
	char			*hex_map;
	char			*result;
	int				i;
	unsigned int	n;

	n = num;
	if (n == 0)
		return (ft_strdup("0"));
	hex_map = "0123456789abcdef";
	result = ft_calloc(13, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[i] = hex_map[n % 16];
		n /= 16;
		++i;
	}
	result[i] = '\0';
	ft_str_reverse(result);
	return (result);
}
