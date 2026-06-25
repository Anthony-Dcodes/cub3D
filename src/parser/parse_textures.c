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

int	skip_whitespaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (i);
}

int	is_empty_line(char *line)
{
	int	i;

	i = skip_whitespaces(line);
		if (line[i] == '\n' || line[i] == '\0')
			return (1);
	return (0);
}

int parse_texture_path(char *line, int i)
{
	int		start;
	int		len;
	char	*path;

	i =+ skip_whitespaces(line);
	len = 0;
	start = i;
	while (line[i] != '\0' || line[i] != '\n' || line != ' ')
	{
		len++;
		i++;
	}
	path = ft_substr(line, start, len);
	return (path);
}

int	get_single_rgb(char *line, int *i)
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

int parse_color(char *line, int i, int *color_dest)
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
	if (b < 0 || b > 255 || line[i++] != ',')
		return (ERR_RGB);
	*color_dest = (r << 16) | (g << 8) | b;
	return (ERR_OK);		
}

int	identify_elements(char *line, int i)
{
	if (is_empty_line(line))
		return (EMPTY);
	i = skip_whitespaces(line);
	if (ft_strncmp(line + i, "NO", 2) == 0)
		return (NORTH);
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		return (SOUTH);
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		return (EAST);
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		return (WEST);
	else if (ft_strncmp(line + i, "F", 1) == 0)
		return (FLOOR);
	else if (ft_strncmp(line + i, "C", 1) == 0)
		return (CEILING);
	return (UNKNOWN);
}

int	parse_cub_file(char *path, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(path), printf("Error\nCannot open the file\n"), ERR_ARGS);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (ERR_OK);
}
