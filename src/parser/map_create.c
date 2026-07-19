/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 19:37:02 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/07 19:37:02 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <stdio.h>

static int	get_height(t_map_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

static int	get_width(t_map_node *head)
{
	int	longest;
	int	current;

	longest = 0;
	while (head)
	{
		current = ft_strlen(head->line);
		if (current > 0 && (head->line[current - 1] == '\n'
				|| head->line[current - 1] == '\r'))
			current--;
		if (longest < current)
			longest = current;
		head = head->next;
	}
	return (longest);
}

static char	*pad_line(char *raw_line, int max_width)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * max_width + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (raw_line[i] != '\0' && raw_line[i] != '\n' && raw_line[i] != '\r'
		&& i < max_width)
	{
		if (raw_line[i] == '\t')
			line[i] = ' ';
		else
			line[i] = raw_line[i];
		i++;
	}
	while (i < max_width)
	{
		line[i] = ' ';
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	create_map(t_scene *scene, t_map_node *head)
{
	int			i;
	t_map_node	*current;

	scene->map.map_height = get_height(head);
	scene->map.map_width = get_width(head);
	scene->map.map = malloc(sizeof(char *) * (scene->map.map_height + 1));
	if (!scene->map.map)
		return (ERR_MALLOC);
	i = 0;
	current = head;
	while (current != NULL)
	{
		scene->map.map[i] = pad_line(current->line, scene->map.map_width);
		if (!scene->map.map[i])
		{
			free_map_array(scene->map.map, i);
			scene->map.map = NULL;
			return (ERR_MALLOC);
		}
		current = current->next;
		i++;
	}
	return (scene->map.map[i] = NULL, free_map_list(head), ERR_OK);
}
