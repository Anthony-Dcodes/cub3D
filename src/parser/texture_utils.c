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
	while (line[i] != '\0' && line[i] != ' ' && !(line[i] >= 9 && line[i] <= 13))
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
