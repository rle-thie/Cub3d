/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:43:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/08 14:49:52 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H



//gnl
char		*free_ptr(char *tab);
static char	*ft_strtrim_front(char *str);
static char	*read_buff(int fd, char *stat, int buffer_size);
char		*read_line(char *str);
char		*get_next_line(int fd);

#endif