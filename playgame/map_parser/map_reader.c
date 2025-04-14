/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:10 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:11 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	copy_map(char *av, t_data *data, int map_start)
{
	int		line_index;
	int		row_index;
	int		fd;
	char	*line;

	line_index = -1;
	fd = open(av, O_RDONLY);
	while (++line_index < map_start)
	{
		line = get_next_line(fd);
		free(line);
	}
	row_index = -1;
	while (++row_index < data->map->row)
		data->map->clone_map[row_index] = get_next_line(fd);
	data->map->clone_map[row_index] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
}

void	map(char *av, t_data *data, int map_start, int i)
{
	int		j;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	init_map(data);
	while (++i < map_start)
	{
		line = get_next_line(fd);
		free(line);
	}
	j = -1;
	while (++j < data->map->row)
		data->map->map[j] = get_next_line(fd);
	data->map->map[j] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	copy_map(av, data, map_start);
}

int	skip_texture(char **line, char **trimmed, t_data *data, int *i)
{
	if (*trimmed[0] == 'C' || *trimmed[0] == 'S' || *trimmed[0] == 'N'
		|| *trimmed[0] == 'W' || *trimmed[0] == 'F' || *trimmed[0] == 'E'
		|| (*trimmed[0] == '\n' && data->map->row == 0))
	{
		(*i)++;
		free(*trimmed);
		free(*line);
		return (1);
	}
	return (0);
}

void	mltp_map_checker(int fd, t_data *data)
{
	char	*line;
	int		flg;

	flg = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, " ", ft_strlen(line)) != 0 || *line == '\n')
			flg = 1;
		if (flg && check_lines(line))
			ft_error("Error\nMultiple map.\n", data);
		free(line);
	}
	close(fd);
	if (data->map->row == 0)
		ft_error("Error\nThere is no map.\n", data);
}

void	map_check(char *av, t_data *data, char *line, char *trimmed)
{
	int	fd;
	int	i;

	fd = open(av, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " ");
		if (skip_texture(&line, &trimmed, data, &i))
			continue ;
		if (trimmed[0] == '\n' && data->map->row != 0)
		{
			free(trimmed);
			free(line);
			break ;
		}
		data->map->row++;
		free(trimmed);
		free(line);
	}
	mltp_map_checker(fd, data);
	map(av, data, i, -1);
}
