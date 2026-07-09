/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ray_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 18:16:19 by advorace          #+#    #+#             */
/*   Updated: 2026/07/06 18:23:49 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"

void	assign_ray_dirs(t_vector *vector, t_player *player)
{
	double	p_dir_x;
	double	p_dir_y;
	double	p_plane_x;
	double	p_plane_y;

	p_dir_x = player->dir_x;
	p_dir_y = player->dir_y;
	p_plane_x = player->plane_x;
	p_plane_y = player->plane_y;
	vector->ray_dir_x = p_dir_x + p_plane_x * vector->camera_x;
	vector->ray_dir_y = p_dir_y + p_plane_y * vector->camera_x;
}
