# **************************************************************************** #
#	Variables
# **************************************************************************** #

.DEFAULT_GOAL := all

RMDIR := $(RM)r

LOG_DIRECTORY ?= log

LOG_PATH ?= $(PROJECT_PATH)/$(LOG_DIRECTORY)

LOG_PATH_EXIST = $(LOG_PATH)/.exist

# **************************************************************************** #
#	Rules
# **************************************************************************** #

.PHONY: all fclean clean clean_log

all: $(LOG_PATH_EXIST)

clean: clean_log

clean_log:
	$(RMDIR) $(LOG_PATH)