/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:13:54 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 19:34:46 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	look_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player->direction_x;
	data->player->direction_x = data->player->direction_x
		* cos(-data->game->turn_speed) - data->player->direction_y
		* sin(-data->game->turn_speed);
	data->player->direction_y = old_dir_x * sin(-data->game->turn_speed)
		+ data->player->direction_y * cos(-data->game->turn_speed);
	old_plane_x = data->player->view_x;
	data->player->view_x = data->player->view_x * cos(-data->game->turn_speed)
		- data->player->view_y * sin(-data->game->turn_speed);
	data->player->view_y = old_plane_x * sin(-data->game->turn_speed)
		+ data->player->view_y * cos(-data->game->turn_speed);
}

void	look_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player->direction_x;
	data->player->direction_x = data->player->direction_x
		* cos(data->game->turn_speed) - data->player->direction_y
		* sin(data->game->turn_speed);
	data->player->direction_y = old_dir_x * sin(data->game->turn_speed)
		+ data->player->direction_y * cos(data->game->turn_speed);
	old_plane_x = data->player->view_x;
	data->player->view_x = data->player->view_x * cos(data->game->turn_speed)
		- data->player->view_y * sin(data->game->turn_speed);
	data->player->view_y = old_plane_x * sin(data->game->turn_speed)
		+ data->player->view_y * cos(data->game->turn_speed);
}
