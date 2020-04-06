# -----------------------------------------------------------------------------
#  General
# -----------------------------------------------------------------------------

PROJECT_PATH ?= $(CURDIR)

MAKE_PROJECT = $(MAKE) --directory="$(CURDIR)" \
	--makefile=$(LIBFT_PATH)/Makefile \
	NAME="$(PROJECT_PATH)/$(NAME)"

# -----------------------------------------------------------------------------
#  Libft
# -----------------------------------------------------------------------------

MAKE_LIBFT = $(MAKE) -C $(LIBFT_PATH) $@

LIBFT_DIR = libft

LIBFT_PATH = $(PROJECT_PATH)/$(LIBFT_DIR)

LIBFT_MK_PATH = $(LIBFT_PATH)/mk

# -----------------------------------------------------------------------------
#  Special rules and definitions
# -----------------------------------------------------------------------------

EMPTY :=

SPACE :=
SPACE +=

RMDIR = $(RM)r

.PHONY: all re clean fclean libft

.SECONDARY: $(OBJECT_FILES)

.DEFAULT: all
