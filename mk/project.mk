PROJECT_PATH := $(shell pwd)

INCLUDE_DIR ?= include

#
#OBJ_DIR ?= obj

#
#SRC_DIR ?= src

INCLUDE_PATH += $(PROJECT_PATH)/$(INCLUDE_DIR)

MAKE_PROJECT = @$(MAKE) -C libft $@ NAME=$(NAME) SRC="$(SRC)" \
	PROJECT_PATH=$(PROJECT_PATH) MAKEFILE_PATH=$(shell pwd)/libft/Makefile \
	INCLUDE_PATH="$(INCLUDE_PATH)"
ifneq ($(LINK_PATH),)
	MAKE_PROJECT += LINK_PATH="$(LINK_PATH)"
endif
ifneq ($(OBJ_DIR),)
	MAKE_PROJECT += OBJ_DIR=$(OBJ_DIR)
endif
ifneq ($(INCLUDE_DIR),)
	MAKE_PROJECT += INCLUDE_DIR=$(INCLUDE_DIR)
endif
ifneq ($(SRC_DIR),)
	MAKE_PROJECT += SRC_DIR=$(SRC_DIR)
endif
