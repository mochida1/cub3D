NAME = cub3D
NAME_FS = cub3D_fs
NAME_TEST = test
MAKEFLAGS = --no-print-directory
BUILDDIR = objs
LIBFT_DIR = libft
LLIBS =  -lmlx -lXext -lX11
LIBFT = $(LIBFT_DIR)/libft.a
VPATH = src tests src/utils src/main src/map_utils src/actions src/image \
src/cleanup src/raycasting

# headers
INCLUDES = -I ./headers

# Lists sources. Manually because of norm...
MAIN		=	main.c
UTILS		=	safe_free.c ft_strcmp.c ft_split_spaces.c int_strrchr.c
MAP_UTILS	=	init_map.c map_disassemble.c get_map_raw_layout.c \
				get_raw_map_settings.c get_settings.c map_validation.c \
				map_checks.c map_checks_line.c get_settings_utils.c
PARSING		=	input_parsing.c
ACTIONS		= 	key_esc.c mlx_keymap.c event_handler.c colision.c key_wasd.c \
				key_lr.c
IMAGE		=	putpix.c putsquare.c render_images.c image_draw0.c image_list.c\
				texture.c
CLEANUP		=	freedom.c
RAYCASTING	=	ray00.c ray01.c draw_walls.c ray_moves.c initial_dir.c \
				draw_walls_utils.c get_texture.c
TEST_LIST	=

# Names sources

SOURCES =	$(MAIN) $(UTILS) $(MAP_UTILS) $(PARSING) $(ACTIONS) $(IMAGE) \
			$(RAYCASTING) $(CLEANUP)\
			$(TEST_LIST)

# Names objects
OBJS = $(addprefix $(BUILDDIR)/, $(SOURCES:%.c=%.o))

# Compiler
CC = clang
CF = -Wall -Wextra -Werror
GDB = -ggdb
VAL = clear && valgrind --trace-children=no --leak-check=full \
		--track-origins=yes --show-leak-kinds=all ./$(NAME) maps/stop.cub
FSF = -fsanitize=address

$(NAME): $(LIBFT) $(BUILDDIR) $(OBJS)
	@printf "Compiling cub3D...\n"
	@$(CC) $(CF) $(OBJS) $(INCLUDES) $(LIBFT) $(LLIBS) -o $(NAME)
	@printf "Done!\n"

$(NAME_FS): $(LIBFT) $(OBJS)
	@$(CC) $(CF) $(FSF) $(OBJS) $(INCLUDES) $(LIBFT) $(LLIBS) -o $(NAME_FS)

$(NAME_TEST): $(LIBFT) $(TEST_OBJS)
	@printf "Compiling test files...\n"
	@$(CC) $(CF) $(TEST_OBJS) $(INCLUDES) $(LIBFT) -o $(NAME_TEST)

$(LIBFT):
	@printf "Compiling libft...\n"
	@make -C $(LIBFT_DIR)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.c
	@$(CC) $(CF) $(GDB) $(INCLUDES) -c $< -o $@

all: $(NAME)

fs: $(NAME_FS)

# test:
# 	@make -C tests/
# 	@printf "\n"
# 	@./tests/tester

clean:
	@rm -rf $(BUILDDIR)
	@rm -f vgcore*
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_FS)
	@rm -f vgcore*
	@make fclean -C $(LIBFT_DIR)

re: fclean all

# from here on shit ain't mandatory or bonus
run: all
	$(VAL)

fs: $(NAME_FS)
	./$(NAME_FS)

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
