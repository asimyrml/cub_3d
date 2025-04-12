/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:23:31 by amayuk            #+#    #+#             */
/*   Updated: 2025/04/12 19:38:32 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	set_address(t_data *data)
{
	data->game->address_no = (int *)mlx_get_data_addr(data->game->game_no,
			&data->game->bit_size, &data->game->size_line,
			&data->game->byte_order);
	data->game->address_so = (int *)mlx_get_data_addr(data->game->game_so,
			&data->game->bit_size, &data->game->size_line,
			&data->game->byte_order);
	data->game->address_ea = (int *)mlx_get_data_addr(data->game->game_ea,
			&data->game->bit_size, &data->game->size_line,
			&data->game->byte_order);
	data->game->address_we = (int *)mlx_get_data_addr(data->game->game_we,
			&data->game->bit_size, &data->game->size_line,
			&data->game->byte_order);
	if (!data->game->address_ea || !data->game->address_we
		|| !data->game->address_so || !data->game->address_no)
		ft_error("Error:\nTextures' address creation failed.\n", data);
}

void	load_textures(t_data *data)
{
	data->game->game_no = mlx_xpm_file_to_image(data->game->mlx,
			data->texture->txt_north, &data->game->size, &data->game->size);
	data->game->game_so = mlx_xpm_file_to_image(data->game->mlx,
			data->texture->txt_south, &data->game->size, &data->game->size);
	data->game->game_we = mlx_xpm_file_to_image(data->game->mlx,
			data->texture->txt_west, &data->game->size, &data->game->size);
	data->game->game_ea = mlx_xpm_file_to_image(data->game->mlx,
			data->texture->txt_east, &data->game->size, &data->game->size);
	if (!data->game->game_no || !data->game->game_so || !data->game->game_ea
		|| !data->game->game_we)
		ft_error("Error:\nMissing image file or texture creation failed.",
			data);
	set_address(data);
}

static void	create_window(t_data *data)
{
	data->game->mlx = mlx_init();
	data->game->wndw = mlx_new_window(data->game->mlx, SCREEN_W, SCREEN_H,
			"Cub3D");
	data->game->image = mlx_new_image(data->game->mlx, SCREEN_W, SCREEN_H);
	data->game->address = (int *)mlx_get_data_addr(data->game->image,
			&data->game->bit_size, &data->game->size_line,
			&data->game->byte_order);
	if (!data->game->mlx || !data->game->wndw || !data->game->image
		|| !data->game->address)
		ft_error("Error\nGame creation failed.\n", data);
	load_textures(data);
}

int	close_window(t_data *data)
{
	printf("Game closed.\n");
	destroy_mlx(data);
	exit(0);
}

void	start_game(t_data *data)
{
	create_window(data);
	mlx_loop_hook(data->game->mlx, put_image, data);
	mlx_hook(data->game->wndw, 2, 1L << 0, key_press, data);
	mlx_hook(data->game->wndw, 3, 1L << 1, key_release, data);
	mlx_hook(data->game->wndw, 17, 0, close_window, data);
	mlx_loop(data->game->mlx);
}
