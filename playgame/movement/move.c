/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:13:44 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 18:38:08 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void move_up(t_data *data)
{
	double x;
	double y;

	x = data->player->position_x + data->player->direction_x * data->game->walk_speed;
	y = data->player->position_y + data->player->direction_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}

void move_down(t_data *data)
{
	double x;
	double y;

	x = data->player->position_x - data->player->direction_x * data->game->walk_speed;
	y = data->player->position_y - data->player->direction_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}

void move_left(t_data *data)
{
	double x;
	double y;

	x = data->player->position_x - data->player->view_x * data->game->walk_speed;
	y = data->player->position_y - data->player->view_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}

void move_right(t_data *data)
{
	double x;
	double y;

	x = data->player->position_x + data->player->view_x * data->game->walk_speed;
	y = data->player->position_y + data->player->view_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->position_y][(int)x] != '1')
		data->player->position_x = x;
	if (data->map->map[(int)y][(int)data->player->position_x] != '1')
		data->player->position_y = y;
}
void move_player(t_data *data)
{
	if (data->key->key_w)
		move_up(data);
	if (data->key->key_s)
		move_down(data);
	if (data->key->key_a)
		move_left(data);
	if (data->key->key_d)
		move_right(data);
	if (data->key->key_right)
		look_right(data);
	if (data->key->key_left)
		look_left(data);
}
