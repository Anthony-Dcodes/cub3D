/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnizek <msnizek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:58:41 by msnizek           #+#    #+#             */
/*   Updated: 2026/07/18 22:39:29 by msnizek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

int	skip_whitespaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (i);
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
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}
