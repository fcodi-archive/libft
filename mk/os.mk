# -----------------------------------------------------------------------------
#  Platform specific
# -----------------------------------------------------------------------------

override OS ?= $(shell uname 2>/dev/null || echo Unknown)

ifeq ($(OS),Unknown)
$(error Unsupported OS)
endif