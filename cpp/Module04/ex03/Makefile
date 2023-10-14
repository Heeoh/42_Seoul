# ---------------------------------- NAME ------------------------------------ #

NAME = heson

# ---------------------------------- COLOR ----------------------------------- #

C_BLUE=\033[0;34m
C_GREEN=\033[0;32m
C_YELLOW=\033[0;33m
C_RED=\033[0;31m
C_END=\033[0m

# ------------------------------- DIRECTORIES -------------------------------- #

# HDRS_DIR      = headers/
# SRCS_DIR      = sources/
OBJS_DIR        = objects/

# ---------------------------------- FILES ----------------------------------- #

# INCLUDE = -I $(HDRS_DIR)
HDRS = AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# -------------------------------- COMPILATE --------------------------------- #

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf
MD		= mkdir -p 

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o : %.cpp $(HDRS)
	@$(MD) $(dir $@)
	$(CC) $(CFLAGS) -g -c $< -o $@

all:
	@echo "$(C_YELLOW)======== make heson =======$(C_END)"
	@make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -o $(NAME)
	@echo "$(C_GREEN)+-------------------------+"
	@echo "$(C_GREEN)|        COMPLETE         |"
	@echo "$(C_GREEN)+-------------------------+$(C_END)"

clean:
	@echo "$(C_YELLOW)========= cleaning ========$(C_END)"
	$(RM) $(OBJS_DIR)

fclean: clean
	@echo "$(C_YELLOW)====== cleaning heson =====$(C_END)"
	$(RM) $(NAME)

re:
	@echo "$(C_YELLOW)======= recompiling =======$(C_END)"
	@make fclean
	@make all

.PHONY: all clean fclean re