# -----------------------------------------------------------------------------
#	Include flags
# -----------------------------------------------------------------------------

ifdef INCLUDE_PATH

INCLUDE_FLAGS := $(sort $(strip $(INCLUDE_FLAGS)) \
	$(foreach PATH,$(sort $(strip $(INCLUDE_PATH))), $(addprefix -I, $(PATH))))

endif

# -----------------------------------------------------------------------------
#	Library flags
# -----------------------------------------------------------------------------

ifdef LIBRARY_FILES

ifeq ($(OS),Darwin)
_LIBRARY_FILES = $(foreach FILE,$(sort $(strip $(LIBRARY_FILES))), \
	$(filter %.a %.so %.dylib, $(FILE)))
else ifeq ($(OS),Linux)
_LIBRARY_FILES = $(foreach FILE,$(sort $(strip $(LIBRARY_FILES))), \
	$(filter %.a %.so, $(FILE)))
endif

LIBRARY_PATH := $(sort $(strip $(LIBRARY_PATH)) \
	$(foreach PATH,$(_LIBRARY_FILES), \
	$(filter-out . ./,$(dir $(PATH)))))

LIBRARY_FLAGS := $(sort $(strip $(LIBRARY_FLAGS)) \
	$(foreach FILE,$(_LIBRARY_FILES), \
    $(addprefix -l,$(patsubst lib%,%,$(basename $(notdir $(FILE)))))) \
	$(foreach PATH,$(LIBRARY_PATH), \
	$(addprefix -L,$(PATH))))

endif

ifdef LIBRARY_PATH

LIBRARY_FLAGS := $(sort $(strip $(LIBRARY_FLAGS)) \
	$(foreach PATH,$(sort $(strip $(LIBRARY_PATH))), \
	$(addprefix -L,$(filter-out . ./,$(PATH)))))

endif

# -----------------------------------------------------------------------------
#	GCC flags
# -----------------------------------------------------------------------------

WARNING_SUPPRESS_FLAGS := -Wall -Wextra -Werror

override CFLAGS := $(sort $(strip $(CFLAGS)) \
	$(WARNING_SUPPRESS_FLAGS) $(INCLUDE_FLAGS))

#override CPPFLAGS := $(sort $(strip $(CPPFLAGS)))

override LDFLAGS := $(sort $(strip $(LDFLAGS)) $(LIBRARY_FLAGS))

ifeq ($(OS),Darwin)
override ARFLAGS := rcs
else ifeq ($(OS),Linux)
override ARFLAGS := rcsU
endif