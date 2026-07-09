/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:01:26 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/09 15:01:11 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "get_next_line.h"

static int	parse_config(int fd, t_scene *scene)
{
	char	*line;
	int		type;
	int		elem_loaded;
	int		err;

	elem_loaded = 0;
	while (elem_loaded < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (ERR_MAP);
		type = identify_elements(line);
		err = check_type(type, scene, line, &elem_loaded);
		if (err != ERR_OK)
			return (free(line), ERR_TEXTURES);
		free(line);
	}
	return (ERR_OK);
}

static int	process_map_line(char *line, t_map_node **head, int *started)
{
	t_map_node	*new_node;

	if (identify_elements(line) == EMPTY)
	{
		if (*started)
			return (ERR_MAP);
		free(line);
	}
	else
	{
		*started = 1;
		new_node = new_map_node(line);
		if (!new_node)
			return (ERR_MALLOC);
		add_map_node(head, new_node);
	}
	return (ERR_OK);
}

static int	parse_map_lines(int fd, t_scene *scene)
{
	char		*line;
	int			map_started;
	int			err;
	t_map_node	*map_head;

	map_started = 0;
	map_head = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		err = process_map_line(line, &map_head, &map_started);
		if (err != ERR_OK)
			return (free(line), free_map_list(map_head), err);
		line = get_next_line(fd);
	}
	if (!map_started || !map_head)
		return (ERR_MAP);
	return (create_map(scene, map_head));
}

static int	parse_file(char *path, t_scene *scene)
{
	int		fd;
	int		err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERR_ARGS);
	err = parse_config(fd, scene);
	if (err != ERR_OK)
		return (close(fd), err);
	err = parse_map_lines(fd, scene);
	close(fd);
	return (err);
}

int	parser(t_scene *scene, int argc, char *argv[])
{
	int	err;

	err = input_validate(argc, argv);
	if (err != ERR_OK)
		return (err);
	err = parse_file(argv[1], scene);
	if (err != ERR_OK)
		return (free_textures(scene), err);
	err = map_validate(scene);
	if (err != ERR_OK)
	{
		free_map_array(scene->map.map, scene->map.map_height);
		scene->map.map = NULL;
		free_textures(scene);
		return (err);
	}
	return (ERR_OK);
}
