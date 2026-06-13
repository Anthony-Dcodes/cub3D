/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 22:15:03 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 22:15:32 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	validate_int_check_sign(const char *nptr, int *sign, int *i)
{
	if (!nptr || nptr[0] == '\0')
		return (0);
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		(*i)++;
		if (nptr[*i] == '\0')
			return (0);
	}
	return (1);
}

// Validate that input
// Every value has to be valid int
int	ft_atoi_safe(const char *nptr, int *out)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!validate_int_check_sign(nptr, &sign, &i))
		return (0);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (0);
		if (sign == 1 && result > (INT_MAX - (nptr[i] - '0')) / 10)
			return (0);
		if (sign == -1 && - result < (INT_MIN + (nptr[i] - '0')) / 10)
			return (0);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	*out = (int)(sign * result);
	return (1);
}
