/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:15:00 by advorace          #+#    #+#             */
/*   Updated: 2025/06/01 12:25:59 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Get the lengh of n
static int	ft_numlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// Transform n to string representation
char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	x;

	len = ft_numlen(n);
	x = n;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (x == 0)
		str[0] = '0';
	else if (x < 0)
	{
		str[0] = '-';
		x *= -1;
	}
	while (x)
	{
		str[--len] = (x % 10) + '0';
		x /= 10;
	}
	return (str);
}
