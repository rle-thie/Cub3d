/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:25:17 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/15 15:47:41 by rle-thie         ###   ########.fr       */
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
void	calc_color(t_data *data);
void	draw_texture(t_data *data, int x);
void	put_floor(t_data *data, int x);

// move
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	rotate_right(t_data *data);
void	rotate_left(t_data *data);

// find delta
void	find_delta(t_data *data);

// init
void	mlx_init_textures(t_data *data);
void	init_game(t_data *data);

// key
int	key_event(int key_pressed, t_data *data);
int	restore_key(int key_pressed, t_data *data);
void	update_position(t_data *data);

// exit fonction
int	ft_exit_esc(t_data *data);

#endif