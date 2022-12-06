/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:25:17 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/02 22:15:04 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

void	ray_casting(t_data *data);

// raytracing truc complique
void	ray_dir(t_data *data, int x);
void	render_steps(t_data *data);
void	wall_pos(t_data *data);
void	render_height_screen(t_data *data);
void	put_ceiling(t_data *data, int x);
void	get_color(t_data *data);
void	draw_texture(t_data *data, int x);

#endif