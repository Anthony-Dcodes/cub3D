/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:59:33 by advorace          #+#    #+#             */
/*   Updated: 2026/07/18 18:20:05 by msnizek          ###   ########.fr       */
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
	{
		while (i < scene->map.map_height)
		{
			free(scene->map.map[i]);
			++i;
		}
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
	else if (err == ERR_EMPTY_FILE)
		ft_putstr_fd("File with the map is empty", 2);
	else if (err == ERR_PLAYER)
		ft_putstr_fd("Invalid number of players", 2);
	else if (err == ERR_SMALL_MAP)
		ft_putstr_fd("Map is too small", 2);
	else if (err == ERR_DUP_TEX_FLAG)
		ft_putstr_fd("Textures have same flag", 2);
	else if (err == ERR_DUP_TEX_PATH || err == ERR_INV_PATH_TEX || err == ERR_MISSING_PATH_TEX)
		ft_putstr_fd("Textures have same, invalid or missing path", 2);
	else if (err == ERR_INV_CHAR_TEX)
		ft_putstr_fd("After texture is unspecified data", 2);
	else if (err == ERR_MISSING_TEX)
		ft_putstr_fd("Texture is missing", 2);
	else if (err == ERR_INV_CHAR_MAP)
		ft_putstr_fd("Invalid character in map", 2);
	else if (err == ERR_DUP_COLOR_FLAG || err == ERR_DUP_COLOR || err == ERR_MISSING_COLOR)
		ft_putstr_fd("C or F have same color flag, color or missing", 2);
	else if (err == ERR_INV_COLOR_NUM || err == ERR_MORE_NUM_COLOR)
		ft_putstr_fd("Color has invalid number or more than 3 numbers", 2);
	else if (err == ERR_EMPTY_LINE_MAP)
		ft_putstr_fd("Empty line inside of the map", 2);
	else if (err == ERR_MAP_UNCLOSED)
		ft_putstr_fd("Map is not enclosed", 2);
	else if (err == ERR_MALLOC)
		ft_putstr_fd("Memory allocation failed", 2);
}
