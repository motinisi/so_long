/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:44:29 by timanish          #+#    #+#             */
/*   Updated: 2024/06/12 17:18:43 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t	size;
	char	*dup;
	int		i;

	size = ft_strlen(src);
	dup = (char *)malloc(size + 1);
	i = 0;
	if (!dup)
		return (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		n;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = -1;
	n = 0;
	if (!join)
		return (NULL);
	while (s1[++i])
		join[i] = s1[i];
	while (s2[n])
		join[i++] = s2[n++];
	join[i] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i ++;
	}
	if ((char)c == 0)
		return ((char *)&s[i]);
	return (0);
}
