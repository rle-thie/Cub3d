/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:43:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/12 23:42:37 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//parsing
void	err_handling(t_data *data, int file, int mode);
int		parsing(t_data *data);
void	extension_check(char *str, t_data *data);
void	fcking_switch(char *line, t_data *data);
void	convert_to_rgb(t_data *data, char **line, int index);
void	data_fill(t_data *data, char **line, int index);
int		is_valid_id(char *id);
void	free_split(char **ptr);
int		check_args(char **tab, t_data *data);

//gnl
char	*get_next_line(int fd, t_data *data);

#endif