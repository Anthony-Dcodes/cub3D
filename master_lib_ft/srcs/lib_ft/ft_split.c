/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:43:14 by advorace          #+#    #+#             */
/*   Updated: 2025/06/29 18:09:02 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// Count the number of words is s
static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

// Free all allocated memory to arr
static void	free_all(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Create and fill a single word
static int	create_word(char **result, const char *w_s, int w_l, int w_i)
{
	result[w_i] = malloc(w_l + 1);
	if (!result[w_i])
		return (0);
	ft_strlcpy(result[w_i], w_s, w_l + 1);
	return (1);
}

// Fill result array with words from string
static int	fill_words(char **result, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			if (!create_word(result, s + start, i - start, j))
				return (0);
			j++;
		}
	}
	result[j] = NULL;
	return (1);
}

// Split s on c and add words to **result until complete
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!fill_words(result, s, c))
	{
		free_all(result);
		return (NULL);
	}
	return (result);
}
