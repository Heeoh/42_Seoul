CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

HEADERS = headers
SRCS = $(wildcard *_utils.c) $(wildcard utils/*.c)
SRCS_MAN = $(wildcard *_man.c) 
SRCS_BONUS = $(wildcard *_bonus.c)
OBJS = $(SRCS:.c=.o)
OBJS_MAN = $(SRCS_MAN:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef ADD_BONUS
		OBJECTS = $(OBJS) $(OBJS_BONUS)
else
		OBJECTS = $(OBJS) $(OBJS_MAN) 
endif

%o : %c
		$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME) : $(OBJECTS)
		ar -crs $@ $(OBJECTS)

bonus :
		make ADD_BONUS=1 
		make all

all : $(NAME)

clean :
		rm -rf $(OBJS) $(OBJS_MAN) $(OBJS_BONUS)

fclean : clean
		rm -rf $(NAME)
re :
	make fclean 
	make all

.PHONY : all clean fclean re bonus
