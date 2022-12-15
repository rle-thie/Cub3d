/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coords_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:22:04 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/15 11:23:02 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_coords_check(int i, int j, char **map, char c)
{
	if (!(c == '1' || c == ' ') && i == 0)
		return (1);
	else if ((c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		&& map_nb_ck(map, i, j))
		return (1);
	return (0);
}

int	map_nb_ck(char **map, int i, int j)
{
	if (i == 0 || j == 0 || !can_check(map, i, j))
		return (1);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
	|| map[i][j - 1] == ' ' || map[i][j + 1] == ' '
	|| map[i + 1][j + 1] == ' ' || map[i + 1][j - 1] == ' '
	|| map[i - 1][j - 1] == ' ' || map[i - 1][j + 1] == ' ')
		return (1);
	if (map[i - 1][j] == '\n' || map[i + 1][j] == '\n'
	|| map[i][j - 1] == '\n' || map[i][j + 1] == '\n'
	|| map[i + 1][j + 1] == '\n' || map[i + 1][j - 1] == '\n'
	|| map[i - 1][j - 1] == '\n' || map[i - 1][j + 1] == '\n')
		return (1);
	return (0);
}

int	can_check(char **map, int i, size_t j)
{
	if (j > ft_strlen(map[i - 1]))
		return (0);
	if (!map[i + 1] || j > ft_strlen(map[i + 1]))
		return (0);
	return (1);
}
