/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:01:16 by timanish          #+#    #+#             */
/*   Updated: 2024/05/27 13:54:23 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_arr(char const *s, char c)
{
	int	i;
	int	arr;

	i = 0;
	arr = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		arr++;
		if (!s[i] && s[i - 1] == c)
			arr --;
	}
	return (arr);
}

static int	malloc_free(char **result, int arr)
{
	while (arr >= 0)
	{
		free (result[arr]);
		arr--;
	}
	free (result);
	return (0);
}

static int	data_malloc(char **result, char const *s, char c)
{
	int	i;
	int	data;
	int	arr;

	i = 0;
	data = 0;
	arr = 0;
	while (s[i + data])
	{
		while (s[i + data] == c && s[i + data])
			i ++;
		while (s[i + data] != c && s[i + data])
			data ++;
		if (s[i + data - 1] != c)
		{
			result[arr] = (char *)malloc(sizeof(char) * (data + 1));
			if (!result[arr])
				return (malloc_free(result, arr));
		}
		i += data;
		data = 0;
		arr ++;
	}
	return (1);
}

static char	**split_result(char **result, char const *s, char c)
{
	int	i;
	int	arr;
	int	data;

	i = 0;
	arr = 0;
	data = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i ++;
		while (s[i] != c && s[i])
		{
			result[arr][data] = s[i];
			i ++;
			data ++;
		}
		if (s[i - 1] != c)
			result[arr ++][data] = 0;
		data = 0;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		arr;

	arr = count_arr(s, c);
	result = (char **)malloc(sizeof(char *) * (arr + 1));
	if (!result)
		return (0);
	if (data_malloc(result, s, c) == 0)
		return (0);
	result = split_result(result, s, c);
	result[arr] = 0;
	return (result);
}
