/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_delta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:40:09 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:42:16 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	delta_ddx(float dir_x, float dir_y)
{
	float	ddx;

	ddx = 0;
	if (dir_y == 0)
		ddx = 0;
	else if (dir_x == 0)
		ddx = 1;
	else
		ddx = sqrt(1 + (dir_y * dir_y) / (dir_x * dir_x));
	return (ddx);
}

float	delta_ddy(float dir_x, float dir_y)
{
	float	ddy;

	ddy = 0;
	if (dir_x == 0)
		ddy = 0;
	else if (dir_y == 0)
		ddy = 1;
	else
		ddy = sqrt(1 + (dir_x * dir_x) / (dir_y * dir_y));
	return (ddy);
}

void	find_delta(t_data *data)
{
	data->raytracing->ddx = delta_ddx(data->raytracing->dir_x, \
		data->raytracing->dir_y);
	data->raytracing->ddy = delta_ddy(data->raytracing->dir_x, \
		data->raytracing->dir_y);
}
