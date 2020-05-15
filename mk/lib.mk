# **************************************************************************** #
#	Variables
# **************************************************************************** #

LIB_DIRECTORY ?= lib

LIB_PATH ?= $(PROJECT_PATH)/$(LIB_DIRECTORY)

LIB_PATH_EXIST = $(LIB_PATH)/.exist

# **************************************************************************** #
#	Variables
# **************************************************************************** #

.DEFAULT_GOAL := all

.PHONY: all re clean fclean clean_lib

all: $(LIB_PATH_EXIST)

clean: clean_lib

clean_lib:
	$(RMDIR) $(LIB_PATH)