CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

HEADERS = headers
SRCS_MAN = $(wildcard *.c) $(wildcard utils/*.c)
# SRCS_BONUS = $(wildcard *_bonus.c)
OBJS_MAN = $(SRCS_MAN:.c=.o)
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJECTS = $(OBJS_MAN)

%o : %c
		$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME) : $(OBJECTS)
		ar -crs $@ $(OBJECTS)

all : $(NAME)

clean :
		rm -rf $(OBJS_MAN) $(OBJS_BONUS)

fclean : clean
		rm -rf $(NAME)
re :
	make fclean 
	make all

.PHONY : all clean fclean re bonus
