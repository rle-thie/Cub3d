/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:43:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/13 22:22:06 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//parsing
void	err_handling(t_data *data, int file, int mode);
int		parsing(t_data *data);
void	extension_check(char *str, t_data *data);
void	data_mode(char *line, t_data *data);
void	convert_to_rgb(t_data *data, char **line, int index);
void	data_fill(t_data *data, char **line, int index);
int		is_valid_id(char *id);
void	free_split(char **ptr);
int		check_args(char **tab, t_data *data);
int		is_data_full(t_data *data);

//parse map 
void	map_mode(char *line, t_data *data, int file);
int		make_node(char *str, t_data *data);
int		add_back_env(t_map_node *new, t_data *data);
void	struct_to_char(t_data *data, int size);

//map validation
int		map_check_char(char **map);
int		map_check_char(char **map);
int		last_check(t_data *data);
//gnl
char	*get_next_line(int fd, t_data *data);

#endif