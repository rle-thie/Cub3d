/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastin_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:19:02 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/29 09:50:12 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_dir(t_data *data, int x)
{
	data->raytracing->camera_x = 2 * x / (float)data->width - 1;
	data->raytracing->dir_x = data->player->dir_x + data->raytracing->plane_x * data->raytracing->camera_x;
	data->raytracing->dir_y = data->player->dir_y + data->raytracing->plane_y * data->raytracing->camera_x;
	data->raytracing->map_x = (int)data->player->x;
	data->raytracing->map_y = (int)data->player->y;
}