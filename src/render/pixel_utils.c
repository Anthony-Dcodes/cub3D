/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:05:10 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 10:26:34 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	dst = scene->frame.addr + (y * scene->frame.line_len + x
			* (scene->frame.bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_scene_pixel(t_scene *scene, int x1, int y1)
{
	int	final_color;

	final_color = create_trgb(10, 156, 8, 200);
	my_mlx_pixel_put(scene, x1, y1, final_color);
}
