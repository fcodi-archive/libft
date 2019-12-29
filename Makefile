# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2019/12/29 14:30:57 by fcodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean obj

.SUFFIXES:
.SUFFIXES: .c  .h .o .a

.SECONDARY: $(OBJ)

override ARFLAGS = rcs

ifeq ($(findstring -Wall -Werror -Wextra -I., $(CFLAGS)),)
override CFLAGS += -Wall -Werror -Wextra -I.
endif

override CC = gcc

NAME = libft.a

SRC =	ft_astr_astr.c \
		ft_atoi.c \
		ft_astr_fill_c.c \
		ft_atol_base.c \
		ft_astr_put.c \
		ft_astr_tolower.c \
		ft_atoll_base.c \
		ft_astr_len.c \
		ft_atoi_base.c \
		ft_atou_base.c \
		ft_atollu_base.c \
		ft_astr_new.c \
		ft_astr_del.c \
		ft_atolu_base.c \
		ft_atox_utils.c \
		ft_lstiter.c \
		ft_strnlen.c \
		ft_putnbr_fd.c \
		ft_memccpy.c \
		ft_putchar_fd.c \
		ft_strrchr.c \
		ft_lstadd.c \
		ft_isalpha.c \
		ft_strjoin.c \
		ft_isdigit.c \
		ft_strlenc.c \
		ft_strdup.c \
		ft_lstdelone.c \
		ft_strncat.c \
		get_next_line.c \
		ft_lstdel.c \
		ft_tolower.c \
		ft_strsplit.c \
		ft_strncpy.c \
		ft_strcpy.c \
		ft_putstr_fd.c \
		ft_memset.c \
		ft_strtrim.c \
		ft_strchr.c \
		ft_toupper.c \
		ft_strnchri.c \
		ft_putendl.c \
		ft_uintlen.c \
		ft_strdel.c \
		ft_strcat.c \
		ft_memchr.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_putendl_fd.c \
		ft_putchar.c \
		ft_ishex.c \
		ft_striter.c \
		ft_itoa.c \
		ft_memcmp.c \
		ft_strnequ.c \
		ft_islower.c \
		ft_isupper.c \
		ft_strstr.c \
		ft_strnew.c \
		ft_nsym.c \
		ft_putnbr.c \
		ft_memdel.c \
		ft_memcpy.c \
		ft_strsub.c \
		ft_isspace.c \
		ft_isprint.c \
		ft_lstnew.c \
		ft_strclr.c \
		ft_striteri.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_lstmap.c \
		ft_strequ.c \
		ft_memalloc.c \
		ft_bzero.c \
		ft_strcmp.c \
		ft_putstr.c \
		ft_strnstr.c \
		ft_isalnum.c \
		ft_memmove.c \
		ft_strmapi.c \
		ft_isascii.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(NAME)($(OBJ))

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

obj: $(OBJ)
	$(MAKE) -C ../ LIBFT_OBJ="$(OBJ)" CFLAGS=$(CFLAGS)
