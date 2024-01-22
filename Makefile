# Necessities:
NAME	:= client server

LIBFT	:= ft
LFT_DIR	:= libft

SRC_DIR	:= srcs
INC_DIR	:= includes

INCX	:= minitalk.h stdlog.h
INCXX	:= $(addprefix $(INC_DIR)/, $(INCXX))
INC		:= $(LFT_DIR)/$(INC_DIR) $(INC_DIR)
SRV_SRC	:= server.c
CLT_SRC	:= client.c
SRC		:= utils.c
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRC))
SRV_SRCS:= $(addprefix $(SRC_DIR)/server/, $(SRV_SRC))
SRV_BNUS:= $(SRV_SRCS:.c=_bonus.c)
CLT_SRCS:= $(addprefix $(SRC_DIR)/client/, $(CLT_SRC))
CLT_BNUS:= $(CLT_SRCS:.c=_bonus.c)
INCLUDES:= $(addprefix -I, $(INC))

# Compiler:
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g3 -L$(LFT_DIR) -l$(LIBFT)

# Rules:
all: $(NAME)

$(NAME): $(INCXX) $(SRV_SRCS) $(CLT_SRCS) $(SRCS)
	@make -C $(LFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRV_SRCS) $(SRCS) -o server
	$(CC) $(CFLAGS) $(INCLUDES) $(CLT_SRCS) $(SRCS) -o client

bonus: $(INCXX) $(SRV_BNUS) $(CLT_BNUS) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRV_BNUS) $(SRCS) -o server
	$(CC) $(CFLAGS) $(INCLUDES) $(CLT_BNUS) $(SRCS) -o client

clean:
	@make -C $(LFT_DIR) clean

fclean:
	@make -C $(LFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus