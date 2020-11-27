ifndef PREFIX_MK
PREFIX_MK :=

# **************************************************************************** #
#	MK
# **************************************************************************** #

include $(MK)/function.mk
include $(MK)/os.mk

# **************************************************************************** #
#	Source
# **************************************************************************** #

SOURCE_DIRECTORY ?= src

SOURCE_PATH ?= $(PREFIX)/$(SOURCE_DIRECTORY)

# **************************************************************************** #
#	Include
# **************************************************************************** #

INCLUDE_DIRECTORY ?= include

INCLUDE_PATH ?= $(PREFIX)/$(INCLUDE_DIRECTORY)

INCLUDE_SEARCH += $(INCLUDE_PATH)

# **************************************************************************** #
#	Object
# **************************************************************************** #

OBJECT_DIRECTORY ?= .obj

OBJECT_PATH ?= $(PREFIX)/$(OBJECT_DIRECTORY)

OBJECT_FILES ?= $(SOURCE_FILES:.c=.o)

# **************************************************************************** #
#	Special
# **************************************************************************** #

override CC = gcc

include $(MK)/flags.mk
include $(MK)/var.mk

WARNING_FLAGS := -Wall -Wextra -Werror

.SECONDARY: $(OBJECT_FILES)

.DEFAULT_GOAL := all

.PHONY: all debug  _cflags _ldflags _cppflags _ipath _lpath

debug: all

#TODO Убедиться что этому здесь место или перенести в иной файл
#	Например в prefix.mk
$(NAME): override CFLAGS := $(WARNING_FLAGS) $(CFLAGS)
ifneq ($(findstring debug,$(MAKECMDGOALS)),)
$(NAME): override CFLAGS := -g3 $(CFLAGS)
endif

# **************************************************************************** #
#	Rule that print value of environment variable
# **************************************************************************** #

_cflags:
	@echo $(CFLAGS)

_cppflags:
	@echo $(CPPFLAGS)

_ldflags:
ifeq ($(notdir $(NAME)),libft.a)
_ldflags:
	@echo -lft -L$(PREFIX)
else
_ldflags:
	@echo $(LDFLAGS)
endif

_ipath:
	@echo $(INCLUDE_SEARCH)

_lpath:
ifeq ($(notdir $(NAME)),libft.a)
_lpath:
	@echo $(dir $(NAME))
else
_lpath:
	@echo $(LIBRARY_PATH)

# **************************************************************************** #
#	Wrapper
# **************************************************************************** #

ifneq ($(OS),Darwin)
ifeq ($(wildcard $(NAME).sh),)
WRAPPER = $(NAME).sh
$(shell echo "#!/usr/bin/env sh" >> $(WRAPPER) \
&& echo "" >> $(WRAPPER)\
&& echo env LD_LIBRARY_PATH=\"$(PREFIX)/lib:$(LD_LIBRARY_PATH)\" \
./$(notdir $(NAME)) "$$""*" >> $(WRAPPER))
$(shell chmod +x $(WRAPPER))
endif
endif
endif

# **************************************************************************** #
#	Check hashsum of environment variable
# **************************************************************************** #

$(eval $(call _CHECK_VARIABLE,$(VARIABLE)))

# **************************************************************************** #
#	Path search
# **************************************************************************** #

vpath %.c $(SOURCE_PATH)
vpath %.h $(INCLUDE_SEARCH)
vpath %.o $(OBJECT_PATH)
vpath %.a $(LIBRARY_PATH)
vpath %.so $(LIBRARY_PATH)
vpath %.var $(VARIABLE_PATH)
ifeq ($(OS),Darwin)
vpath %.dylib $(LIBRARY_PATH)
endif

endif