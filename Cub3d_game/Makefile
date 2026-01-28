CC = gcc

CFLAGS = -I./minilibx_linux -lm 

LDFLAGS = -L./minilibx_linux -lmlx -lX11 -lXext -lpthread  

TARGET = CUB3D

SRC = cube.c rendering.c keys_handling.c utils_2.c clean_mem.c vectors2.c raycasting2.c raycasting3.c rendering2.c raycasting.c ft_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	player_utils.c vectors.c textures.c \
	parsing/cheak_textures.c parsing/check_map.c parsing/utils2.c parsing/check_rgb.c parsing/file_read.c parsing/ft_split.c parsing/help_function.c parsing/parsing.c parsing/read_fd.c parsing/read_utils.c parsing/utils.c

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean $(TARGET)

.PHONY: clean fclean re
