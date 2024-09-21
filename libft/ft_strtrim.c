/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:09:51 by timanish          #+#    #+#             */
/*   Updated: 2024/05/07 20:14:08 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		t;

	while (ft_strchr(set, *s1) != 0 && s1 && *s1 != '\0')
		s1 ++;
	i = ft_strlen(s1);
	if (*s1 != '\0')
		i = i - 1;
	while (ft_strchr(set, s1[i]) != 0 && s1 && s1[i] != '\0')
		i --;
	if (*s1 != '\0')
		i = i + 1;
	if (*set == '\0')
		i = ft_strlen(s1);
	trim = (char *)malloc(i + 1);
	if (!trim)
		return (NULL);
	t = -1;
	while (++t < i && i != 0)
		trim[t] = s1[t];
	trim[t] = '\0';
	return (trim);
}
