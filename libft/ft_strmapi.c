/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:14:27 by timanish          #+#    #+#             */
/*   Updated: 2024/05/07 20:13:56 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*re;
	size_t	i;

	i = ft_strlen(s);
	re = (char *)malloc(sizeof(char) * (i + 1));
	if (!re)
		return (0);
	re[i] = '\0';
	while (i--)
		re[i] = (*f)(i, s[i]);
	return (re);
}
