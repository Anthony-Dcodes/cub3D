/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 22:20:48 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 22:22:25 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sort_array(int n_elements, int array[])
{
	int	i;
	int	sorted;
	int	temp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 1;
		while (i < n_elements)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				sorted = 0;
			}
			++i;
		}
	}
	return (1);
}
