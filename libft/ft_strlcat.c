/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:03:36 by timanish          #+#    #+#             */
/*   Updated: 2024/05/07 20:13:47 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen + dstsize);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	else if (dstlen + 1 < dstsize)
	{
		while (src[i] && (dstlen + i +1 < dstsize))
		{
			dst[dstlen + i] = src[i];
			i ++;
		}
		dst[dstlen + i] = 0;
	}
	return (dstlen + srclen);
}
