# names
NAME := libftprintf.a

AR := ar -crs

RM := rm -rf

CC := gcc

CFLAGS := -Wall -Werror -Wextra

# directories
INCLUDE := includes/

SRCS_DIR := srcs/

# necessary files
SRCS := ft_printf.c

SRCS := $(addprefix $(SRCS_DIR), $(SRCS))

OBJS := $(SRCS:.c=.o)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
