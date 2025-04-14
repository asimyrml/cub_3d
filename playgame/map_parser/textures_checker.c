/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:45:29 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:45:30 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	txt_count(char *trimmed, t_data *data)
{
	if (trimmed[0] == 'N' && trimmed[1] == 'O' && trimmed[2] == ' ')
		data->parse->parse_no++;
	else if (trimmed[0] == 'S' && trimmed[1] == 'O' && trimmed[2] == ' ')
		data->parse->parse_so++;
	else if (trimmed[0] == 'W' && trimmed[1] == 'E' && trimmed[2] == ' ')
		data->parse->parse_we++;
	else if (trimmed[0] == 'E' && trimmed[1] == 'A' && trimmed[2] == ' ')
		data->parse->parse_ea++;
	else if (trimmed[0] == 'C' && trimmed[1] == ' ')
		data->parse->parse_c++;
	else if (trimmed[0] == 'F' && trimmed[1] == ' ')
		data->parse->parse_f++;
}

void	txt_count_check(t_data *data)
{
	if (data->parse->parse_no != 1 || data->parse->parse_so != 1
		|| data->parse->parse_we != 1 || data->parse->parse_ea != 1
		|| data->parse->parse_c != 1 || data->parse->parse_f != 1)
		ft_malloc_error("Error\nThe wrong number of textures.\n", data);
}

void	free_gnl(int fd, char **trimmed, char **line)
{
	free(*line);
	free(*trimmed);
	free_getnextline(fd);
	exit(1);
}

void	txt_check_2(char *av, t_data *data, int fd)
{
	char	*line;

	init_parse(data);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_texture_error("Error\nFile could not be opened\n", data);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		handle_lines(line, data, fd);
	}
	close(fd);
}

void	txt_check(char *av, t_data *data)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		trimmed = ft_strtrim(line, " ");
		if (trimmed && trimmed[0] != 'C' && trimmed[0] != 'S'
			&& trimmed[0] != 'N' && trimmed[0] != 'W' && trimmed[0] != 'F'
			&& trimmed[0] != 'E' && trimmed[0] != '1' && trimmed[0] != '\n'
			&& trimmed[0] != '\0')
		{
			ft_texture_error("Error\nThe map error.\n", data);
			free_gnl(fd, &trimmed, &line);
		}
		txt_count(trimmed, data);
		free(line);
		free(trimmed);
	}
	close(fd);
	txt_count_check(data);
}
