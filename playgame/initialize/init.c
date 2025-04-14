/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:44:55 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:44:56 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	init_parse(t_data *data)
{
	data->parse->parse_c = 0;
	data->parse->parse_f = 0;
	data->parse->parse_no = 0;
	data->parse->parse_so = 0;
	data->parse->parse_ea = 0;
	data->parse->parse_we = 0;
}

void	init_texture(t_data *data)
{
	data->texture->txt_ceiling = NULL;
	data->texture->txt_floor = NULL;
	data->texture->txt_north = NULL;
	data->texture->txt_south = NULL;
	data->texture->txt_west = NULL;
	data->texture->txt_east = NULL;
	data->map->clone_map = NULL;
	data->map->map = NULL;
	data->map->row = 0;
	data->map->player_count = 0;
}

void	init_map(t_data *data)
{
	data->map->map = (char **)malloc(sizeof(char *) * (data->map->row + 1));
	if (data->map->map == NULL)
	{
		write(2, "Error:\nMemory problem.\n", 24);
		exit(1);
	}
	data->map->clone_map = (char **)malloc(sizeof(char *) * (data->map->row
				+ 1));
	if (data->map->clone_map == NULL)
	{
		write(2, "Error:\nMemory problem.\n", 24);
		exit(1);
	}
}

void	init_game(t_data *data)
{
	data->game->mlx = NULL;
	data->game->wndw = NULL;
	data->game->image = NULL;
	data->game->game_no = NULL;
	data->game->game_so = NULL;
	data->game->game_ea = NULL;
	data->game->game_we = NULL;
	data->game->address = NULL;
	data->game->address_no = NULL;
	data->game->address_so = NULL;
	data->game->address_ea = NULL;
	data->game->address_we = NULL;
	data->game->size = 0;
	data->game->turn_speed = 0.03;
	data->game->walk_speed = 0.032;
}

void	init_key(t_data *data)
{
	data->key->key_w = 0;
	data->key->key_a = 0;
	data->key->key_s = 0;
	data->key->key_d = 0;
	data->key->key_left = 0;
	data->key->key_right = 0;
}
