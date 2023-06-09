/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anammal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:58:11 by anammal           #+#    #+#             */
/*   Updated: 2022/12/09 11:58:12 by anammal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strdlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strdlen(s1, '\0');
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (cpy)
		cpy = ft_strncpy(cpy, s1, len);
	return (cpy);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (free(s1), NULL);
	s1_len = ft_strdlen(s1, '\0');
	s2_len = ft_strdlen(s2, '\0');
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, s1_len);
	ft_strncpy(str + s1_len, s2, s2_len);
	free(s1);
	s1 = NULL;
	return (str);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*str;

	if (!s || start >= ft_strdlen(s, '\0'))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
		str = ft_strncpy(str, s + start, len);
	return (str);
}
