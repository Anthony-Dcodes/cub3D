/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:09:19 by antonindvor       #+#    #+#             */
/*   Updated: 2025/06/08 12:24:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// If c is upper char, return lower c
// Else return c
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
