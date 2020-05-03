# **************************************************************************** #
#	Project
# **************************************************************************** #

.PHONY: all re clean fclean

PROJECT_PATH := $(CURDIR)

LIBFT_DIRECTORY ?= libft

LIBFT_PATH = $(PROJECT_PATH)/$(LIBFT_DIRECTORY)

LIBFT_MK_PATH = $(LIBFT_PATH)/mk

include $(LIBFT_MK_PATH)/libft.mk

MAKE_LIBFT = @$(MAKE) -C $(LIBFT_PATH) $(MAKECMDGOALS)

MAKE_PROJECT = @$(MAKE) $@ --makefile="$(LIBFT_MAKEFILE)" \
	--directory="$(PROJECT_PATH)" NAME="$(NAME)" \
	SOURCE_FILES="$(SOURCE_FILES)" INCLUDE_FILES="$(INCLUDE_FILES)"

ifneq ($(LIBRARY_FILES),)
MAKE_PROJECT += LIBRARY_FILES="$(LIBRARY_FILES)"
endif

ifneq ($(LIBRARY_FLAGS),)
MAKE_PROJECT += LIBRARY_FLAGS="$(LIBRARY_FLAGS)"
endif

ifneq ($(LIBRARY_PATH),)
MAKE_PROJECT += LIBRARY_PATH="$(LIBRARY_PATH)"
endif

ifneq ($(LDFLAGS),)
MAKE_PROJECT += LDFLAGS="$(LDFLAGS)"
endif

ifneq ($(CFLAGS),)
MAKE_PROJECT += CFLAGS="$(CFLAGS)"
endif

ifneq ($(CPPFLAGS),)
MAKE_PROJECT += CPPFLAGS="$(CPPFLAGS)"
endif