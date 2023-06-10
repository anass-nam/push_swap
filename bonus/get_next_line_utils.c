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

size_t	strdlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

char	*dup_str(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = strdlen(s1, '\0');
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (cpy)
		cpy = copy(cpy, s1, len);
	return (cpy);
}

char	*copy(char *dst, const char *src, size_t n)
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

char	*joinbuff(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (free(s1), NULL);
	s1_len = strdlen(s1, '\0');
	s2_len = strdlen(s2, '\0');
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	copy(str, s1, s1_len);
	copy(str + s1_len, s2, s2_len);
	free(s1);
	s1 = NULL;
	return (str);
}

char	*shrink(char *s, size_t start, size_t len)
{
	char	*str;

	if (!s || start >= strdlen(s, '\0'))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
		str = copy(str, s + start, len);
	return (str);
}
