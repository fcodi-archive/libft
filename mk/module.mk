# -----------------------------------------------------------------------------
#	Module
# -----------------------------------------------------------------------------

MODULE_PATH = $(LIBFT_MODULE_PATH)/$(MODULE_NAME)

# -----------------------------------------------------------------------------
#	Source
# -----------------------------------------------------------------------------

MODULE_SOURCE_DIRECTORY = src

MODULE_SOURCE_PATH = $(MODULE_PATH)/$(MODULE_SOURCE_DIRECTORY)

SOURCE_FILES +=$(foreach FILE,$(MODULE_SOURCE_FILES), \
	$(addprefix $(MODULE_SOURCE_PATH)/,$(sort $(strip $(FILE)))))

# -----------------------------------------------------------------------------
#	Include
# -----------------------------------------------------------------------------

MODULE_INCLUDE_DIRECTORY = include

MODULE_INCLUDE_PATH = $(MODULE_PATH)/$(MODULE_INCLUDE_DIRECTORY)

INCLUDE_FILES +=$(foreach FILE,$(MODULE_INCLUDE_FILES), \
	$(addprefix $(MODULE_INCLUDE_PATH)/,$(sort $(strip $(FILE)))))