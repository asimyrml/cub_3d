/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:14 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:16 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	free_getnextline(int fd)
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

int	check_lines(char *line)
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
	check_map_edges(data);
	check_under_space(data, -1, data->map->row);
	check_above_space(data, (data->map->row - 1));
	check_left_space(data, -1);
	check_right_space(data, -1);
	check_fields(data, -1);
}

void	handle_lines(char *line, t_data *data, int fd)
{
	char	*clean_line;

	clean_line = ft_strtrim(line, " \n");
	txt_count(clean_line, data);
	if (clean_line[0] == '1' && (data->parse->parse_no == 0
			|| data->parse->parse_so == 0 || data->parse->parse_we == 0
			|| data->parse->parse_ea == 0 || data->parse->parse_c == 0
			|| data->parse->parse_f == 0))
	{
		ft_texture_error("Error\nThe map error.\n", data);
		free_gnl(fd, &clean_line, &line);
	}
	if (xpm_check(clean_line, data) || color_line_check(clean_line, data))
		free_gnl(fd, &clean_line, &line);
	free(line);
	free(clean_line);
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
