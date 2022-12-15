/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:28:25 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 11:30:28 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strjoin_gc(char *s1, char *s2, t_data *data)
{
	size_t	lentt;
	char	*tab;
	size_t	i;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	y = 0;
	lentt = ft_strlen(s1) + ft_strlen(s2);
	tab = ft_malloc(sizeof(char) * (lentt + 1), data);
	if (!tab)
		return (NULL);
	while (s1[y])
		tab[i++] = s1[y++];
	y = 0;
	while (s2[y])
		tab[i++] = s2[y++];
	tab[i] = '\0';
	ft_free(s1, data);
	return (tab);
}

char	*ft_strjoinchar_gc(char *s1, char s2, t_data *data)
{
	size_t	lentt;
	char	*tab;
	size_t	i;
	size_t	y;

	if (!s1 || s2 == '\0')
		return (NULL);
	i = 0;
	y = 0;
	lentt = ft_strlen(s1) + 1;
	tab = ft_calloc(sizeof(char) * (lentt + 1), data);
	if (!tab)
		return (NULL);
	while (s1[y])
		tab[i++] = s1[y++];
	tab[i] = s2;
	i++;
	ft_free(s1, data);
	return (tab);
}
