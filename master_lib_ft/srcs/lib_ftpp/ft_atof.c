/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:41:55 by advorace          #+#    #+#             */
/*   Updated: 2026/01/26 20:51:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	ft_atof_decimal(const char *str, int *i)
{
	double	result;
	double	decimal;
	double	divisor;

	result = 0.0;
	decimal = 0.0;
	divisor = 1.0;
	while (str[*i] >= '0' && str[*i] <= '9')
		result = result * 10.0 + (str[(*i)++] - '0');
	if (str[*i] == '.')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		decimal = decimal * 10.0 + (str[(*i)++] - '0');
		divisor *= 10.0;
	}
	return (result + decimal / divisor);
}

double	ft_atof(const char *str)
{
	int		i;
	double	sign;
	double	result;

	i = 0;
	sign = 1.0;
	result = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	result = ft_atof_decimal(str, &i);
	return (result * sign);
}
