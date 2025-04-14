/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:44 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:45 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	handle_move_up(t_data *data)
{
	double	x;
	double	y;

	x = data->player->position_x + data->player->direction_x
		* data->game->walk_speed;
	y = data->player->position_y + data->player->direction_y
		* data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}

void	handle_move_down(t_data *data)
{
	double	x;
	double	y;

	x = data->player->position_x - data->player->direction_x
		* data->game->walk_speed;
	y = data->player->position_y - data->player->direction_y
		* data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}

void	handle_move_left(t_data *data)
{
	double	x;
	double	y;

	x = data->player->position_x - data->player->view_x
		* data->game->walk_speed;
	y = data->player->position_y - data->player->view_y
		* data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}

void	handle_move_right(t_data *data)
{
	double	x;
	double	y;

	x = data->player->position_x + data->player->view_x
		* data->game->walk_speed;
	y = data->player->position_y + data->player->view_y
		* data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}

void	handle_move_player(t_data *data)
{
	if (data->key->key_w)
		handle_move_up(data);
	if (data->key->key_s)
		handle_move_down(data);
	if (data->key->key_a)
		handle_move_left(data);
	if (data->key->key_d)
		handle_move_right(data);
	if (data->key->key_right)
		handle_right_view(data);
	if (data->key->key_left)
		handle_left_view(data);
}
