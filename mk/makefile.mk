# -----------------------------------------------------------------------------
#	General
# -----------------------------------------------------------------------------

RMDIR := $(RM)r

EMPTY :=

SPACE :=

SPACE +=

PROJECT_PATH ?= $(CURDIR)

# -----------------------------------------------------------------------------
#  Special rule and definition
# -----------------------------------------------------------------------------

include libft/mk/libft.mk
include $(VAR_MK)
include $(OS_MK)
include $(FLAGS_MK)

.PHONY: all re clean fclean debug default

.SECONDARY: $(OBJECT_FILES)

.DEFAULT: all

default: all

%.exist:
	-mkdir $(@D)
	-touch $@

debug: override CFLAGS := $(sort -g3 $(strip $(CFLAGS)))
debug: all

vpath %.c $(SOURCE_PATH)
vpath %.h $(INCLUDE_PATH)
vpath %.o $(OBJECT_PATH)
vpath %.a $(LIBRARY_PATH)
vpath %.so $(LIBRARY_PATH)
ifeq ($(OS),Darwin)
vpath %.dylib $(LIBRARY_PATH)
endif