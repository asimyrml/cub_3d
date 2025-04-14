/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:44:35 by beyarsla          #+#    #+#             */
/*   Updated: 2025/04/14 16:44:36 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SCREEN_W 1920
# define SCREEN_H 1080

typedef struct s_parse
{
	int				parse_c;
	int				parse_f;
	int				parse_no;
	int				parse_so;
	int				parse_we;
	int				parse_ea;
}					t_parse;

typedef struct s_player
{
	double			position_x;
	double			position_y;
	double			direction_x;
	double			direction_y;
	double			view_x;
	double			view_y;
}					t_player;

typedef struct s_map
{
	char			**map;
	char			**clone_map;
	int				row;
	int				player_count;
}					t_map;

typedef struct s_textures
{
	char			**txt_floor;
	char			**txt_ceiling;
	char			*txt_north;
	char			*txt_south;
	char			*txt_west;
	char			*txt_east;
}					t_textures;

typedef struct s_game
{
	void			*mlx;
	void			*wndw;
	void			*image;
	void			*game_no;
	void			*game_so;
	void			*game_ea;
	void			*game_we;
	int				*address;
	int				*address_no;
	int				*address_so;
	int				*address_ea;
	int				*address_we;
	int				bit_size;
	int				size_line;
	int				byte_order;
	int				size;
	double			turn_speed;
	double			walk_speed;
}					t_game;

typedef struct s_raycast
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				wall_start;
	int				wall_end;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	double			wall_dist;
	double			hit_x;
	double			per_pix;
	int				tex_x;
	int				tex_y;
	double			tex_y_next;
}					t_raycasting;

typedef struct s_keys
{
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_left;
	int				key_right;
}					t_keys;

typedef struct s_data
{
	t_parse			*parse;
	t_textures		*texture;
	t_player		*player;
	t_map			*map;
	t_game			*game;
	t_raycasting	*raycast;
	t_keys			*key;
}					t_data;

void				init_parse(t_data *data);
void				init_texture(t_data *data);
void				init_map(t_data *data);
void				init_key(t_data *data);
void				init_game(t_data *data);

void				txt_check(char *av, t_data *data);
void				txt_check_2(char *av, t_data *data, int fd);
int					xpm_check(char *str, t_data *data);
int					color_line_check(char *str, t_data *data);
void				map_check(char *av, t_data *data, char *line,
						char *trimmed);
int					check_lines(char *line);
void				check_char(t_data *data);
void				bounds_check(t_data *data, int i, int j);
void				check_player_bounds(t_data *data, int i, int j);
void				check_fields(t_data *data, int i);
void				flood_fill(int x, int y, t_data *data);
void				check_floodfill(t_data *data);
void				is_map_closed(t_data *data);
void				check_map_edges(t_data *data);
void				check_above_space(t_data *data, int map_row);
void				check_under_space(t_data *data, int i, int row);
void				check_right_space(t_data *data, int i);
void				check_left_space(t_data *data, int i);

void				start_game(t_data *data);
int					put_image(t_data *data);
int					handle_keys(int key_code, t_data *data);
int					reset_keys(int key, t_data *data);
void				set_variable(t_data *data, int i);
void				calculate_step(t_data *data);
int					dda_algorithm(t_data *data);
void				set_pixel(t_data *data, int line_h, int side);
void				put_col(t_data *data, int col, int side);
void				handle_move_up(t_data *data);
void				handle_move_down(t_data *data);
void				handle_move_left(t_data *data);
void				handle_move_right(t_data *data);
void				handle_right_view(t_data *data);
void				handle_left_view(t_data *data);

void				ft_malloc_error(char *msg, t_data *data);
void				ft_texture_error(char *msg, t_data *data);
void				ft_texture_error(char *msg, t_data *data);
void				ft_error(char *msg, t_data *data);
void				destroy_mlx(t_data *data);
void				ft_full_free(t_data *data);
void				double_free(char **str);
void				free_getnextline(int fd);
void				handle_move_player(t_data *data);
char				*check_is_digit_and_trim(char *rgb_part, t_data *data);
void				handle_lines(char *line, t_data *data, int fd);
void				txt_count_check(t_data *data);
void				free_gnl(int fd, char **trimmed, char **line);
void				txt_count(char *trimmed, t_data *data);

#endif