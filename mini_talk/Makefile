
# ---------------------------------- NAME ------------------------------------ #

NAME				= minitalk
NAME_CLIENT			= client
NAME_SERVER			= server

# ------------------------------- DIRECTORIES -------------------------------- #

SRCS_DIR	= sources/
INC_DIR		= headers/
LIBFT_DIR	= library/libft/
PRINTF_DIR  = library/printf/
OBJS_DIR	= objects/

# ---------------------------------- FILES ----------------------------------- #

LIBS = $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a
INCLUDE = -I $(INC_DIR) -I $(LIBFT_DIR)*.h -I $(PRINTF_DIR)headers
HDRS = $(INC_DIR)minitalk.h $(LIBS)

CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENTBONUS_SRCS = client_bonus.c
SERVERBONUS_SRCS = server_bonus.c

SRCS_CLIENT += $(addprefix $(SRCS_DIR), $(CLIENT_SRCS))
SRCS_SERVER += $(addprefix $(SRCS_DIR), $(SERVER_SRCS))

OBJS_CLIENT = $(addprefix $(OBJS_DIR), $(CLIENT_SRCS:.c=.o))
OBJS_SERVER = $(addprefix $(OBJS_DIR), $(SERVER_SRCS:.c=.o))

# DEP_CLIENT = $(addsuffix .d, $(basename $(OBJS_CLIENT)))
# DEP_SERVER = $(addsuffix .d, $(basename $(OBJS_SERVER)))

# SRCS_CLIENTBONUS += $(addprefix $(SRCS_DIR), $(CLIENTBONUS_SRCS))
# SRCS_SERVERBONUS += $(addprefix $(SRCS_DIR), $(SERVERBONUS_SRCS))

# OBJS_CLIENTBONUS = $(addprefix $(OBJS_DIR), $(CLIENTBONUS_SRCS:.c=.o))
# OBJS_SERVERBONUS = $(addprefix $(OBJS_DIR), $(SERVERBONUS_SRCS:.c=.o))

# DEP_CLIENTBONUS = $(addsuffix .d, $(basename $(OBJS_CLIENTBONUS)))
# DEP_SERVERBONUS = $(addsuffix .d, $(basename $(OBJS_SERVERBONUS)))

# -------------------------------- COMPILATE --------------------------------- #

CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar -rcs
MD		= mkdir -p
CP		= cp -f
CC		= gcc

# --------------------------------- RULES ------------------------------------ #

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@	

all:	
		@$(MAKE) -C $(LIBFT_DIR)
		@$(MAKE) -C $(PRINTF_DIR)
		@$(MAKE) $(NAME)


$(NAME):		
		@$(MAKE) $(NAME_CLIENT)
		@$(MAKE) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBS) -o $(NAME_CLIENT)
# @echo "$(GREEN) Client compilado!$(DEF_COLOR)"

$(NAME_SERVER): $(OBJS_SERVER) $(HDRS)	
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBS) -o $(NAME_SERVER)
# @echo "$(GREEN) Server compilado!$(DEF_COLOR)"
# @touch $@

$(NAME_CLIENTBONUS): $(OBJS_CLIENTBONUS) $(HDRS) 
	$(CC) $(CFLAGS) $(OBJS_CLIENTBONUS) $(LIBS) -o $(NAME_CLIENTBONUS)
# @echo "$(GREEN) Client Bonus compilado!$(DEF_COLOR)"
# @touch $@

$(NAME_SERVERBONUS): $(OBJS_SERVERBONUS) $(HDRS)	
	$(CC) $(CFLAGS) $(OBJS_SERVERBONUS) $(LIBS) -o $(NAME_SERVERBONUS)
# @echo "$(GREEN) Server Bonus compilado!$(DEF_COLOR)"
# @touch $@

# -include $(DEP_CLIENT)
# -include $(DEP_SERVER)

# -include $(DEP_CLIENTBONUS)
# -include $(DEP_SERVERBONUS)

clean:		
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@$(RM) -rf $(OBJS_DIR)
# @$(RM) $(DEP)
# @echo "$(RED)Borrando objetos... $(DEF_COLOR)"

fclean:
	@$(MAKE) clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(RM) $(NAME) $(NAME_CLIENT) $(NAME_SERVER) 
# @echo "$(RED)Borrando archivos...$(DEF_COLOR)"

re:
	@$(MAKE)  fclean 
	@$(MAKE)  all
# @echo ""
# @echo "$(GREEN) Borrado y recompilado$(DEF_COLOR)"

.PHONY:		all clean fclean re