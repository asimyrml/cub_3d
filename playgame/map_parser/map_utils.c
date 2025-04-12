/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayirmili <ayirmili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:14:11 by kgulfida          #+#    #+#             */
/*   Updated: 2025/04/12 19:46:18 by ayirmili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	finish_gnl(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
}

int	check_c(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((ft_isalnum(line[i]) || ft_isalpha(line[i])) && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	is_map_closed(t_data *data)
{
	first_last_line(data);
	under_space(data, -1, data->map->row);
	above_space(data, (data->map->row - 1));
	left_space(data, -1);
	right_space(data, -1);
	check_all_field(data, -1);
}

void	process_line(char *line, t_data *data, int fd)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \n");
	texture_count(trimmed, data);
	if (trimmed[0] == '1' && (data->parse->parse_no == 0
			|| data->parse->parse_so == 0 || data->parse->parse_we == 0
			|| data->parse->parse_ea == 0 || data->parse->parse_c == 0
			|| data->parse->parse_f == 0))
	{
		ft_texture_error("Error\nThe map error.\n", data);
		free_gnl(fd, &trimmed, &line);
	}
	if (xpm_check(trimmed, data) || color_line_check(trimmed, data))
		free_gnl(fd, &trimmed, &line);
	free(line);
	free(trimmed);
}

char	*check_is_digit_and_trim(char *rgb_part, t_data *data)
{
	int		j;
	char	*trimmed;

	trimmed = ft_strtrim(rgb_part, " \n");
	j = 0;
	while (trimmed[j])
	{
		if (!ft_isdigit(trimmed[j]))
		{
			free(trimmed);
			ft_texture_error("Error\nRGB values must be digits.\n", data);
			return (NULL);
		}
		j++;
	}
	return (trimmed);
}
