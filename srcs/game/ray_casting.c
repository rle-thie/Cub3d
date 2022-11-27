/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:58:41 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/27 19:24:32 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub3d.h"

void	init_game(t_data *data)
{
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		ft_free_exit("Can't init mlx ptr", 1, data);
	data->mlx->win = mlx_new_window(data->mlx->ptr, data->width, data->height, "Cub3d");
	if (!data->mlx->win)
		ft_free_exit("Can't init mlx window", 1, data);
	data->mlx->img = mlx_new_image(data->mlx->ptr, data->width, data->height);
	if (!data->mlx->img)
		ft_free_exitft_free_exit("Can't init mlx image", 1, data);
	data->mlx->addr = (int *)mlx_get_data_addr(data->mlx->img, &data->mlx->bpp, \
		&data->mlx->line_length, &data->mlx->endian);
	if (!data->mlx->addr)
		ft_free_exit("Can't init mlx addr", 1, data);
	// get_textures()
}

void	ray_casting(t_data *data)
{
	init_game(data);
}