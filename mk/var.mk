# -----------------------------------------------------------------------------
#	Include
# -----------------------------------------------------------------------------

INCLUDE_DIRECTORY ?= include

INCLUDE_PATH := $(sort $(INCLUDE_PATH) $(INCLUDE_PATH_FIND))

INCLUDE_PATH_ROOT ?= $(PROJECT_PATH)/$(INCLUDE_DIRECTORY)

INCLUDE_PATH_FIND != find $(INCLUDE_PATH_ROOT) -type d 2>/dev/null

# -----------------------------------------------------------------------------
#	Source
# -----------------------------------------------------------------------------

SOURCE_DIRECTORY ?= src

SOURCE_PATH := $(sort $(SOURCE_PATH) $(SOURCE_PATH_FIND))

SOURCE_PATH_ROOT ?= $(PROJECT_PATH)/$(SOURCE_DIRECTORY)

SOURCE_PATH_FIND != find $(SOURCE_PATH_ROOT) -type d 2>/dev/null

# -----------------------------------------------------------------------------
#  Object
# -----------------------------------------------------------------------------

OBJECT_DIRECTORY ?= obj

OBJECT_PATH_EXIST ?= $(OBJECT_ROOT_PATH)/.exist

OBJECT_PATH_ROOT ?= $(PROJECT_PATH)/$(OBJECT_DIRECTORY)

OBJECT_PATH := $(sort $(OBJECT_PATH) $(OBJECT_PATH_FIND))

OBJECT_PATH_FIND != find $(OBJECT_PATH_ROOT) -type d 2>/dev/null

OBJECT_FILES ?= $(SOURCE_FILES:.c=.o)