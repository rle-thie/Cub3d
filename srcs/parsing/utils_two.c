/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:05:53 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/15 14:19:46 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ext_xpm_check(char *str, t_data *data, int file)
{
	char	*ext;
	int		size;

	size = ft_strlen(str);
	if (size <= 4)
	{
		close(file);
		err_handling(data, 0, 1);
	}
	ext = &(str[size - 4]);
	if (ft_strncmp(ext, ".xpm", 4))
	{
		close(file);
		err_handling(data, 0, 1);
	}
	return (1);
}

//mettre les chagements de fct prot dans les includes