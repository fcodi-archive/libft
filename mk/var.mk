# **************************************************************************** #
#	Variable
# **************************************************************************** #

ifndef VAR_MK
VAR_MK = $(MK)/var.mk
include $(MK)/hashsum.mk
include $(MK)/function.mk

RMDIR ?= $(RM)r

VARIABLE += CPPFLAGS CFLAGS LDFLAGS ARFLAGS CC CPATH LIBRARY_PATH \
	LD_LIBRARY_PATH INCLUDE C_INCLUDE_PATH
ifeq($(OS),Darwin)
VARIABLE += DYLD_LIBRARY_PATH
endif

VARIABLE_DIRECTORY ?= var

VARIABLE_PATH ?= $(PREFIX)/var

VARIABLE_PATH_EXIST ?= $(VARIABLE_PATH)/.exist

VARIABLE_FILES = $(VARIABLE:%=$(VARIABLE_PATH)/%)

endif