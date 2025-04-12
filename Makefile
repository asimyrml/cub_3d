NAME = cub3D
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLXFLAGS = -Llib/mlx_linux -lmlx -L/usr/lib -Ilib/mlx_linux -lXext -lX11 -lm -lz

LIBFT = lib/libft/libft.a
LIBSRC = lib/libft/ft_atoi.c lib/libft/ft_bzero.c lib/libft/ft_calloc.c lib/libft/ft_isalnum.c \
         lib/libft/ft_isalpha.c lib/libft/ft_isascii.c lib/libft/ft_isdigit.c lib/libft/ft_isprint.c \
         lib/libft/ft_itoa.c lib/libft/ft_memchr.c lib/libft/ft_memcmp.c lib/libft/ft_memcpy.c \
         lib/libft/ft_memmove.c lib/libft/ft_memset.c lib/libft/ft_putchar_fd.c lib/libft/ft_putendl_fd.c \
         lib/libft/ft_putnbr_fd.c lib/libft/ft_putstr_fd.c lib/libft/ft_split.c lib/libft/ft_strchr.c \
         lib/libft/ft_strdup.c lib/libft/ft_striteri.c lib/libft/ft_strjoin.c lib/libft/ft_strlcat.c \
         lib/libft/ft_strlcpy.c lib/libft/ft_strlen.c lib/libft/ft_strmapi.c lib/libft/ft_strncmp.c \
         lib/libft/ft_strnstr.c lib/libft/ft_strrchr.c lib/libft/ft_strtrim.c lib/libft/ft_substr.c \
         lib/libft/ft_toupper.c lib/libft/ft_tolower.c

C_SRC = lib/GNL/get_next_line.c cub3d.c \
            playgame/initialize/init.c playgame/initialize/game.c \
            playgame/map_parser/flood_fill.c playgame/map_parser/map_check.c playgame/map_parser/map_reader.c \
            playgame/map_parser/map_utils.c playgame/map_parser/player_position.c playgame/map_parser/rgb_validator.c \
            playgame/map_parser/textures_checker.c playgame/map_parser/xpm_checker.c \
            playgame/movement/key_handler.c playgame/movement/move.c \
            playgame/utils/error.c playgame/utils/free.c \
            playgame/view/handle_direction.c playgame/view/raycasting.c playgame/view/set_images.c \

MLX = lib/mlx_linux/libmlx.a
SRCS = $(LIBSRC) $(C_SRC)
OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(LIBFT) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLXFLAGS)

$(MLX):
	make -C lib/mlx_linux


$(LIBFT):
	make -C lib/libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C lib/libft clean

fclean: clean
	rm -f $(NAME)
	make -C lib/libft fclean

re: fclean all

.PHONY: all clean fclean re
