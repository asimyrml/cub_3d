/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:02 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:03 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	check_floodfill(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->row)
	{
		j = 0;
		while (data->map->clone_map[i][j])
		{
			if (data->map->clone_map[i][j] != ' '
				&& data->map->clone_map[i][j] != 'F'
				&& data->map->clone_map[i][j] != '\n')
				ft_error("Error\nMultiple map.\n", data);
			j++;
		}
	}
}

void	flood_fill(int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || y >= data->map->row
		|| x >= (int)ft_strlen(data->map->clone_map[y])
		|| data->map->clone_map[y][x] == ' '
		|| data->map->clone_map[y][x] == 'F')
		return ;
	data->map->clone_map[y][x] = 'F';
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}

void	check_player_bounds(t_data *data, int i, int j)
{
	int	flg;

	flg = 0;
	if (i == 0)
		ft_error("Error\nThe map error.\n", data);
	if (data->map->map[i - 1] && data->map->map[i - 1][j] && (data->map->map[i
			- 1][j] == '0' || data->map->map[i - 1][j] == '1'))
		flg++;
	if (data->map->map[i + 1] && data->map->map[i + 1][j] && (data->map->map[i
			- 1][j] == '0' || data->map->map[i - 1][j] == '1'))
		flg++;
	if (data->map->map[i][j - 1] && (data->map->map[i][j - 1] == '0'
			|| data->map->map[i][j - 1] == '1'))
		flg++;
	if (data->map->map[i][j + 1] && (data->map->map[i][j + 1] == '0'
			|| data->map->map[i][j + 1] == '1'))
		flg++;
	if (flg < 4)
		ft_error("Error\nThe map error.\n", data);
}

void	bounds_check(t_data *data, int i, int j)
{
	int		valid_count;
	char	up;
	char	down;
	char	left;
	char	right;

	valid_count = 0;
	up = data->map->map[i - 1][j];
	down = data->map->map[i + 1][j];
	left = data->map->map[i][j - 1];
	right = data->map->map[i][j + 1];
	if (data->map->map[i - 1] && up && (up == '0' || up == '1'
			|| up == 'S' || up == 'E' || up == 'N' || up == 'W'))
		valid_count++;
	if (data->map->map[i + 1] && down && (down == '0' || down == '1'
			|| down == 'S' || down == 'N' || down == 'E' || down == 'W'))
		valid_count++;
	if (left && (left == '0' || left == '1' || left == 'N'
			|| left == 'S' || left == 'W' || left == 'E'))
		valid_count++;
	if (right && (right == '0' || right == '1' || right == 'N'
			|| right == 'W' || right == 'S' || right == 'E'))
		valid_count++;
	if (valid_count < 4)
		ft_error("Error\nThe map error.\n", data);
}

void	check_fields(t_data *data, int i)
{
	int	j;

	while (++i < data->map->row)
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == '0')
				bounds_check(data, i, j);
			j++;
		}
	}
}
