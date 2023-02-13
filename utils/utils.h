#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putendl_fd(const char *s, int fd);
void    err(char *msg);
int     *parse_items(char const**s_items, int size);
int		ft_strcmp(const char *s1, const char *s2);

#endif