/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:58:41 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/06 22:31:31 by msnizek          ###   ########.fr       */
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

char	*parse_texture_path(char *line, int i)
{
	int		start;
	int		len;
	int		check;
	char	*path;

	i += skip_whitespaces(line + i);
	len = 0;
	start = i;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ')
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

static int	is_empty_line(char *line)
{
	int	i;

	i = skip_whitespaces(line);
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}
int	identify_elements(char *line)
{
	int	i;

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
