/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:44:43 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 20:53:02 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*join_and_free(char **stash, char **buf)
{
	char	*new;

	if (!stash || !*stash || !buf || !*buf)
	{
		free(*stash);
		*stash = NULL;
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	new = ft_strjoin(*stash, *buf);
	if (!new)
	{
		free(*stash);
		*stash = NULL;
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	free(*stash);
	*stash = NULL;
	return (new);
}
