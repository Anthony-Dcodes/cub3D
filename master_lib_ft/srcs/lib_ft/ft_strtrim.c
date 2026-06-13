/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:45:28 by advorace          #+#    #+#             */
/*   Updated: 2025/05/31 15:42:15 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// Trim all leading and trailing set characters from s1
// Return new string (allocated with malloc)
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	end = (int)ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	if (len <= 0)
		return (ft_strdup(""));
	str = ft_substr(s1, (unsigned int)start, (size_t)len);
	if (!str)
		return (NULL);
	return (str);
}
