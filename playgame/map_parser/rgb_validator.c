/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:25 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:27 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	rgb_num_check(char **rgb_i, char **control, int num, t_data *data)
{
	if (num < 0 || num > 255 || ft_strncmp(*rgb_i, *control,
			ft_strlen(*control)))
	{
		free(*rgb_i);
		free(*control);
		ft_texture_error("Error\nRGB value must be between 0 and 255.\n", data);
		return (1);
	}
	else
	{
		free(*rgb_i);
		free(*control);
	}
	return (0);
}

int	rgb_validate(char **rgb, int i, int j, t_data *data)
{
	char	*rgb_i;
	char	*control;
	int		num;
	int		flag;

	while (rgb[i])
	{
		j = 0;
		rgb_i = check_is_digit_and_trim(rgb[i], data);
		if (!rgb_i)
			return (1);
		num = ft_atoi(rgb[i]);
		control = ft_itoa(num);
		flag = rgb_num_check(&rgb_i, &control, num, data);
		if (flag)
			return (1);
		i++;
	}
	return (0);
}

int	ensure_rgb_triplet(char **str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
	{
		ft_texture_error("Error\nRGB must have 3 components.\n", data);
		return (1);
	}
	return (0);
}

int	ensure_rgb_comma(char *str, t_data *data)
{
	int	i;
	int	c_count;

	i = 0;
	c_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			c_count++;
		i++;
	}
	if (c_count != 2)
	{
		ft_texture_error("Error\nRGB must have 3 components.\n", data);
		return (1);
	}
	return (0);
}

int	color_line_check(char *str, t_data *data)
{
	if (str[0] == 'F' && str[1] == ' ')
	{
		if (data->texture->txt_floor == NULL)
			data->texture->txt_floor = ft_split(str + 2, ',');
		if (ensure_rgb_comma(str, data)
			|| ensure_rgb_triplet(data->texture->txt_floor, data)
			|| rgb_validate(data->texture->txt_floor, 0, 0, data))
			return (1);
	}
	else if (str[0] == 'C' && str[1] == ' ')
	{
		if (data->texture->txt_ceiling == NULL)
			data->texture->txt_ceiling = ft_split(str + 2, ',');
		if (ensure_rgb_comma(str, data)
			|| ensure_rgb_triplet(data->texture->txt_ceiling, data)
			|| rgb_validate(data->texture->txt_ceiling, 0, 0, data))
			return (1);
	}
	return (0);
}
