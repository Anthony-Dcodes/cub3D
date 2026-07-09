/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:59:33 by advorace          #+#    #+#             */
/*   Updated: 2026/07/09 15:26:30 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "cub3d.h"
#include "render.h"
#include "libft.h"

void	clean_up(t_scene *scene, int exit_status)
{
	int	i;

	i = 0;
	if (scene->map.map)
		while (i < scene->map.map_height)
		{
			free(scene->map.map[i]);
			++i;
		}
	free(scene->map.map);
	scene->map.map = NULL;
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
	error_message(exit_status);
	exit(exit_status);
}

void	clean_up_textures(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (scene->texture[i].img)
			mlx_destroy_image(scene->mlx, scene->texture[i].img);
		free(scene->tex_paths[i]);
		++i;
	}
}

void	error_message(int err)
{
	if (err == ERR_OK)
		return ;
	ft_putstr_fd("Error\n", 2);
	error_render(err);
	error_parser(err);
	ft_putstr_fd("\n", 2);
}

void	error_render(int err)
{
	if (err == ERR_TEXTURES)
		ft_putstr_fd("Mlx failed loading textures into an image.", 2);
	else if (err == ERR_MLX_INIT)
		ft_putstr_fd("Mlx failed to initialize.", 2);
	else if (err == ERR_MLX_WIN)
		ft_putstr_fd("Mlx failed to create window.", 2);
}

void	error_parser(int err)
{
	if (err == ERR_ARGS)
		ft_putstr_fd("Invalid arguments. Usage: ./cub3D <map.cub>", 2);
	else if (err == ERR_MAP)
		ft_putstr_fd("Invalid map configuration or missing map.", 2);
	else if (err == ERR_RGB)
		ft_putstr_fd("Invalid RGB color format for floor or ceiling.", 2);
	else if (err == ERR_PARSER_TEX)
		ft_putstr_fd("Invalid texture path or loading failure.", 2);
	else if (err == ERR_MALLOC)
		ft_putstr_fd("Memory allocation failed (malloc).", 2);
}
