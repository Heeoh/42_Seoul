
# ---------------------------------- NAME ------------------------------------ #

NAME = philo

# ---------------------------------- COLOR ----------------------------------- #

C_BLUE=\033[0;34m
C_GREEN=\033[0;32m
C_YELLOW=\033[0;33m
C_RED=\033[0;31m
C_END=\033[0m

# ------------------------------- DIRECTORIES -------------------------------- #

# HDRS_DIR	= headers/
# SRCS_DIR	= sources/
OBJS_DIR	= objects/

# ---------------------------------- FILES ----------------------------------- #

INCLUDE = -I philo.h 
SRCS = $(wildcard *.c)
OBJS += $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

# -------------------------------- COMPILATE --------------------------------- #

CFLAGS	= -Wall -Werror -Wextra 
# -fsanitize=thread
RM		= rm -rf
MD		= mkdir -p 

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o : %.c
	@$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -g -c $< -o $@

all: 
	@echo "$(C_YELLOW)======= make philo ========$(C_END)"
	@make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lpthread $(OBJS) -g -o $(NAME)
	@echo "$(C_GREEN)+-------------------------+"
	@echo "$(C_GREEN)|        COMPLETE         |"
	@echo "$(C_GREEN)+-------------------------+$(C_END)"

clean:
	@echo "$(C_YELLOW)======== cleaning =========$(C_END)"
	$(RM) $(OBJS_DIR)

fclean: clean
	@echo "$(C_YELLOW)===== cleaning philo ======$(C_END)"
	$(RM) $(NAME)

re:
	@echo "$(C_YELLOW)======= recompiling =======$(C_END)"
	@make fclean
	@make all

.PHONY:		all clean fclean re