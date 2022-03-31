NAME = cub3D

SRC = srcs/main.c \
      srcs/utils/init.c \
      srcs/utils/free_all.c \
      srcs/utils/utils.c \
      srcs/parsing/utils.c \
      srcs/parsing/utils2.c \
      srcs/parsing/get_info.c \
      srcs/parsing/get_textures.c \
      srcs/parsing/get_map.c \




LIBFT = -L./libft -lft
MLX = -L./mlx -lmlx -lXext -lX11 -lm

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = rm -rf
INC = -Icub3d.h
OBJ = $(SRC:.c=.o)
DIROBJ = objs/
DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

all: LIBFT MLX $(NAME)

LIBFT:
	@$(MAKE) -C libft/

MLX:
	@$(MAKE) -C mlx/

$(DIROBJ)%.o: %.c
	@mkdir -p $(dir $@)
	@echo Compiling: $<
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(DIROBJS)
	@echo Creating executable $(NAME)
	@$(CC) $(DIROBJS) $(CFLAGS) -o $(NAME) $(INC) $(LIBFT) $(MLX)

clean:
	@$(RM) $(DIROBJ)
	@$(MAKE) clean -C libft/
	@$(MAKE) clean -C mlx/

fclean: clean
	@$(MAKE) fclean -C libft/
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

