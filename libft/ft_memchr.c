/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:08:58 by timanish          #+#    #+#             */
/*   Updated: 2024/05/07 17:15:29 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	int				i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)ptr;
	while (num--)
	{
		if (tmp[i] == (unsigned char)value)
			return (&tmp[i]);
		i ++;
	}
	return (NULL);
}
