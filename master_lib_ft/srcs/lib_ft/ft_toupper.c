/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:43:21 by advorace          #+#    #+#             */
/*   Updated: 2025/06/08 12:24:34 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// If c is lower char, return upper c
// else return c
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
