# Necessities:
NAME := minitalk

LIBFT := ft
LFT_DIR := libft

SRC_DIR := srcs
INC_DIR := includes

INC := $(LFT_DIR)/$(INC_DIR)/libft.h $(INC_DIR)/minitalk.h
SRV_SRC := main.c
CLT_SRC := main.c
SRV_SRCS:= $(addprefix $(SRC_DIR)/server/, $(SRV_SRC))
SRV_BNUS:= $(SRV_SRCS:.c=_bonus.c)
CLT_SRCS:= $(addprefix $(SRC_DIR)/client/, $(CLT_SRC))
CLT_BNUS:= $(CLT_SRCS:.c=_bonus.c)
INCLUDES:= $(addprefix -I, $(INC))

# Compiler:
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 $(INCLUDES) -L$(LFT_DIR) -l$(LIBFT)
