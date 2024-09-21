/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:49:29 by timanish          #+#    #+#             */
/*   Updated: 2024/05/07 17:20:16 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	else if (!len)
		return (0);
	while (*haystack && needle_len <= len--)
	{
		if (*haystack == *needle && !(ft_strncmp(haystack, needle, needle_len)))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
