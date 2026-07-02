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
