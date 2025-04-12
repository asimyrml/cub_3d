/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:14:04 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 18:19:21 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	player_direction_2(char direction, t_data *data)
{
	if (direction == 'E')
	{
		data->player->direction_x = 1;
		data->player->direction_y = 0;
		data->player->view_x = 0;
		data->player->view_y = 0.66;
	}
	else if (direction == 'W')
	{
		data->player->direction_x = -1;
		data->player->direction_y = 0;
		data->player->view_x = 0;
		data->player->view_y = -0.66;
	}
}

void	player_direction(char direction, t_data *data)
{
	if (direction == 'N')
	{
		data->player->direction_x = 0;
		data->player->direction_y = -1;
		data->player->view_x = 0.66;
		data->player->view_y = 0;
	}
	else if (direction == 'S')
	{
		data->player->direction_x = 0;
		data->player->direction_y = 1;
		data->player->view_x = -0.66;
		data->player->view_y = 0;
	}
	else
		player_direction_2(direction, data);
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->row)
	{
		j = -1;
		while (data->map->map[i][++j])
		{
			if (data->map->map[i][j] == 'N' || data->map->map[i][j] == 'W'
				|| data->map->map[i][j] == 'S' || data->map->map[i][j] == 'E')
			{
				data->player->position_x = j + 0.5;
				data->player->position_y = i + 0.5;
				player_around_check(data, i, j);
				player_direction(data->map->map[i][j], data);
			}
		}
	}
	flood_fill(data->player->position_x, data->player->position_y, data);
}

void	player_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->row)
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'N' || data->map->map[i][j] == 'S'
				|| data->map->map[i][j] == 'W' || data->map->map[i][j] == 'E')
				data->map->player_count++;
			j++;
		}
		i++;
	}
	if (data->map->player_count != 1)
		ft_error("Error:\nThe map error.\n", data);
	find_player(data);
}

void	char_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->row)
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] != '1' && data->map->map[i][j] != '0'
				&& data->map->map[i][j] != 'N' && data->map->map[i][j] != 'S'
				&& data->map->map[i][j] != 'W' && data->map->map[i][j] != 'E'
				&& data->map->map[i][j] != ' ' && data->map->map[i][j] != '\n')
				ft_error("Error:\nThe map has invalid charecter.\n", data);
			j++;
		}
		i++;
	}
	player_check(data);
}
