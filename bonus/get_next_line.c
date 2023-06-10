/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:57:58 by anammal           #+#    #+#             */
/*   Updated: 2022/12/09 11:58:01 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	reset_buf(char *b)
{
	ssize_t	i;

	i = -1;
	while (++i <= BUFFER_SIZE)
		*(b + i) = '\0';
}

static char	*init(char *rem)
{
	char	*l;

	if (rem)
	{
		l = dup_str(rem);
		free(rem);
		rem = NULL;
	}
	else
		l = dup_str("");
	return (l);
}

static int	check_nl(char *s)
{
	if (s)
	{
		while (*s)
			if (*(s++) == '\n')
				return (0);
		return (1);
	}
	return (0);
}

static char	*readline(char *b, char *l, int fd)
{
	char	*line;
	ssize_t	rd_status;
	size_t	nl_check;

	line = l;
	nl_check = 1;
	while (nl_check)
	{
		reset_buf(b);
		rd_status = read(fd, b, BUFFER_SIZE);
		if (!rd_status)
			break ;
		else if (rd_status == -1)
			return (free(line), NULL);
		line = joinbuff(line, b);
		nl_check = check_nl(line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*ret;
	int			len;

	ret = NULL;
	line = init(buf);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	line = readline(buf, line, fd);
	free(buf);
	buf = NULL;
	if (line)
	{
		len = strdlen(line, '\n') + 1;
		if (*line)
		{
			ret = shrink(line, 0, len);
			buf = shrink(line, len, strdlen(line, '\0') - len);
		}
		free(line);
	}
	return (ret);
}
