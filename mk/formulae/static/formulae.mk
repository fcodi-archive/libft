define _FORMULAE_EVAL

include $(MK)/brew.mk

ifndef $(call _TO_UPPER,$1)_MK
$(call _TO_UPPER,$1)_MK = $(FORMULAE)/$1.mk

$(call _TO_UPPER,$2) = $(BREW_BIN)/$2

ifeq ($(wildcard $(call _TO_UPPER,$2)),)
$(call _TO_UPPER,$2): $(BREW)
	$(BREW) install $$1
endif

endif

endef

_FORMULAE = $(eval $(call _FORMULAE_EVAL,$1,$1))

_FORMULAE_NAME = $(eval $(call _FORMULAE_EVAL,$1,$2))

#TODO Сделать возможность генерировать мк файл с правилами загрузки и
#	установки формул