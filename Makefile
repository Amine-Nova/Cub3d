NAME = Cub3D
NAME_BONUS = Cub3D_bonus

CC = gcc

FLAG = -framework Cocoa -framework OpenGL -framework IOKit 

CFLAGS = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address

SRC = main.c cub_utils.c map_set2D.c check_errors.c read_maps.c tools.c horizental_inter.c\
	  vertical_inter.c horiverti_inter_utils.c move_player.c start_3d.c map_set2D_2.c set_2d.c \
	  tools2.c cub3d.c

SRC_BONUS = main.c map_set_bonus.c cub_utils.c check_errors.c read_maps.c tools.c horizental_inter.c\
	  vertical_inter.c horiverti_inter_utils.c start_3d.c map_set2D_2.c set_2d.c \
	  tools2.c map_set_bonus.c move_player_bonus.c cub3d.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ)
	cd libft && make
	$(CC)  $(CFLAGS)  $(FLAG)  MLX/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $^ -o $(NAME) ./libft/libft.a

$(NAME_BONUS) : $(OBJ_BONUS)
	cd libft && make
	$(CC)  $(CFLAGS)  $(FLAG)  MLX/libmlx42.a -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" $^ -o $(NAME_BONUS) ./libft/libft.a

clean :
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@make clean -C ./libft

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C ./libft

re : fclean all 
