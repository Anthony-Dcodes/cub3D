/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:59:33 by advorace          #+#    #+#             */
/*   Updated: 2026/06/15 14:05:10 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "cub3d.h"

void	clean_up(t_player *player, int exit_status)
{
	if (!player)
		exit(exit_status);
	if (player->mlx_struct.img)
		mlx_destroy_image(player->mlx_struct.mlx, player->mlx_struct.img);
	if (player->mlx_struct.win)
		mlx_destroy_window(player->mlx_struct.mlx, player->mlx_struct.win);
	if (player->mlx_struct.mlx)
	{
		mlx_destroy_display(player->mlx_struct.mlx);
		free(player->mlx_struct.mlx);
	}
	exit(exit_status);
}
