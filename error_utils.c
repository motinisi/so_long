/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:04:33 by timanish          #+#    #+#             */
/*   Updated: 2024/10/06 16:12:50 by timanish         ###   ########.fr       */
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

int	close_window(char **map)
{
	free_map(map);
	exit(0);
}
