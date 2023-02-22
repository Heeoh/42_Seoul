
# ---------------------------------- NAME ------------------------------------ #

NAME = so_long

# ------------------------------- DIRECTORIES -------------------------------- #

LIBFT_DIR	= library/libft/
PRINTF_DIR	= library/printf/
MLX_DIR		= mlx/
HDRS_DIR	= headers/
SRCS_DIR	= sources/
OBJS_DIR	= objects/

# ---------------------------------- FILES ----------------------------------- #

LIBS = $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a
MLX = $(MLX_DIR)libmlx.a 
INCLUDE = -I $(HDRS_DIR) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)
# INCLUDE = -I $(HDRS_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)
SRCS = $(wildcard $(SRCS_DIR)*.c)
# GNL_SRCS = $(wildcard $(SRCS_DIR)get_next_line/*.c) 
OBJS += $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
# OBJS += $(addprefix $(OBJS_DIR), $(notdir $(GNL_SRCS:.c=.o)))

# -------------------------------- COMPILATE --------------------------------- #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf
MD		= mkdir -p 
AR		= ar -rcs

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -g -c $< -o $@

all:
	make -C $(MLX_DIR)
	make bonus -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	make $(NAME)

$(NAME): $(OBJS)
	cc -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIBS) -o $(NAME)
# cc -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIBS) -o $(NAME)


clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS_DIR)

fclean:
	make clean
	make clean -C $(MLX_DIR)
	$(RM) $(LIBS) $(NAME) 
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY:		all clean fclean re