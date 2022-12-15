/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:47:31 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 11:29:34 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup(const char *s, t_data *data)
{
	int		i;
	char	*cpy;
	int		j;

	j = 0;
	while (s[j])
		j++;
	cpy = ft_malloc(sizeof(char) * j + 1, data);
	if (cpy == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
