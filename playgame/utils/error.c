/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:49 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:50 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	ft_error(char *msg, t_data *data)
{
	ft_full_free(data);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_texture_error(char *msg, t_data *data)
{
	if (data->texture->txt_east)
		free(data->texture->txt_east);
	if (data->texture->txt_west)
		free(data->texture->txt_west);
	if (data->texture->txt_north)
		free(data->texture->txt_north);
	if (data->texture->txt_south)
		free(data->texture->txt_south);
	if (data->texture->txt_floor)
		double_free(data->texture->txt_floor);
	if (data->texture->txt_ceiling)
		double_free(data->texture->txt_ceiling);
	free(data->texture);
	free(data->game);
	free(data->parse);
	free(data->player);
	free(data->key);
	free(data->raycast);
	free(data->map);
	write(2, msg, ft_strlen(msg));
}

void	ft_malloc_error(char *msg, t_data *data)
{
	if (data->map)
		free(data->map);
	if (data->game)
		free(data->game);
	if (data->parse)
		free(data->parse);
	if (data->key)
		free(data->key);
	if (data->player)
		free(data->player);
	if (data->texture)
		free(data->texture);
	if (data->raycast)
		free(data->raycast);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
