# **************************************************************************** #
#	Detect OS
# **************************************************************************** #

ifeq ($(OS),Windows_NT)
$(error $(OS) unsupported!)
endif
override OS = $(shell uname 2>/dev/null || echo Unknown)
ifeq ($(OS),Unknown)
$(warning $(OS) OS!)
endif