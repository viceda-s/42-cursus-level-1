# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 18:12:10 by viceda-s          #+#    #+#              #
#    Updated: 2025/06/25 21:20:46 by viceda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME			= libftprintf.a

# Mandatory sources
MANDATORY_SRCS	= ft_printf.c \
				ft_printf_utils.c \
				ft_printf_numbers.c

# Bonus sources
BONUS_SRCS		= ft_printf_bonus.c \
				ft_printf_parse_bonus.c \
				ft_printf_format_bonus.c \
				ft_printf_char_str_bonus.c \
				ft_printf_numbers_bonus.c \
				ft_printf_utils_bonus.c \
				ft_printf_int_bonus.c \
				ft_printf_uint_bonus.c \
				ft_printf_hex_bonus.c

# Objects
MANDATORY_OBJS	= $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

# Compiler and flags
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar
ARFLAGS			= rcs
RM				= rm -f

# Default target
all: bonus

# Mandatory library
$(NAME): $(MANDATORY_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(MANDATORY_OBJS)

# Bonus target
bonus: $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

# Object file compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)

# Full clean
fclean: clean
	$(RM) $(NAME)

# Rebuild
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re
