/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_of.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:01:26 by msnizek           #+#    #+#             */
/*   Updated: 2026/06/25 18:55:08 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_cub_file(char *path, t_scene *scene)
{
	char	*line;
	int		fd;
	int		type;
	int		elem_loaded;
	int		err;

	elem_loaded = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCannot open the file\n"), ERR_ARGS);
	while ((line = get_next_line(fd)) != NULL)
	{
		type = identify_elements(line);
		if (elem_loaded < 6)
		{
			err = check_type(type, scene, line, &elem_loaded);
			if (err != ERR_OK)
				return (free(line), close(fd), err);
		}
		free(line);
	}
	close(fd);
	// to do: Map part
	return (ERR_OK);
}
