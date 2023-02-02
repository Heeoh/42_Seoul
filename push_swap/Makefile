
# ---------------------------------- NAME ------------------------------------ #

NAME = push_swap

# ------------------------------- DIRECTORIES -------------------------------- #

LIBFT_DIR	= library/libft/
#PRINTF_DIR
HDRS_DIR	= headers/
SRCS_DIR	= sources/
OBJS_DIR	= objects/

# ---------------------------------- FILES ----------------------------------- #

LIBS = $(LIBFT_DIR)libft.a
INCLUDE = -I $(HDRS_DIR) -I $(LIBFT_DIR)
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS += $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

# -------------------------------- COMPILATE --------------------------------- #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf
MD		= mkdir -p 
AR		= ar -rcs

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: 
	make bonus -C $(LIBFT_DIR)
	make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean:
	make clean
	$(RM) $(LIBS) $(NAME) 

re:
	make fclean
	make all

.PHONY:		all clean fclean re