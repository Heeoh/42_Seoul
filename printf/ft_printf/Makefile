CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

HEADERS = headers
SRCS = $(wildcard *_utils.c) $(wildcard utils/*.c)
SRCS_MAN = $(wildcard *_man.c) 
OBJS = $(SRCS:.c=.o)
OBJS_MAN = $(SRCS_MAN:.c=.o)

OBJECTS = $(OBJS) $(OBJS_MAN) 

%o : %c
		$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME) : $(OBJECTS)
		ar -crs $@ $(OBJECTS)

all : $(NAME)

clean :
		rm -rf $(OBJS) $(OBJS_MAN) 

fclean : clean
		rm -rf $(NAME)
re :
	make fclean 
	make all

.PHONY : all clean fclean re bonus
