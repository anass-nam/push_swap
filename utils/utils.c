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
