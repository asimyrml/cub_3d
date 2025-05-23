/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:06 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/16 19:15:22 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	check_map_edges(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[0][i])
	{
		if (data->map->map[0][i] != '1' && data->map->map[0][i] != '\n'
			&& data->map->map[0][i] != ' ' && data->map->map[0][i] != '\t')
			ft_error("Error\nThe map error.\n", data);
		i++;
	}
	i = 0;
	while (data->map->map[data->map->row - 1][i])
	{
		if (data->map->map[data->map->row - 1][i] != '1'
			&& data->map->map[data->map->row - 1][i] != '\n'
			&& data->map->map[data->map->row - 1][i] != ' '
			&& data->map->map[data->map->row - 1][i] != '\t'
			&& data->map->map[data->map->row - 1][i] != '\0')
			ft_error("Error\nThe map error.\n", data);
		i++;
	}
}

void	check_above_space(t_data *data, int map_row)
{
	int	j;
	int	ctr;

	while (map_row-- > 0)
	{
		j = 0;
		while (data->map->map[map_row][j])
		{
			if (data->map->map[map_row][j] == ' ')
			{
				ctr = map_row - 1;
				while (ctr > 0 && (int)ft_strlen(data->map->map[ctr]) - 1 > j
					&& data->map->map[ctr][j] && data->map->map[ctr][j] == ' ')
					ctr--;
				if (ctr <= 0 || (int)ft_strlen(data->map->map[ctr]) - 1 <= j)
				{
					j++;
					continue ;
				}
				else if (data->map->map[ctr][j] != '1')
					ft_error("Error\nThe map error.\n", data);
			}
			j++;
		}
	}
}

void	check_under_space(t_data *data, int i, int row)
{
	int	j;
	int	ctr;

	while (++i < row)
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == ' ')
			{
				ctr = i + 1;
				while (ctr < row && (int)ft_strlen(data->map->map[ctr]) - 1 > j
					&& data->map->map[ctr][j] && data->map->map[ctr][j] == ' ')
					ctr++;
				if (ctr >= row || (int)ft_strlen(data->map->map[ctr]) - 1 <= j)
				{
					j++;
					continue ;
				}
				else if (data->map->map[ctr][j] != '1')
					ft_error("Error\nThe map error.\n", data);
			}
			j++;
		}
	}
}

void	check_right_space(t_data *data, int i)
{
	int	ctr;
	int	j;

	while (++i < data->map->row)
	{
		j = 0;
		while (data->map->map[i][j++])
		{
			if (data->map->map[i][j] == ' ')
			{
				ctr = j + 1;
				while (ctr < (int)ft_strlen(data->map->map[i])
					&& data->map->map[i][ctr] && data->map->map[i][ctr] == ' ')
					ctr++;
				if (ctr >= (int)ft_strlen(data->map->map[i]) || ctr
					+ 1 == (int)ft_strlen(data->map->map[i]))
				{
					j++;
					continue ;
				}
				else if (data->map->map[i][ctr] != '1')
					ft_error("Error\nThe map error.\n", data);
			}
		}
	}
}

void	check_left_space(t_data *data, int i)
{
	int	j;
	int	control;

	while (++i < data->map->row)
	{
		j = (int)ft_strlen(data->map->map[i]) - 1;
		while (j > 0 && data->map->map[i][j])
		{
			if (data->map->map[i][j] == ' ')
			{
				control = j - 1;
				while (control > 0 && data->map->map[i][control]
					&& data->map->map[i][control] == ' ')
					control--;
				if (control <= 0 || control == j - 1)
				{
					j--;
					continue ;
				}
				else if (data->map->map[i][control] != '1')
					ft_error("Error\nThe map error.\n", data);
			}
			j--;
		}
	}
}
