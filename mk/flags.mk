# **************************************************************************** #
#	Flags
# **************************************************************************** #

WARNING_FLAGS = -Wall -Wextra -Werror

override CC = gcc

ifeq ($(OS),Linux)
override ARFLAGS = rcsU
else
override ARFLAGS = rcs
endif

override CFLAGS += $(WARNING_FLAGS) \
	$(foreach PATH,$(_INCLUDE_PATH),$(addprefix -I,$(PATH)))

ifdef LIBRARY_FILES
ifneq ($(LIBRARY_FILES),)
_LIBRARY_PATH := $(sort $(LIBRARY_PATH) \
	$(foreach FILE,$(LIBRARY_FILES), $(filter-out . ./,$(dir $(FILE)))))
_LIBRARY_NAME = $(foreach FILE,$(LIBRARY_FILES), \
	$(patsubst lib%,%,$(basename $(filter %.a %.so %.dylib, \
	$(notdir $(shell find $(_LIBRARY_PATH) -name "$(notdir $(FILE))"))))))
override LDFLAGS += $(foreach FILE,$(_LIBRARY_NAME),$(addprefix -l,$(FILE)))
endif
endif

ifdef LIBRARY_PATH
_LIBRARY_PATH += $(sort $(LIBRARY_PATH) \
	$(foreach FILE,$(LIBRARY_FILES), $(filter-out . ./,$(dir $(FILE)))))
endif

ifdef _LIBRARY_PATH
ifneq ($(_LIBRARY_PATH),)
override LDFLAGS += $(foreach PATH,$(sort $(_LIBRARY_PATH)), \
	$(addprefix -L,$(PATH)))
endif
endif
