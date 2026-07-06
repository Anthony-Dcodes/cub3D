/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:01:26 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/06 22:31:29 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			return (printf("Error:\nMissing configuration\n"), ERR_MAP);
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
			return (printf("Error:\nEmpty line inside or after map\n"), ERR_MAP);
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
	char	*line;
	int		map_started;
	int		err;
	t_map_node	*map_head;

	map_started = 0;
	map_head = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		err = process_map_line(line, &map_head, &map_started);
		if (err != ERR_OK)
			return (free(line), free_map_list(map_head), err);
	}
	if (!map_started || !map_head)
		return (printf("Error:\nMap is missing in the file\n"), ERR_MAP);
	return (create_map(scene, map_head));
}

int	parse_cub_file(char *path, t_scene *scene)
{
	int		fd;
	int		err;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCannot open the file\n"), ERR_ARGS);
	err = parse_config(fd, scene);
	if (err != ERR_OK)
		return (close(fd), err);
	err = parse_map_lines(fd, scene);
	close(fd);
	return (err);
}

void	free_textures(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (scene->tex_paths[i] != NULL)
		{
			free(scene->tex_paths[i]);
			scene->tex_paths[i] = NULL;
		}
		i++;
	}
}

void	free_map_array(char **map_array, int size)
{
	int	i;

	if (!map_array)
		return ;
	i = 0;
	while (i < size)
	{
		if (map_array[i])
			free(map_array[i]);
		i++;
	}
	free(map_array);
}

int	parser(t_scene *scene, int argc, char *argv[])
{
	int	err;

	err = input_validate(argc, argv);
	if (err != ERR_OK)
		return (err);
	err = parse_cub_file(argv[1], scene);
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
