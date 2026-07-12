/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 23:26:44 by msnizek           #+#    #+#             */
/*   Updated: 2026/06/21 23:26:44 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	get_single_rgb(char *line, int *i)
{
	int	val;

	if (!ft_isdigit(line[*i]))
		return (-1);
	val = 0;
	while (ft_isdigit(line[*i]))
	{
		val = (val * 10) + (line[*i] - '0');
		(*i)++;
	}
	return (val);
}

static int	parse_color(char *line, int i, int *color_dest)
{
	int	r;
	int	g;
	int	b;

	while (line[i] == ' ')
		i++;
	r = get_single_rgb(line, &i);
	if (r < 0 || r > 255 || line[i++] != ',')
		return (ERR_RGB);
	g = get_single_rgb(line, &i);
	if (g < 0 || g > 255 || line[i++] != ',')
		return (ERR_RGB);
	b = get_single_rgb(line, &i);
	if (b < 0 || b > 255)
		return (ERR_RGB);
	i += skip_whitespaces(line + i);
	if (line[i] != '\n' && line[i] != '\0')
		return (ERR_RGB);
	*color_dest = (r << 16) | (g << 8) | b;
	return (ERR_OK);
}

static int	load_texture(int type, t_scene *scene, char *line, int *elem_loaded)
{
	int	fd;
	int	start;

	if (scene->tex_paths[type] != NULL)
		return (ERR_PARSER_TEX);
	start = skip_whitespaces(line) + 2;
	scene->tex_paths[type] = parse_texture_path(line, start);
	if (!scene->tex_paths[type])
		return (ERR_PARSER_TEX);
	fd = open(scene->tex_paths[type], O_RDONLY);
	if (fd < 0)
	{
		free(scene->tex_paths[type]);
		scene->tex_paths[type] = NULL;
		return (ERR_PARSER_TEX);
	}
	close(fd);
	(*elem_loaded)++;
	return (ERR_OK);
}

static int	load_color(int type, t_scene *scene, char *line, int *elem_loaded)
{
	int	err;
	int	start;

	if ((type == FLOOR && scene->floor_color != - 1) ||
		(type == CEILING && scene->ceiling_color != -1))
		return (ERR_RGB);
	start = skip_whitespaces(line) + 1;
	if (type == FLOOR)
		err = parse_color(line, start, &scene->floor_color);
	else
		err = parse_color(line, start, &scene->ceiling_color);
	if (err != ERR_OK)
		return (err);
	(*elem_loaded)++;
	return (ERR_OK);
}

int	check_type(int type, t_scene *scene, char *line, int *elem_loaded)
{
	if (type == EMPTY)
		return (ERR_OK);
	else if (type >= NORTH && type <= WEST)
		return (load_texture(type, scene, line, elem_loaded));
	else if (type == FLOOR || type == CEILING)
		return (load_color(type, scene, line, elem_loaded));
	else
		return (ERR_MAP);
}
