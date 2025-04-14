/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:40 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:42 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	destroy_mlx(t_data *data)
{
	if (data->game->image)
		mlx_destroy_image(data->game->mlx, data->game->image);
	if (data->game->game_no)
		mlx_destroy_image(data->game->mlx, data->game->game_no);
	if (data->game->game_so)
		mlx_destroy_image(data->game->mlx, data->game->game_so);
	if (data->game->game_ea)
		mlx_destroy_image(data->game->mlx, data->game->game_ea);
	if (data->game->game_we)
		mlx_destroy_image(data->game->mlx, data->game->game_we);
	if (data->game->wndw)
		mlx_destroy_window(data->game->mlx, data->game->wndw);
	if (data->game->mlx)
		mlx_destroy_display(data->game->mlx);
	ft_full_free(data);
	if (data->game->mlx)
	{
		free(data->game->mlx);
		data->game->mlx = NULL;
	}
	if (data->game)
	{
		free(data->game);
		data->game = NULL;
	}
}

int	handle_keys(int key_code, t_data *data)
{
	if (key_code == 65307)
	{
		printf("Game closed!\n");
		destroy_mlx(data);
		exit(0);
	}
	if (key_code == 119)
		data->key->key_w = 1;
	else if (key_code == 115)
		data->key->key_s = 1;
	else if (key_code == 97)
		data->key->key_a = 1;
	else if (key_code == 100)
		data->key->key_d = 1;
	if (key_code == 65361)
		data->key->key_left = 1;
	else if (key_code == 65363)
		data->key->key_right = 1;
	return (0);
}

int	reset_keys(int key, t_data *data)
{
	if (key == 119)
		data->key->key_w = 0;
	if (key == 115)
		data->key->key_s = 0;
	if (key == 97)
		data->key->key_a = 0;
	if (key == 100)
		data->key->key_d = 0;
	if (key == 65361)
		data->key->key_left = 0;
	if (key == 65363)
		data->key->key_right = 0;
	return (0);
}
