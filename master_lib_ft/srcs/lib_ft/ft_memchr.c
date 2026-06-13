/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:03:32 by advorace          #+#    #+#             */
/*   Updated: 2025/05/31 14:46:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// Scans the initial n bytes of s
// Returns pointer to the matching (c) byte or NULL
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*prt;

	i = 0;
	prt = (const unsigned char *)s;
	while (i < n)
	{
		if (prt[i] == (unsigned char)c)
			return ((void *)(prt + i));
		i++;
	}
	return (NULL);
}
