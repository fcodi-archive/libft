# **************************************************************************** #
#	General
# **************************************************************************** #

.PHONY: all re clean fclean

.DEFAULT_GOAL := all

.DEFAULT: all

PROJECT_PATH ?= $(CURDIR)

RMDIR := $(RM)r

EMPTY :=

SPACE := $(EMPTY) $(EMPTY)

COMMA :=,

# **************************************************************************** #
#	Libft
# **************************************************************************** #

LIBFT_DIRECTORY ?= libft

ifeq ($(notdir $(CURDIR)),$(LIBFT_DIRECTORY))
LIBFT_PATH ?= $(CURDIR)
else
LIBFT_PATH ?= $(PROJECT_PATH)/$(LIBFT_DIRECTORY)

ifneq ($(CURDIR),$(OBJECT_PATH))
LIBRARY_FILES += $(LIBFT_PATH)/libft.a
override LDFLAGS += -lm
endif

endif

LIBFT_MAKEFILE ?= $(LIBFT_PATH)/Makefile

LIBFT_INCLUDE_DIRECTORY ?= include

LIBFT_INCLUDE_PATH_ROOT ?= $(LIBFT_PATH)/$(LIBFT_INCLUDE_DIRECTORY)

LIBFT_INCLUDE_PATH ?= $(shell find $(LIBFT_INCLUDE_PATH_ROOT) -type d)

# **************************************************************************** #
#	Libft MK
# **************************************************************************** #

LIBFT_MK_PATH ?= $(LIBFT_PATH)/mk

LIBFT_MK ?= $(LIBFT_MK_PATH)/libft.mk

VAR_MK ?= $(LIBFT_MK_PATH)/var.mk

#BREW_MK ?= $(LIBFT_MK_PATH)/brew.mk

FLAGS_MK ?= $(LIBFT_MK_PATH)/flags.mk

OS_MK ?= $(LIBFT_MK_PATH)/os.mk

PROJECT_MK ?= $(LIBFT_MK_PATH)/project.mk

#INSTALL_MK ?= $(LIBFT_MK_PATH)/install.mk

SDL2_MK ?= $(LIBFT_MK_PATH)/sdl2.mk

LOG_MK ?= $(LIBFT_MK_PATH)/log.mk

BIN_MK ?= $(LIBFT_MK_PATH)/bin.mk

LIB_MK ?= $(LIBFT_MK_PATH)/lib.mk

# **************************************************************************** #
#	Libft special rules and definitions
# **************************************************************************** #

ifneq ($(CURDIR),$(OBJECT_PATH))
include $(OS_MK)
include $(VAR_MK)
include $(FLAGS_MK)
endif

%.exist:
	-mkdir -p $(@D)
	-touch $@

%.backup:
	-cp $(basename $@) $@

vpath %.c $(SOURCE_PATH)
vpath %.o $(OBJECT_PATH)
vpath %.h $(sort $(INCLUDE_PATH) $(_INCLUDE_PATH))
vpath %.a $(sort $(LIBRARY_PATH) $(_LIBRARY_PATH))
vpath %.so $(sort $(LIBRARY_PATH) $(_LIBRARY_PATH))
ifeq ($(OS),Darwin)
vpath %.dylib $(sort $(LIBRARY_PATH) $(_LIBRARY_PATH))
endif