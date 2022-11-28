
#ifndef UTILS_H
# define UTILS_H

// init
t_data	*init(char *filename);

// garbage
void		ft_garb_addback(t_data *data, t_garbage *new);
t_garbage	*ft_garb_lstnew(void *ptr, t_data *data);
void		*ft_malloc(size_t size, t_data *data);
void		*ft_calloc(size_t size, t_data *data);
void		ft_free_garb(t_garbage *garb);
void		remove_garb(void *ptr, t_data *data);
void		ft_free(void *ptr, t_data *data);
void		free_all(t_data *data);

// error
int	ft_free_exit(char *msg, int value, t_data *data)
void	ft_exit_message(char *msg, t_data *data, int value);

#endif