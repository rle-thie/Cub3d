/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:14:55 by ldevy             #+#    #+#             */
/*   Updated: 2022/12/14 18:14:53 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_mode(char *line, t_data *data, int file)
{
	int	i;

	i = 0;
	if (ft_strlen(line) != 1 || line[0] != '\n')
		err_handling(data, file, 3);
	line = get_next_line(file, data);
	if (line && line[0] == '\n')
		err_handling(data, file, 3);
	while (line)
	{
		if (line)
			make_node(line, data);
		line = get_next_line(file, data);
		i++;
	}
	struct_to_char(data, i);
}

int	make_node(char *str, t_data *data)
{
	t_map_node	*new;
	int			size;

	size = ft_strlen(str);
	new = ft_malloc(sizeof(t_map_node), data);
	if (!new)
		return (0);
	new->str = ft_malloc(size + 1, data);
	if (!new->str)
		return (0);
	ft_strlcpy(new->str, str, size + 1);
	new->next = NULL;
	new->prev = NULL;
	add_back_env(new, data);
	return (1);
}

int	add_back_env(t_map_node *new, t_data *data)
{
	t_map_node	*head;

	if (!data->head_map)
	{
		data->head_map = new;
		return (1);
	}
	head = data->head_map;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
	new->prev = head;
	return (1);
}

void	struct_to_char(t_data *data, int size)
{
	t_map_node	*head;
	int			si;
	int			i;

	i = 0;
	data->map = ft_malloc(((size + 1) * sizeof(*data->map)), data);
	head = data->head_map;
	while (head)
	{
		si = ft_strlen(head->str) + 1;
		data->map[i] = ft_malloc(si, data);
		ft_strlcpy(data->map[i], head->str, si);
		head = head->next;
		i++;
	}
	data->map[i] = NULL;
}
