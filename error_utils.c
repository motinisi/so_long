/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:04:33 by timanish          #+#    #+#             */
/*   Updated: 2024/09/29 11:49:45 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	int	byte;

	byte = ft_strlen(message);
	write (2, "Error\n", 6);
	write (2, message, byte);
	exit (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i ++;
	}
	free(map);
}

void	free_and_error(char **map, char *message)
{
	free_map(map);
	error(message);
}

void	check_hidden(char *argv)
{
	char	*filename;

	filename = ft_strrchr(argv, '/');
	if (filename == NULL)
		filename = argv;
	else
		filename++;
	if (filename[0] == '.')
		error("file error\n");
}
