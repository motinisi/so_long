/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:13:14 by timanish          #+#    #+#             */
/*   Updated: 2025/01/12 14:51:56 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_enemy(t_mapdata *data)
{
	mlx_destroy_image(data->mlx, data->enemy->enemy_img);
	mlx_destroy_image(data->mlx, data->enemy->enemy_on_wall);
	free(data->enemy);
}
