/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:57:29 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 16:05:45 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_data *data)
{
	data->player->change = 0;
	data->player->dir = 0;
	data->player->x = 0;
	data->player->y = 0;
	data->player->old_x = 0;
	data->player->old_y = 0;
	data->player->dir_x = 0;
	data->player->dir_y = 0;
	data->player->old_dx = 0;
	data->player->old_dy = 0;
}

void	init_raytracing_utils(t_data *data)
{
	data->raytracing->hit = 0;
	data->raytracing->side = 0;
	data->raytracing->side = 0;
	data->raytracing->map_x = 0;
	data->raytracing->map_y = 0;
	data->raytracing->step_x = 0;
	data->raytracing->step_y = 0;
	data->raytracing->line_h = 0;
	data->raytracing->text_x = 0;
	data->raytracing->text_y = 0;
	data->raytracing->text_num = 0;
	data->raytracing->draw_end = 0;
	data->raytracing->draw_start = 0;
}

void	init_raytracing(t_data *data)
{
	data->raytracing->pwd = 0;
	data->raytracing->ddy = 0;
	data->raytracing->ddx = 0;
	data->raytracing->sdy = 0;
	data->raytracing->sdx = 0;
	data->raytracing->step = 0;
	data->raytracing->dir_x = 0;
	data->raytracing->dir_y = 0;
	data->raytracing->wall_x = 0;
	data->raytracing->text_pos = 0;
	data->raytracing->plane_x = 0;
	data->raytracing->plane_y = 0;
	data->raytracing->camera_x = 0;
	init_raytracing_utils(data);
}

void	init_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->texture[i].h = 0;
		data->texture[i].w = 0;
		data->texture[i].bpp = 0;
		data->texture[i].endian = 0;
		data->texture[i].line_length = 0;
		data->texture[i].addr = NULL;
		data->texture[i].img = NULL;
		data->texture[i].path = NULL;
		i++;
	}
}

void	initialise_struct(t_data *data)
{
	init_player(data);
	init_raytracing(data);
	init_texture(data);
}
