
# ---------------------------------- NAME ------------------------------------ #

NAME = libftprintf.a

# ------------------------------- DIRECTORIES -------------------------------- #

HDRS_DIR = headers/
OBJS_DIR = objects/

# ---------------------------------- FILES ----------------------------------- #

SRCS = $(wildcard *_utils.c) $(wildcard utils/*.c)
SRCS_MAN = $(wildcard *_man.c) 
SRCS_BONUS = $(wildcard *_bonus.c)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_MAN = $(addprefix $(OBJS_DIR), $(SRCS_MAN:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

ifdef ADD_BONUS
		OBJECTS = $(OBJS) $(OBJS_BONUS)
else
		OBJECTS = $(OBJS) $(OBJS_MAN) 
endif

# -------------------------------- COMPILATE --------------------------------- #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar -rcs
MD		= mkdir -p
RM		= rm -rf

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%o : %c
		$(MD) $(dir $@)
		$(CC) $(CFLAGS) -I $(HDRS_DIR) -c $< -o $@

$(NAME) : $(OBJECTS)
		$(AR) $@ $(OBJECTS)

bonus :
		make ADD_BONUS=1 
		make all

all : $(NAME)

clean :
		$(RM) $(OBJECTS) $(OBJS_DIR)

fclean : clean
		$(RM) $(NAME)

re :
	make fclean 
	make all

.PHONY : all clean fclean re bonus
