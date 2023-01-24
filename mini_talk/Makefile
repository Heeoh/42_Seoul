
# ---------------------------------- NAME ------------------------------------ #

NAME				= minitalk
NAME_CLIENT			= client
NAME_SERVER			= server
NAME_BONUS			= minitalk_bonus
NAME_CLIENT_BONUS	= client_bonus
NAME_SERVER_BONUS	= server_bonus


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

SRCS_CLIENT_BONUS = client_bonus.c
SRCS_SERVER_BONUS = server_bonus.c

OBJS_CLIENT_BONUS = $(addprefix $(OBJS_DIR), $(SRCS_CLIENT_BONUS:.c=.o))
OBJS_SERVER_BONUS = $(addprefix $(OBJS_DIR), $(SRCS_SERVER_BONUS:.c=.o))


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

bonus:
		make $(NAME_BONUS)
	

$(NAME):
		make -C $(LIBFT_DIR)
		make -C $(PRINTF_DIR)
		make $(NAME_CLIENT) 
		make $(NAME_SERVER)	

$(NAME_CLIENT): $(OBJS_CLIENT)
		$(CC) $(CFLAGS) $< $(LIBS) -o $@

$(NAME_SERVER): $(OBJS_SERVER)
		$(CC) $(CFLAGS) $< $(LIBS) -o $@


$(NAME_BONUS):
		make -C $(LIBFT_DIR)
		make -C $(PRINTF_DIR)
		make $(NAME_CLIENT_BONUS) 
		make $(NAME_SERVER_BONUS)	

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
		$(CC) $(CFLAGS) $< $(LIBS) -o $@

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
		$(CC) $(CFLAGS) $< $(LIBS) -o $@


clean:		
		make clean -C $(LIBFT_DIR)
		make clean -C $(PRINTF_DIR)
		$(RM) $(OBJS_DIR)

fclean:
		make clean
		make fclean -C $(LIBFT_DIR)
		make fclean -C $(PRINTF_DIR)
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)	

re:
		make  fclean 
		make  all

.PHONY:		all clean fclean re