/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:26:32 by advorace          #+#    #+#             */
/*   Updated: 2025/06/29 17:00:31 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Allocate mem to array of nmemb elements of size bytes
// Return pointer to allocated mem or NULL if fail
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_mem;
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if (size != 0 && (size_t)-1 / size < nmemb)
		return (NULL);
	total_mem = nmemb * size;
	if (total_mem == 0)
		return (malloc(0));
	ptr = malloc(total_mem);
	if (ptr == NULL)
		return (NULL);
	while (i < total_mem)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
