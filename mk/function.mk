ifndef FUNCTION_MK
FUNCTION_MK := $(LIBFT_MK_PATH)/function.mk

# **************************************************************************** #
#	List function
# **************************************************************************** #

_UNIQ = $(if $1,$(firstword $1)$(call _UNIQ,$(filter-out $(firstword $1),$1)))

# **************************************************************************** #
#	Hashsum function
# **************************************************************************** #

include $(MK)/hashsum.mk

define _HASHSUM
$(shell echo $1 | $(HASHSUM) -)
endef

define _VARIABLE_HASHSUM
$(call _HASHSUM,$($1))
endef

# **************************************************************************** #
#	File function
# **************************************************************************** #

define _CAT_FILE
$(shell test -f $1 && cat $1 || echo)
endef

# **************************************************************************** #
#	Variable function
# **************************************************************************** #

include $(MK)/var.mk

define _CHECK_VARIABLE
$(shell test -d $(VARIABLE_PATH) || mkdir -p $(VARIABLE_PATH))
$(foreach VAR,$1, \
	$(shell test "$(call _CAT_FILE,$(VARIABLE_PATH)/$(VAR))" \
	!= "$(call _VARIABLE_HASHSUM,$(VAR))" \
	&& echo "$(call _VARIABLE_HASHSUM,$(VAR))" > $(VARIABLE_PATH)/$(VAR)))
endef

# **************************************************************************** #
#	Text function
# **************************************************************************** #

_TO_UPPER = $(shell echo '$1' | tr '[:lower:]' '[:upper:]')

_TO_LOWER = $(shell echo '$1' | tr '[:upper:]' '[:lower:]')

endif