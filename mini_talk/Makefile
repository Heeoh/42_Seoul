
# ---------------------------------- NAME ------------------------------------ #

NAME				= minitalk
NAME_CLIENT			= client
NAME_SERVER			= server

# ------------------------------- DIRECTORIES -------------------------------- #

HDRS_DIR	= headers/
LIBFT_DIR	= library/libft/
PRINTF_DIR  = library/printf/
OBJS_DIR	= objects/

# ---------------------------------- FILES ----------------------------------- #

LIBS = $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a
INCLUDE = -I $(HDRS_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)headers

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(addprefix $(OBJS_DIR), $(SRCS_CLIENT:.c=.o))
OBJS_SERVER = $(addprefix $(OBJS_DIR), $(SRCS_SERVER:.c=.o))

# SRCS_CLIENTBONUS = $(addprefix $(SRCS_DIR), $(CLIENTBONUS_SRCS))
# SRCS_SERVERBONUS = $(addprefix $(SRCS_DIR), $(SERVERBONUS_SRCS))

# OBJS_CLIENTBONUS = $(addprefix $(OBJS_DIR), $(CLIENTBONUS_SRCS:.c=.o))
# OBJS_SERVERBONUS = $(addprefix $(OBJS_DIR), $(SERVERBONUS_SRCS:.c=.o))


# -------------------------------- COMPILATE --------------------------------- #

CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf
AR		= ar -rcs
MD		= mkdir -p
CC		= cc

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o:%.c 
		$(MD) $(dir $@)
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@	
	
all: 
	make $(NAME)

$(NAME):
		make -C $(LIBFT_DIR)
		make -C $(PRINTF_DIR)
		make $(NAME_CLIENT) 
		make $(NAME_SERVER)	

$(NAME_CLIENT): $(OBJS_CLIENT)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)	

clean:		
		make clean -C $(LIBFT_DIR)
		make clean -C $(PRINTF_DIR)
		$(RM) $(OBJS_DIR)

fclean:
		make clean
		make fclean -C $(LIBFT_DIR)
		make fclean -C $(PRINTF_DIR)
		$(RM) $(NAME) $(NAME_CLIENT) $(NAME_SERVER) 

re:
		make  fclean 
		make  all

.PHONY:		all clean fclean re