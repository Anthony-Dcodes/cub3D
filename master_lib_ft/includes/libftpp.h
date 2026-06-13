/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:51:41 by advorace          #+#    #+#             */
/*   Updated: 2026/06/12 22:22:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

double			ft_atof(const char *str);
char			*ft_int2hex(int num);
char			*ft_str_reverse(char *str);
char			*ft_uint2str(unsigned int n);
unsigned int	ft_uintlen(unsigned int n);
char			*ft_ulong2hex(void *prt);
int				ft_atoi_safe(const char *nptr, int *out);
int				ft_sort_array(int n_elements, int array[]);
