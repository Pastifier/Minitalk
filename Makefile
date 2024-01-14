# Necessities:
NAME	:= client server

LIBFT	:= ft
LFT_DIR	:= libft

SRC_DIR	:= srcs
INC_DIR	:= includes

INCX	:= $(LFT_DIR)/$(INC_DIR)/libft.h 
INCXX	:= minitalk.h
INCXXX	:= $(addprefix $(INC_DIR)/, $(INCXX))
INC		:= $(LFT_DIR)/$(INC_DIR) $(INC_DIR)
SRV_SRC	:= main.c
CLT_SRC	:= main.c
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

$(NAME): $(INCX) $(INCXXX) $(SRV_SRCS) $(CLT_SRCS) $(SRCS)
	@make -C $(LFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRV_SRCS) $(SRCS) -o server
	$(CC) $(CFLAGS) $(INCLUDES) $(CLT_SRCS) $(SRCS) -o client

clean:
	@make -C $(LFT_DIR) clean

fclean:
	@make -C $(LFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re