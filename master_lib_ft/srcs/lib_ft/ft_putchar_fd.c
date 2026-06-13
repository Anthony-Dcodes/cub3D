/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:00:35 by advorace          #+#    #+#             */
/*   Updated: 2025/06/08 12:09:58 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Write char c to file descriptor fd
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
