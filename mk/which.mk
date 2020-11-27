ifndef WHICH_MK
WHICH_MK = $(MK)/which.mk

WHICH = $(shell /usr/bin/env which env 1>/dev/null 2>/dev/null \
&& echo /usr/bin/env which || echo $(BREW_BIN)/gwhich)

$(WHICH):
ifeq ($(WHICH),$(BREW_BIN)/gwhich)
$(shell /usr/bin/env gwhich env 1>/dev/null 2>/dev/null)
ifneq ($(.SHELLSTATUS),0)
$(WHICH): $(BREW)
	$(BREW) install gnu-which
endif
endif

endif