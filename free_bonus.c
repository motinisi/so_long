/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:13:14 by timanish          #+#    #+#             */
/*   Updated: 2025/01/15 11:40:53 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_enemy(t_mapdata *data)
{
	mlx_destroy_image(data->mlx, data->enemy->enemy_img);
	mlx_destroy_image(data->mlx, data->enemy->enemy_on_wall);
	if (data->enemy->enemy_freeze)
		mlx_destroy_image(data->mlx, data->enemy->enemy_freeze);
	free(data->enemy);
}
