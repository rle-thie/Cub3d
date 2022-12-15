/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:43:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/15 15:04:57 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//parsing
void	err_handling(t_data *data, int file, int mode);
int		parsing(t_data *data);
void	extension_check(char *str, t_data *data);
void	data_mode(char *line, t_data *data, int file);
void	convert_to_rgb(t_data *data, char **line, int index, int file);
void	data_fill(t_data *data, char **line, int index, int file);
int		is_valid_id(char *id);
void	free_split(char **ptr);
int		check_args(char **tab, t_data *data, int file, char **line);
int		is_data_full(t_data *data);
int		ext_xpm_check(char *str);

//parse map 
void	map_mode(char *line, t_data *data, int file);
int		make_node(char *str, t_data *data);
int		add_back_env(t_map_node *new, t_data *data);
void	struct_to_char(t_data *data, int size);

//map validation
int		map_check_char(char **map);
int		map_check_char(char **map);
int		last_check(t_data *data);
int		map_check_char(char **map);
int		map_check_char_p2(char **map);
int		last_check(t_data *data);
int		map_validation(char **map);
int		map_coords_check(int i, int j, char **map, char c);
int		map_nb_ck(char **map, int i, int j);
int		can_check(char **map, int i, size_t j);

//gnl
char	*get_next_line(int fd, t_data *data);

#endif