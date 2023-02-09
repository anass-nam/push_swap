#include "utils.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}

void	ft_putendl_fd(const char *s, int fd)
{
	ft_putstr_fd((char *)s, fd);
	ft_putchar_fd('\n', fd);
}

void    err(char *msg)
{
	ft_putstr_fd("Error", 2);
    ft_putendl_fd(msg, 2);
    exit(EXIT_FAILURE);
}

// void    arr_free(void **ptr)
// {
//     free(*ptr);
//     *ptr = NULL;
// }

/*
	 A																				       B
	[6] [2] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [1] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [ ] 
	[4] [6] [6] [4] [ ] [ ] [ ] [ ] [ ] [2] [2] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [ ] 
	[3] [4] [4] [3] [3] [1] [ ] [4] [3] [3] [3] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [ ] 
	[1] [3] [3] [1] [1] [3] [3] [3] [4] [4] [4] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [ ] 
	[5] [1] [1] [5] [5] [5] [5] [5] [5] [5] [5] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [ ] 
	[2] [5] [5] [6] [6] [6] [6] [6] [6] [6] [6] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [ ] 
	check for order:
		*top = *(top - 1) + 1: sa
		*top = *bottom - 1: ra
		*bottom = *top + 1: rra
	check for min:
		min on top: pb
		min on top - 1: sa
		min on bottom: rra

	reverse condition for B
*/