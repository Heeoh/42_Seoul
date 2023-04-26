
# ---------------------------------- NAME ------------------------------------ #

NAME = philo

# ------------------------------- DIRECTORIES -------------------------------- #

HDRS_DIR	= headers/
SRCS_DIR	= sources/
OBJS_DIR	= objects/

# ---------------------------------- FILES ----------------------------------- #

INCLUDE = -I $(HDRS_DIR)
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS += $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

# -------------------------------- COMPILATE --------------------------------- #

CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf
MD		= mkdir -p 

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -g -c $< -o $@

all:
	make $(NAME)

$(NAME): $(HDRS_DIR) $(OBJS)
	$(CC) $(CFLAGS) -lpthread $(OBJS) -g -o $(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY:		all clean fclean re