/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:28:18 by timanish          #+#    #+#             */
/*   Updated: 2024/05/27 13:39:14 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	digit(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	else if (n == 0)
		i ++;
	while (n != 0)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*re;

	i = digit(n);
	re = (char *)malloc(sizeof(char) * (i + 1));
	if (!re)
		return (0);
	re[i--] = '\0';
	if (n < 0)
		re[0] = '-';
	else if (n == 0)
		re[0] = '0';
	while (n != 0)
	{
		if ((n % 10) < 0)
			re[i] = n % 10 * -1 + '0';
		else
			re[i] = n % 10 + '0';
		n = n / 10;
		i --;
	}
	return (re);
}
