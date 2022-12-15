/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:05:53 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/15 14:51:15 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ext_xpm_check(char *str)
{
	char	*ext;
	int		size;

	size = ft_strlen(str);
	if (size <= 4)
		return (0);
	ext = &(str[size - 4]);
	if (ft_strncmp(ext, ".xpm", 5))
		return (0);
	return (1);
}
