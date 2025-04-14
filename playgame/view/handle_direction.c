/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:46:04 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:46:07 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	handle_left_view(t_data *data)
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

void	handle_right_view(t_data *data)
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
