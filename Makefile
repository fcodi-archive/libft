# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2019/07/22 16:35:15 by fcodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

.SECONDARY: $(OBJ)

override ARFLAGS = rc

override CFLAGS = -Wall -Werror -Wextra -I.

override CC = gcc

NAME = libft.a

OBJ =   ft_isprint.o ft_lstnew.o ft_memmove.o ft_putnbr_fd.o ft_strcpy.o \
		ft_strlcat.o ft_strnequ.o ft_strsub.o ft_atoi.o ft_itoa.o \
		ft_memalloc.o ft_memset.o ft_putstr.o ft_strdel.o ft_strlen.o \
		ft_strnew.o ft_strtrim.o ft_bzero.o ft_lstadd.o ft_memccpy.o \
		ft_putchar.o ft_putstr_fd.o ft_strdup.o ft_strmap.o ft_strlenc.o \
		ft_tolower.o ft_isalnum.o ft_lstdel.o ft_memchr.o ft_putchar_fd.o \
		ft_strcat.o ft_strequ.o ft_strmapi.o ft_strnstr.o ft_toupper.o \
		ft_isalpha.o ft_lstdelone.o ft_memcmp.o ft_putendl.o ft_strchr.o \
		ft_striter.o ft_strncat.o ft_strrchr.o ft_isascii.o ft_lstiter.o \
		ft_memcpy.o ft_putendl_fd.o ft_strclr.o ft_striteri.o ft_strncmp.o \
		ft_strsplit.o ft_isdigit.o ft_lstmap.o ft_memdel.o ft_putnbr.o \
		ft_strcmp.o ft_strjoin.o ft_strncpy.o ft_strstr.o ft_nsym.o\
		ft_islower.o ft_isspace.o ft_isupper.o ft_uintlen.o get_next_line.o \
		ft_astr_new.o ft_astr_del.o ft_astr_put.o ft_strnchri.o \
		ft_astr_fill_c.o

all: $(NAME)

$(NAME): $(NAME)($(OBJ))
	ranlib $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

pclean: fclean
	$(RM)r cmake-* CMakeLists.txt README.md .DS_Store
