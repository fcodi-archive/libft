# **************************************************************************** #
#	Variables
# **************************************************************************** #

BINNARY_DIRECTORY ?= bin

BINNARY_PATH ?= $(PROJECT_PATH)/bin

BINNARY_PATH_EXIST = $(BINNARY_PATH)/.exist

# **************************************************************************** #
#	Rules
# **************************************************************************** #

.DEFAULT_GOAL := all

.PHONY: all re clean fclean clean_bin

all: $(BINNARY_PATH_EXIST)

clean: clean_bin

clean_bin:
	$(RMDIR) $(BINNARY_PATH)