/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:13:48 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 19:38:32 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	set_color(char **str)
{
	int	i;
	int	rgb[3];
	int	color;

	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(str[i]);
		i++;
	}
	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (color);
}

static void	put_rgb(t_data *data)
{
	int	i;
	int	j;
	int	sky_color;
	int	surface_color;

	sky_color = set_color(data->texture->txt_ceiling);
	surface_color = set_color(data->texture->txt_floor);
	i = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			if (i < SCREEN_H / 2)
				data->game->address[i * SCREEN_W + j] = sky_color;
			else
				data->game->address[i * SCREEN_W + j] = surface_color;
			j++;
		}
		i++;
	}
}

void	calculate_rays(t_data *data, int i, int side, int line_h)
{
	while (i < SCREEN_W)
	{
		set_variable(data, i);
		calculate_step(data);
		side = dda_algorithm(data);
		if (side == 0)
			data->raycast->wall_dist = data->raycast->side_x
				- data->raycast->delta_x;
		else
			data->raycast->wall_dist = data->raycast->side_y
				- data->raycast->delta_y;
		line_h = (int)(SCREEN_H / data->raycast->wall_dist);
		data->raycast->wall_start = -line_h / 2 + SCREEN_H / 2;
		if (data->raycast->wall_start < 0)
			data->raycast->wall_start = 0;
		data->raycast->wall_end = line_h / 2 + SCREEN_H / 2;
		if (data->raycast->wall_end > SCREEN_H)
			data->raycast->wall_end = SCREEN_H;
		set_pixel(data, line_h, side);
		put_col(data, i, side);
		i++;
	}
}

int	put_image(t_data *data)
{
	mlx_clear_window(data->game->mlx, data->game->wndw);
	put_rgb(data);
	calculate_rays(data, 0, 0, 0);
	mlx_put_image_to_window(data->game->mlx, data->game->wndw,
		data->game->image, 0, 0);
	move_player(data);
	return (0);
}
