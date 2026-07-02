/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:59:33 by advorace          #+#    #+#             */
/*   Updated: 2026/07/02 19:07:28 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "cub3d.h"
#include "render.h"

void	clean_up(t_scene *scene, int exit_status)
{
	int	i;

	i = 0;
	//if (scene->map.map)
	//	while (i < scene->map.malloc_count)
	//	{
	//		free(scene->map.map[i]);
	//		++i;
	//	}
	//free(scene->map.map);
	if (!scene->mlx)
		exit(exit_status);
	clean_up_textures(scene);
	if (scene->frame.img)
		mlx_destroy_image(scene->mlx, scene->frame.img);
	if (scene->win)
		mlx_destroy_window(scene->mlx, scene->win);
	if (scene->mlx)
	{
		mlx_destroy_display(scene->mlx);
		free(scene->mlx);
	}
	exit(exit_status);
}

void	clean_up_textures(t_scene *scene)
{
	mlx_destroy_image(scene->mlx, scene->texture[NORTH].img);
	mlx_destroy_image(scene->mlx, scene->texture[SOUTH].img);
	mlx_destroy_image(scene->mlx, scene->texture[EAST].img);
	mlx_destroy_image(scene->mlx, scene->texture[WEST].img);
}
