ifndef FUNCTION_MK
FUNCTION_MK := $(LIBFT_MK_PATH)/function.mk

# **************************************************************************** #
#	List function
# **************************************************************************** #

_UNIQ = $(if $1,$(firstword $1)$(call _UNIQ,$(filter-out $(firstword $1),$1)))

endif