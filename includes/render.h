/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:12:21 by advorace          #+#    #+#             */
/*   Updated: 2026/06/17 10:28:13 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"

void	clean_up(t_scene *scene, int exit_status);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color);
void	put_scene_pixel(t_scene *scene, int x1, int y1);
int		render_scene(void *param);
