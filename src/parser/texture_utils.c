/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:55:10 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/07 20:55:10 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

char	*parse_texture_path(char *line, int i)
{
	int		start;
	int		len;
	int		check;
	char	*path;

	i += skip_whitespaces(line + i);
	len = 0;
	start = i;
	while (line[i] != '\0' && line[i] != ' '
		&& !(line[i] >= 9 && line[i] <= 13))
	{
		len++;
		i++;
	}
	check = i + skip_whitespaces(line + i);
	if (line[check] != '\n' && line[check] != '\0')
		return (NULL);
	path = ft_substr(line, start, len);
	return (path);
}

int	check_dup_and_col(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (ft_strncmp(scene->tex_paths[i], scene->tex_paths[j],
					ft_strlen(scene->tex_paths[i]) + 1) == 0)
				return (ERR_DUP_TEX_PATH);
			j++;
		}
		i++;
	}
	if (scene->floor_color == scene->ceiling_color)
		return (ERR_DUP_COLOR);
	return (ERR_OK);
}

int	check_missing_elem(t_scene *scene, char *line)
{
	if (!line)
		free(line);
	if (scene->ceiling_color == -1 || scene->floor_color == -1)
		return (ERR_MISSING_COLOR);
	return (ERR_MISSING_TEX);
}
