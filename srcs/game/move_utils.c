/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:09 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:29:18 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_plane_x;

	old_plane_x = data->raytracing->plane_x;
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->player->dir_x = data->player->dir_x
		* cos(data->rotate_speed) - data->player->dir_y
		* sin(data->rotate_speed);
	data->player->dir_y = data->player->old_dx
		* sin(data->rotate_speed) + data->player->dir_y
		* cos(data->rotate_speed);
	data->raytracing->plane_x = data->raytracing->plane_x
		* cos(data->rotate_speed) - data->raytracing->plane_y
		* sin(data->rotate_speed);
	data->raytracing->plane_y = old_plane_x
		* sin(data->rotate_speed) + data->raytracing->plane_y
		* cos(data->rotate_speed);
	data->player->change = 1;
}
