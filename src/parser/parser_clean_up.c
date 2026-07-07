/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clean_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 19:21:15 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/07 19:21:15 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_list(t_map_node *head)
{
	t_map_node	*tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->line);
		free(head);
		head = tmp;
	}
}

void	free_visited(char **visited, int count)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < count)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
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
