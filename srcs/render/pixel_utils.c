/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:05:10 by advorace          #+#    #+#             */
/*   Updated: 2026/06/15 13:19:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->i_addr + (y * mlx->i_line_length + x
			* (mlx->i_bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_scene_pixel(t_player *player, int x1, int y1)
{
	int	final_color;

	final_color = create_trgb(10, 156, 156, 200);
	my_mlx_pixel_put(&player->mlx_struct, x1, y1, final_color);
}
