# **************************************************************************** #
#	Predefined libft variables and includes
# **************************************************************************** #

PROJECT_PATH := $(CURDIR)

LIBFT_DIRECTORY ?= libft

LIBFT_PATH ?= $(PROJECT_PATH)/$(LIBFT_DIRECTORY)

LIBFT = $(LIBFT_PATH)/libft.a

LIBFT_MK_PATH = $(LIBFT_PATH)/mk

LIBFT_MAKEFILE ?= $(LIBFT_PATH)/Makefile

MAKE_LIBFT = +@$(MAKE) --no-print-directory -C $(LIBFT_PATH) $(MAKECMDGOALS)

.PHONY: all re clean fclean $(LIBFT)

include $(LIBFT_MK_PATH)/libft.mk

# **************************************************************************** #
#	Set MAKE_PROJECT command
# **************************************************************************** #

MAKE_PROJECT = +@$(MAKE) --makefile="$(LIBFT_MAKEFILE)" \
	--directory="$(PROJECT_PATH)" --no-print-directory \
	NAME="$(NAME)" SOURCE_FILES="$(SOURCE_FILES)" $@

ifneq ($(INCLUDE_FILES),)
MAKE_PROJECT += INCLUDE_FILES="$(INCLUDE_FILES)"
endif

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

ifneq ($(REMOVE_FILE),)
MAKE_PROJECT += REMOVE_FILE="$(REMOVE_FILE)"
endif

ifneq ($(REMOVE_PATH),)
MAKE_PROJECT += REMOVE_PATH="$(REMOVE_PATH)"
endif

# **************************************************************************** #
#	Rule that always check libft
# **************************************************************************** #

all: $(LIBFT)

$(LIBFT):
	$(MAKE_LIBFT)