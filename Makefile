# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 13:25:43 by csilva            #+#    #+#              #
#    Updated: 2025/11/12 11:13:09 by csilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = ./Libft/ft_strjoin.o \
		./Libft/ft_atoi.o \
		./Libft/ft_strtrim.o \
		./Libft/ft_bzero.o \
		./Libft/ft_lstnew.o \
		./Libft/ft_calloc.o \
		./Libft/ft_isalnum.o \
		./Libft/ft_isalpha.o \
		./Libft/ft_isascii.o \
		./Libft/ft_isdigit.o \
		./Libft/ft_isprint.o \
		./Libft/ft_memchr.o \
		./Libft/ft_memcmp.o \
		./Libft/ft_memcpy.o \
		./Libft/ft_memmove.o \
		./Libft/ft_memset.o \
		./Libft/ft_strchr.o \
		./Libft/ft_strdup.o \
		./Libft/ft_strlcat.o \
		./Libft/ft_strlcpy.o \
		./Libft/ft_strlen.o \
		./Libft/ft_strncmp.o \
		./Libft/ft_strnstr.o \
		./Libft/ft_strrchr.o \
		./Libft/ft_tolower.o \
		./Libft/ft_toupper.o \
		./Libft/ft_substr.o \
		./Libft/ft_split.o \
		./Libft/ft_itoa.o \
		./Libft/ft_strmapi.o \
		./Libft/ft_striteri.o \
		./Libft/ft_putchar_fd.o \
		./Libft/ft_putstr_fd.o \
		./Libft/ft_putendl_fd.o \
		./Libft/ft_putnbr_fd.o \
		./Libft/ft_lstadd_front.o \
		./Libft/ft_lstsize.o \
		./Libft/ft_lstlast.o \
		./Libft/ft_lstadd_back.o \
		./Libft/ft_lstdelone.o \
		./Libft/ft_lstclear.o \
		./Libft/ft_lstiter.o \
		./Libft/ft_lstmap.o


all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C Libft
	$(AR) $(NAME) $(OBJ) $(OBJ_LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C Libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re