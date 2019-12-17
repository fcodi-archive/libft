# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2019/12/17 20:03:17 by fcodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean
.SECONDARY: $(OBJ)

NAME = libft.a
SRC = ft_isprint.c ft_lstnew.c ft_memmove.c ft_putnbr_fd.c ft_strcpy.c \
		ft_strlcat.c ft_strnequ.c ft_strsub.c ft_atoi.c ft_itoa.c \
		ft_memalloc.c ft_memset.c ft_putstr.c ft_strdel.c ft_strlen.c \
		ft_strnew.c ft_strtrim.c ft_bzero.c ft_lstadd.c ft_memccpy.c \
		ft_putchar.c ft_putstr_fd.c ft_strdup.c ft_strmap.c ft_strnlen.c \
		ft_tolower.c ft_isalnum.c ft_lstdel.c ft_memchr.c ft_putchar_fd.c \
		ft_strcat.c ft_strequ.c ft_strmapi.c ft_strnstr.c ft_toupper.c \
		ft_isalpha.c ft_lstdelone.c ft_memcmp.c ft_putendl.c ft_strchr.c \
		ft_striter.c ft_strncat.c ft_strrchr.c ft_isascii.c ft_lstiter.c \
		ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_striteri.c ft_strncmp.c \
		ft_strsplit.c ft_isdigit.c ft_lstmap.c ft_memdel.c ft_putnbr.c \
		ft_strcmp.c ft_strjoin.c ft_strncpy.c ft_strstr.c ft_astrdel.c \
		ft_islower.c ft_isspace.c ft_isupper.c ft_uintlen.c
OBJ = $(SRC:.c=.o)
override CFLAGS = -Wall -Wextra -Werror
override ARFLAGS = rcs
override CC = gcc

all: $(NAME)

$(NAME): $(NAME)($(OBJ))

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all