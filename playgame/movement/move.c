/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyza <beyza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:13:44 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 16:35:59 by beyza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void move_up(t_data *data)
{
	double x;
	double y;

	x = data->player->pos_x + data->player->dir_x * data->game->walk_speed;
	y = data->player->pos_y + data->player->dir_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}

void move_down(t_data *data)
{
	double x;
	double y;

	x = data->player->pos_x - data->player->dir_x * data->game->walk_speed;
	y = data->player->pos_y - data->player->dir_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}

void move_left(t_data *data)
{
	double x;
	double y;

	x = data->player->pos_x - data->player->plane_x * data->game->walk_speed;
	y = data->player->pos_y - data->player->plane_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}

void move_right(t_data *data)
{
	double x;
	double y;

	x = data->player->pos_x + data->player->plane_x * data->game->walk_speed;
	y = data->player->pos_y + data->player->plane_y * data->game->walk_speed;
	if (data->map->map[(int)data->player->pos_y][(int)x] != '1')
		data->player->pos_x = x;
	if (data->map->map[(int)y][(int)data->player->pos_x] != '1')
		data->player->pos_y = y;
}
void move_player(t_data *data)
{
	if (data->key->w)
		move_up(data);
	if (data->key->s)
		move_down(data);
	if (data->key->a)
		move_left(data);
	if (data->key->d)
		move_right(data);
	if (data->key->right)
		look_right(data);
	if (data->key->left)
		look_left(data);
}
