/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:33 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:35 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	check_xpm_file_validity(char *texture, t_data *data)
{
	int	fd;
	int	len;

	fd = open(texture, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		ft_texture_error("Error\nTexture file can not open.\n", data);
		return (1);
	}
	close(fd);
	if (!texture)
	{
		ft_texture_error("Error\nMissing texture file path.\n", data);
		return (1);
	}
	len = ft_strlen(texture);
	if (texture[len - 1] != 'm' || texture[len - 2] != 'p' || texture[len
			- 3] != 'x' || texture[len - 4] != '.')
	{
		ft_texture_error("Error\nTexture file must have a .xpm extension.\n",
			data);
		return (1);
	}
	return (0);
}

static int	xpm_check_2(char *str, t_data *data)
{
	if (str[0] == 'W' && str[1] == 'E')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->txt_west = ft_strdup(str);
		return (check_xpm_file_validity(data->texture->txt_west, data));
	}
	else if (str[0] == 'E' && str[1] == 'A')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->txt_east = ft_strdup(str);
		return (check_xpm_file_validity(data->texture->txt_east, data));
	}
	return (0);
}

int	xpm_check(char *str, t_data *data)
{
	int	flag;

	flag = 0;
	if (str[0] == 'N' && str[1] == 'O')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->txt_north = ft_strdup(str);
		flag = check_xpm_file_validity(data->texture->txt_north, data);
	}
	else if (str[0] == 'S' && str[1] == 'O')
	{
		str += 2;
		while (str && *str == ' ')
			str++;
		data->texture->txt_south = ft_strdup(str);
		flag = check_xpm_file_validity(data->texture->txt_south, data);
	}
	if (flag)
		return (1);
	return (xpm_check_2(str, data));
}
