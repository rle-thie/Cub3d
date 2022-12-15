/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastin_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:19:02 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:40:38 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_dir(t_data *data, int x)
{
	data->raytracing->camera_x = 2 * x / (float)data->width - 1;
	data->raytracing->dir_x = data->player->dir_x + data->raytracing->plane_x
		* data->raytracing->camera_x;
	data->raytracing->dir_y = data->player->dir_y + data->raytracing->plane_y
		* data->raytracing->camera_x;
	data->raytracing->map_x = (int)data->player->x;
	data->raytracing->map_y = (int)data->player->y;
}

void	render_steps(t_data *data)
{
	find_delta(data);
	if (data->raytracing->dir_x < 0)
	{
		data->raytracing->step_x = -1;
		data->raytracing->sdx = (data->player->x
				- data->raytracing->map_x) * data->raytracing->ddx;
	}
	else
	{
		data->raytracing->step_x = 1;
		data->raytracing->sdx = (data->raytracing->map_x + 1.0
				- data->player->x) * data->raytracing->ddx;
	}
	if (data->raytracing->dir_y < 0)
	{
		data->raytracing->step_y = -1;
		data->raytracing->sdy = (data->player->y - data->raytracing->map_y)
			* data->raytracing->ddy;
	}
	else
	{
		data->raytracing->step_y = 1;
		data->raytracing->sdy = (data->raytracing->map_y + 1.0
				- data->player->y) * data->raytracing->ddy;
	}
}

void	wall_pos(t_data *data)
{
	data->raytracing->hit = 0;
	while (data->raytracing->hit == 0)
	{
		if (data->raytracing->sdx < data->raytracing->sdy)
		{
			data->raytracing->sdx += data->raytracing->ddx;
			data->raytracing->map_x += data->raytracing->step_x;
			data->raytracing->side = 0;
		}
		else
		{
			data->raytracing->sdy += data->raytracing->ddy;
			data->raytracing->map_y += data->raytracing->step_y;
			data->raytracing->side = 1;
		}
		if (data->map[data->raytracing->map_x][data->raytracing->map_y] == '1')
			data->raytracing->hit = 1;
	}
}

void	render_height_screen(t_data *data)
{
	if (data->raytracing->side == 0)
		data->raytracing->pwd = ((float)data->raytracing->map_x
				- data->player->x + (1 - (float)data->raytracing->step_x) / 2)
			/ data->raytracing->dir_x;
	else
		data->raytracing->pwd = ((float)data->raytracing->map_y
				- data->player->y + (1 - (float)data->raytracing->step_y) / 2)
			/ data->raytracing->dir_y;
	data->raytracing->line_h = (int)(data->height / data->raytracing->pwd);
	data->raytracing->draw_start = -data->raytracing->line_h / 2
		+ data->height / 2;
	if (data->raytracing->draw_start < 0)
		data->raytracing->draw_start = 0;
	data->raytracing->draw_end = data->raytracing->line_h / 2
		+ data->height / 2;
	if (data->raytracing->draw_end >= data->height
		|| data->raytracing->draw_end < 0)
		data->raytracing->draw_end = data->height - 1;
}
