DIR_S = src

DIR_O = objs

SOURCES = main.c \
		  bitmanipforscreen.c \
		  color.c \
		  controls.c \
		  draw.c \
		  flortexture.c \
		  ft_check_parse_and_color.c \
		  ft_error.c \
		  ft_parsing.c \
		  ft_sprit.c \
		  get_datas.c \
		  get_next_line.c \
		  get_next_line_utils.c \
		  keyparsing.c \
		  map.c \
		  raycasting.c \
		  screenshot.c \
		  sprit_pos_and_sorted.c \
		  texture.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

HEADERS = headers

LIBFT_DIR = Libft

MLX_DIR = Mlx

NAME = Cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBS = -lmlx -framework OpenGL -framework Appkit

MLX = $(addprefix $(MLX_DIR)/,libmlx.a)

LIBFT = $(addprefix $(LIBFT_DIR)/,libft.a)

all: $(LIBFT) $(MLX) $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT_DIR)
	make clean -c $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: re fclean all clean 
