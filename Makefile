NAME = fdf

LIST = main.c main_two.c ft_create_map.c draw.c draw_two.c utils_one.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(patsubst %.c, %.o, $(LIST))

HEAD = fdf.h

DIR = ./libft_finish

DIR_LIB = ./minilibx_macos

LIB = libft_finish/libft.a

MINILIB = minilibx_macos/libmlx.a

all	: $(NAME)

$(NAME)	: $(OBJ) $(HEAD)
	$(MAKE) -C $(DIR_LIB)
	$(MAKE) -C $(DIR)
	gcc -Wall -Wextra -Werror $(LIB) $(MINILIB) $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)

%.o	: %.c
	gcc $(FLAGS) -c $< -o $@

clean	:
	$(MAKE) clean -C $(DIR_LIB)
	$(MAKE) clean -C $(DIR)
	rm -f $(OBJ)

fclean	: clean
	$(MAKE) fclean -C $(DIR)
	rm -f $(NAME)

re	 : fclean all

.PHONY	: all clean fclean re