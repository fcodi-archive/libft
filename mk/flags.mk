ifndef FLAGS_MK
FLAGS_MK :=

include $(MK)/function.mk

# **************************************************************************** #
#	ARFLAGS
# **************************************************************************** #

ifeq ($(suffix $(NAME)),.a)
ifeq ($(OS),Linux)
override ARFLAGS = rcsU
else
override ARFLAGS = rcs
endif
endif

# **************************************************************************** #
#	CFLAGS
# **************************************************************************** #

CFLAGS_PATH = $(call _UNIQ, \
	$(filter-out . ./,$(dir $(INCLUDE_FILES))) $(INCLUDE_PATH))

override CFLAGS += $(foreach _PATH,$(CFLAGS_PATH), \
	$(shell [ -d $(_PATH) ] && echo $(addprefix -I,$(_PATH))))

# **************************************************************************** #
#	LDFLAGS
# **************************************************************************** #

LDFLAGS_FILES := $(foreach _FILE,$(LDFLAGS_FILES), \
	$(shell [ -f $(_FILE) ] && echo $(_FILE)))

ifeq ($(OS),Darwin)
LDFLAGS_PATH := $(call _UNIQ, $(filter-out . ./,$(dir \
	$(filter %.a %.so %.dylib,$(LDFLAGS_FILES)))) $(LIBRARY_PATH))
LDFLAGS_NAME := $(call _UNIQ, \
	$(patsubst lib%,%,$(basename $(filter %.a %.so %.dylib, \
	$(notdir $(LDFLAGS_FILES))))))
else
LDFLAGS_PATH := $(call _UNIQ, $(filter-out . ./,$(dir $(filter %.a %.so, \
	$(LDFLAGS_FILES)))) $(LIBRARY_PATH))
LDFLAGS_NAME := $(call _UNIQ, \
	$(patsubst lib%,%,$(basename $(filter %.a %.so, \
	$(notdir $(LDFLAGS_FILES))))))
endif

LDFLAGS_PATH := $(foreach _PATH,$(LDFLAGS_PATH), \
	$(shell [ -d $(_PATH) ] && echo $(_PATH)))

LIBRARY_PATH += $(LDFLAGS_PATH)

override LDFLAGS += $(foreach _PATH,$(LDFLAGS_PATH), \
	$(addprefix -L,$(_PATH)))

override LDFLAGS += $(foreach _NAME,$(LDFLAGS_NAME), \
	$(addprefix -l,$(_NAME)))

endif