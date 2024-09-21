/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:02:49 by timanish          #+#    #+#             */
/*   Updated: 2024/05/07 17:15:51 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	tmp = dst;
	s = src;
	if (dst < src)
	{
		while (len --)
			*tmp++ = *s++;
	}
	else if (dst > src)
	{
		tmp += len;
		s += len;
		while (len --)
			*--tmp = *--s;
	}
	return (dst);
}
