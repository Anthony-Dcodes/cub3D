/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:26:07 by msnizek           #+#    #+#             */
/*   Updated: 2026/06/30 20:26:07 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

t_map_node	*new_map_node(char *line)
{
	t_map_node	*node;

	node = malloc(sizeof(t_map_node));
	if (!node)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

void	add_map_node(t_map_node **head, t_map_node *new_node)
{
	t_map_node	*current;

	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current != NULL)
		current = current->next;
	current->next = new_node;
}

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

int	get_height(t_map_node *head)
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

int	get_width(t_map_node *head)
{
	int	longest;
	int	current;

	current = 0;
	longest = 0;
	while (head)
	{
		current = ft_strlen(head->line);
		if (longest < current)
			longest = current;
		head = head->next;
	}
	return (longest);
}
char	*pad_line(char *raw_line, int max_width)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * max_width + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (raw_line[i] != '\0')
	{
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
	scene->map.map = malloc(sizeof(char) * scene->map.map_height + 1);
	if (!scene->map.map)
		return (ERR_MALLOC);
	i = 0;
	current = head;
	while (current != NULL)
	{
		scene->map.map[i] = pad_line(current->line, scene->map.map_width);
		if (!scene->map.map[i])
			return (ERR_MALLOC);
		current = current->next;
		i++;
	}
	scene->map.map[i] == NULL;
	free_map_list(head);
	return (ERR_OK);
}
