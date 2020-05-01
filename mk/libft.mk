# **************************************************************************** #
#	General
# **************************************************************************** #

.PHONY: all re clean fclean

PROJECT_PATH ?= $(CURDIR)

RMDIR := $(RM)r

EMPTY :=

SPACE :=
SPACE +=

# **************************************************************************** #
#	Libft
# **************************************************************************** #

LIBFT_DIRECTORY ?= libft

ifeq ($(notdir $(CURDIR)),$(LIBFT_DIRECTORY))
LIBFT_PATH ?= $(CURDIR)
else
LIBFT_PATH ?= $(PROJECT_PATH)/$(LIBFT_DIRECTORY)
endif

LIBFT_MAKEFILE ?= $(LIBFT_PATH)/Makefile

LIBFT_INCLUDE_DIRECTORY ?= include

LIBFT_INCLUDE_PATH_ROOT ?= $(LIBFT_PATH)/$(LIBFT_INCLUDE_DIRECTORY)

LIBFT_INCLUDE_PATH ?= $(shell find $(LIBFT_INCLUDE_PATH_ROOT) -type d)

ifneq ($(CURDIR),$(OBJECT_PATH))
INCLUDE_PATH += $(LIBFT_INCLUDE_PATH)
LIBRARY_FILES += $(LIBFT_PATH)/libft.a
override LDFLAGS += -lm
endif

# **************************************************************************** #
#	Libft MK
# **************************************************************************** #

LIBFT_MK_PATH ?= $(LIBFT_PATH)/mk

LIBFT_MK ?= $(LIBFT_MK_PATH)/libft.mk

VAR_MK ?= $(LIBFT_MK_PATH)/var.mk

BREW_MK ?= $(LIBFT_MK_PATH)/brew.mk

FLAGS_MK ?= $(LIBFT_MK_PATH)/flags.mk

OS_MK ?= $(LIBFT_MK_PATH)/os.mk

PROJECT_MK ?= $(LIBFT_MK_PATH)/project.mk

# **************************************************************************** #
#	Libft special rules and definitions
# **************************************************************************** #

ifneq ($(CURDIR),$(OBJECT_PATH))
include $(VAR_MK)
include $(OS_MK)
include $(FLAGS_MK)
include $(BREW_MK)
endif

all:

%.exist:
	-mkdir $(@D)
	-touch $@

%.backup:
	-cp $(basename $@) $@

vpath %.c $(SOURCE_PATH)
vpath %.o $(OBJECT_PATH)
vpath %.h $(INCLUDE_PATH)
vpath %.a $(LIBRARY_FILES)
vpath %.so $(LIBRARY_PATH)
ifeq ($(OS),Darwin)
vpath %.dylib $(LIBRARY_PATH)
endif