
# ---------------------------------- NAME ------------------------------------ #

NAME = philo

# ------------------------------- DIRECTORIES -------------------------------- #

# HDRS_DIR	= headers/
# SRCS_DIR	= sources/
OBJS_DIR	= objects/

# ---------------------------------- FILES ----------------------------------- #

INCLUDE = -I philo.h 
# $(HDRS_DIR)
# SRCS = $(wildcard $(SRCS_DIR)*.c)
SRCS = philo.c philo_utils.c philo_acting.c
OBJS += $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

# -------------------------------- COMPILATE --------------------------------- #

CFLAGS	= -Wall -Werror -Wextra -fsanitize=thread
RM		= rm -rf
MD		= mkdir -p 

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o : %.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -g -c $< -o $@

all:
	make $(NAME)

$(NAME): $(OBJS)
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