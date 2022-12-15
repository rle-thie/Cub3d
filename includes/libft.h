/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:38:07 by rle-thie          #+#    #+#             */
/*   Updated: 2022/12/13 19:05:18 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s, t_data *data);
//c'est ultra relou d'avoir remixé la libft comme ça >:|
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gc(char *s1, char *s2, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set, t_data *data);
int		ft_atoi(const char *nptr);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// mlx utils
int		convert_trgb(int t, int r, int g, int b);

#endif