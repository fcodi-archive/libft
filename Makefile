# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2020/03/05 17:10:56 by fcodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean

.SUFFIXES:
.SUFFIXES: .c .h .o .a

VPATH ?= ../$(SRC_DIR) ../$(INCLUDE_DIR) $(VPATHS)

.SECONDARY: $(OBJ)

ifneq ($(CFLAGS),-Wall -Werror -Wextra)
ifeq ($(suffix $(NAME)),.a)
override ARFLAGS = rcsU
endif
override CFLAGS += -Wall -Werror -Wextra $(INCLUDE_FLAGS)
override CC = gcc
endif

NAME ?= libft.a

PROJECT_PATH ?= $(shell pwd)

SRC ?=	ft_astr_astr.c \
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
		ft_isascii.c \
		ft_strndup.c \
		ft_write_free.c \
		ft_cpowl.c \
        ft_cabsl.c \
        ft_cdiv.c \
        ft_cadd.c \
        ft_cmul.c \
        ft_csub.c \
        twin.c \
        tview.c \
        tview_init.c \
		digits_after_dot.c \
		digits_before_dot.c \
		ft_atod_ex.c \
		ft_atof_ex.c \
		ft_atold_ex.c \
		int_after_dot.c \
		int_before_dot.c \
		is_valid_float_string_ex.c

LIB_PATH_FLAG ?= $(addprefix -L,$(LINK_PATH))

LIB_NAME = $(shell echo $(notdir $(LINK_PATH)) | sed "s|lib||")

LIB_NAME_FLAG ?= $(addprefix -l,$(LIB_NAME))

LINK_FLAGS = $(sort $(UNSORT_LINK_FLAGS))

UNSORT_LINK_FLAGS := $(LINK_FLAGS) $(LIB_PATH_FLAG) $(LIB_NAME_FLAG)

INCLUDE_FLAGS ?= $(addprefix -I,$(INCLUDE_PATH))

MAKEFILE_PATH ?= $(PROJECT_PATH)/Makefile

NAME_PATH ?= $(PROJECT_PATH)/$(NAME)

INCLUDE_DIR ?= include

INCLUDE_PATH ?= $(PROJECT_PATH)/$(INCLUDE_DIR)

SRC_DIR ?= src

SRC_PATH ?= $(PROJECT_PATH)/$(SRC_PATH)

OBJ_DIR ?= obj

OBJ_PATH ?= $(PROJECT_PATH)/$(OBJ_DIR)

OBJ ?= $(SRC:.c=.o)

RMDIR = $(RM)r

ifeq ($(notdir $(shell pwd)),obj)
all: $(NAME)
else
all: $(OBJ_PATH)
	@$(MAKE) --directory=$(OBJ_PATH) --makefile=$(MAKEFILE_PATH) \
	PROJECT_PATH=$(PROJECT_PATH) NAME=$(NAME_PATH) ARFLAGS=$(ARFLAGS) \
	LINK_FLAGS="$(LINK_FLAGS)" LIB_NAME_LIST="$(LIB_NAME_LIST)"
endif

$(OBJ_PATH):
	@if [ ! -d $(OBJ_PATH) ]; then mkdir $(OBJ_PATH); fi

$(NAME): $(OBJ)
ifeq ($(suffix $(notdir $(NAME))),.a)
$(NAME): $(NAME)($(OBJ))
else
$(NAME):
	$(CC) $(OBJ) $(CFLAGS) $(LINK_FLAGS) -o $@
endif

clean:
	$(RMDIR) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME_PATH)

re: fclean all