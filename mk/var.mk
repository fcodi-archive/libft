# **************************************************************************** #
#	Include
# **************************************************************************** #

INCLUDE_DIRECTORY ?= include

_INCLUDE_FILES ?= $(sort $(INCLUDE_FILES) $(LIBFT_INCLUDE_FILES))

INCLUDE_PATH_ROOT ?= $(PROJECT_PATH)/$(INCLUDE_DIRECTORY)

INCLUDE_PATH_FIND ?= $(shell find $(INCLUDE_PATH_ROOT) -type d)

_INCLUDE_PATH ?= $(sort $(INCLUDE_PATH) $(INCLUDE_PATH_ROOT))

ifneq ($(notdir $(CURDIR)),$(LIBFT_DIRECTORY))
_INCLUDE_PATH += $(LIBFT_INCLUDE_PATH)
endif

# **************************************************************************** #
#	Source
# **************************************************************************** #

SOURCE_DIRECTORY ?= src

SOURCE_PATH_ROOT ?= $(PROJECT_PATH)/$(SOURCE_DIRECTORY)

SOURCE_PATH_FIND ?= $(shell find $(SOURCE_PATH_ROOT) -type d)

SOURCE_PATH ?= $(SOURCE_PATH_FIND)

_SOURCE_PATH ?= $(SOURCE_PATH) $(SOURCE_PATH_FIND)

# **************************************************************************** #
#	Object
# **************************************************************************** #

OBJECT_DIRECTORY ?= obj

OBJECT_PATH ?= $(PROJECT_PATH)/$(OBJECT_DIRECTORY)

OBJECT_PATH_EXIST ?= $(OBJECT_PATH)/.exist

OBJECT_FILES ?= $(SOURCE_FILES:.c=.o)