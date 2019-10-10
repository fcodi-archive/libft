# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2019/10/10 19:39:29 by fcodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean obj

.SUFFIXES:
.SUFFIXES: .c .h .o .a

.SECONDARY: $(OBJ)

override ARFLAGS = rcs

ifeq ($(findstring -Wall -Werror -Wextra -I., $(CFLAGS)),)
override CFLAGS += -Wall -Werror -Wextra -I.
endif

override CC = gcc

NAME = libft.a

SRC =   ft_astr_del.c \
        ft_atoi_base.c \
        ft_astr_put.c \
        ft_astr_new.c \
        ft_atollu_base.c \
        ft_astr_fill_c.c \
        ft_atol_base.c \
        ft_atoll_base.c \
        ft_atoi.c \
        ft_atolu_base.c \
        ft_atou_base.c \
        ft_atox_utils.c \
        ft_garbage_collector.c \
        ft_bzero.c \
        ft_gc_parray.c \
        ft_memcpy.c \
        ft_putchar_fd.c \
        ft_putendl_fd.c \
        ft_uintlen.c \
        ft_strlen.c \
        ft_putstr.c \
        ft_toupper.c \
        ft_isspace.c \
        ft_isascii.c \
        ft_strequ.c \
        ft_putnbr.c \
        ft_striter.c \
        ft_isupper.c \
        ft_islower.c \
        ft_strclr.c \
        ft_lstdelone.c \
        get_next_line.c \
        ft_lstdel.c \
        ft_strchr.c \
        ft_isalpha.c \
        ft_lstiter.c \
        ft_lstnew.c \
        ft_isalnum.c \
        ft_strcpy.c \
        ft_strnstr.c \
        ft_itoa.c \
        ft_memccpy.c \
        ft_putendl.c \
        ft_strsplit.c \
        ft_strrchr.c \
        ft_gc_utils.c \
        ft_strncat.c \
        ft_strmap.c \
        ft_strsub.c \
        ft_isdigit.c \
        ft_strnchri.c \
        ft_strdel.c \
        ft_strstr.c \
        ft_strcat.c \
        ft_strdup.c \
        ft_putnbr_fd.c \
        ft_strcmp.c \
        ft_tolower.c \
        ft_memalloc.c \
        ft_strnew.c \
        ft_strjoin.c \
        ft_strnequ.c \
        ft_strncpy.c \
        ft_strlenc.c \
        ft_putchar.c \
        ft_nsym.c \
        ft_strnlen.c \
        ft_strmapi.c \
        ft_strtrim.c \
        ft_putstr_fd.c \
        ft_strlcat.c \
        ft_memdel.c \
        ft_isprint.c \
        ft_memset.c \
        ft_strncmp.c \
        ft_memmove.c \
        ft_lstmap.c \
        ft_striteri.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_lstadd.c

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
