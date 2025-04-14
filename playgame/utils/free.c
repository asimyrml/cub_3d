/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:55 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:57 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	ft_full_free(t_data *data)
{
	if (data->map->map)
		double_free(data->map->map);
	if (data->map->clone_map)
		double_free(data->map->clone_map);
	free(data->map);
	if (data->texture->txt_floor)
		double_free(data->texture->txt_floor);
	if (data->texture->txt_ceiling)
		double_free(data->texture->txt_ceiling);
	free(data->texture->txt_north);
	free(data->texture->txt_south);
	free(data->texture->txt_west);
	free(data->texture->txt_east);
	free(data->texture);
	free(data->parse);
	free(data->player);
	free(data->key);
	free(data->raycast);
}

void	double_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
