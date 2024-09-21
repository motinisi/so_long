/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:37:31 by timanish          #+#    #+#             */
/*   Updated: 2024/05/07 20:14:14 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*dup;

	i = 0;
	if (ft_strlen(s) <= start)
		len = 0;
	else if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	dup = (char *) malloc(len + 1);
	if (!dup)
		return (0);
	while (len-- && s[start])
		dup[i++] = s[start++];
	dup[i] = '\0';
	return (dup);
}
