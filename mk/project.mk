# -----------------------------------------------------------------------------
#  Make project
# -----------------------------------------------------------------------------

MAKE_PROJECT = $(MAKE) --directory="$(CURDIR)" \
	--makefile=$(LIBFT_PATH)/Makefile \
	NAME="$(PROJECT_PATH)/$(NAME)" \
	PROJECT_PATH="$(PROJECT_PATH)" \
	SOURCE_FILES="$(SOURCE_FILES)

ifneq ($(INCLUDE_FILES),)
MAKE_PROJECT += INCLUDE_FILES="$(INCLUDE_FILES)"
endif
ifneq ($(INCLUDE_DIRECTORY),)
MAKE_PROJECT += INCLUDE_DIRECTORY="$(INCLUDE_DIRECTORY)"
endif
ifneq ($(INCLUDE_PATH),)
MAKE_PROJECT += INCLUDE_PATH="$(INCLUDE_PATH)"
endif
ifneq ($(INCLUDE_FLAGS),)
MAKE_PROJECT += INCLUDE_FLAGS="$(INCLUDE_FLAGS)"
endif
ifneq ($(SOURCE_DIRECTORY),)
MAKE_PROJECT += SOURCE_DIRECTORY="$(SOURCE_DIRECTORY)"
endif
ifneq ($(SOURCE_PATH),)
MAKE_PROJECT += SOURCE_PATH="$(SOURCE_PATH)"
endif
ifneq ($(OBJECT_DIRECTORY),)
MAKE_PROJECT += OBJECT_DIRECTORY="$(OBJECT_DIRETORY)"
endif
ifneq ($(OBJECT_PATH),)
MAKE_PROJECT += OBJECT_PATH="$(OBJECT_PATH)"
endif
ifneq ($(LIBRARY_FILES),)
MAKE_PROJECT += LIBRARY_FILES="$(LIBRARY_FILES)"
endif
ifneq ($(LIBRARY_PATH),)
MAKE_PROJECT += LIBRARY_PATH="$(LIBRARY_PATH)"
endif
ifneq ($(LIBRRY_FLAGS),)
MAKE_PROJECT += LIBRARY_FLAGS="$(LIBRARY_FLAGS)"
endif
ifneq ($(CFLAGS),)
MAKE_PROJECT += CFLAGS="$(CFLAGS)"
endif
ifneq ($(CPPFLAGS),)
MAKE_PROJECT += CPPFLAGS="$(CPPFLAGS)"
endif
ifneq ($(LDFLAGS),)
MAKE_PROJECT += LDFLAGS="$(LDFLAGS)"
endif

# -----------------------------------------------------------------------------
#  Libft
# -----------------------------------------------------------------------------

MAKE_LIBFT = $(MAKE) -C $(LIBFT_PATH) $@

LIBFT_DIRECTORY = libft

LIBFT_PATH = $(PROJECT_PATH)/$(LIBFT_DIRECTORY)

LIBFT_MK_PATH = $(LIBFT_PATH)/mk

BREW_MK = $(LIBFT_MK_PATH)/brew.mk

# -----------------------------------------------------------------------------
#  Special rules and definitions
# -----------------------------------------------------------------------------

PROJECT_PATH ?= $(CURDIR)

EMPTY :=

SPACE :=
SPACE +=

RMDIR = $(RM)r

.PHONY: all re clean fclean libft

.SECONDARY: $(OBJECT_FILES)

.DEFAULT: all
