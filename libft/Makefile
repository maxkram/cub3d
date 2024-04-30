# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 00:12:29 by mkramer           #+#    #+#              #
#    Updated: 2024/04/30 02:13:48 by mkramer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLGS = -Wall -Wextra -Werror -Wpedantic -Wunreachable-code -Wtype-limits
COMPILE = $(CC) $(CFLGS) -c
AR = ar rucs $(NAME) $(OBJS)

SRCS	=	basic/ft_isspace.c \
			basic/ft_isdigit.c \
			basic/ft_strlen.c \
			basic/ft_bzero.c \
			basic/ft_memcpy.c \
			basic/ft_memmove.c \
			basic/ft_strlcpy.c \
			basic/ft_strlcat.c \
			basic/ft_strchr.c \
			basic/ft_strncmp.c \
			basic/ft_atoi.c \
			basic/ft_calloc.c \
			basic/ft_strdup.c \
			basic/ft_substr.c \
			basic/ft_strjoin.c \
			basic/ft_strtrim.c \
			basic/ft_split.c \
			basic/ft_putchar_fd.c \
			basic/ft_putstr_fd.c \
			basic/ft_putnbr_fd.c \
			basic/ft_strrev.c \
			basic/ft_strndup.c \
			printf/ft_printf.c \
			printf/ft_printf_utils.c \
			printf/ft_printf_spec_hex.c \
			gnl/get_next_line.c \

OBJS = $(SRCS:%.c=%.o)

.PHONY: Makefile

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(AR)

%.o: %.c
	$(COMPILE) $< -o $@

.PHONY: clean
clean:
	/bin/rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)

.PHONY: re
re: fclean all
