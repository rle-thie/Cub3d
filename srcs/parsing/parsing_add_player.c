/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_add_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:40:07 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 16:07:21 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_plane(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player->dir_x = -1;
		data->raytracing->plane_y = 0.66;
	}
	else if (c == 'S')
	{
		data->player->dir_x = 1;
		data->raytracing->plane_y = -0.66;
	}
	else if (c == 'E')
	{
		data->player->dir_y = 1;
		data->raytracing->plane_x = 0.66;
	}
	else if (c == 'W')
	{
		data->player->dir_y = -1;
		data->raytracing->plane_x = -0.66;
	}
}

void	add_player(t_data *data, int x, int y, char c)
{
	data->player->x = (float)x + 0.5;
	data->player->y = (float)y + 0.5;
	data->player->old_x = x;
	data->player->old_y = y;
	data->player->dir = c;
	data->player->change = 1;
	set_plane(data, c);
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
}
