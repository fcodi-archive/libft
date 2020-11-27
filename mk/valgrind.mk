ifndef VALGRIND_MK
VALGRIND_MK = $(MK)/valgrind.mk

$(shell $(WHICH) valgrind 1>/dev/null 2>/dev/null)
ifneq ($(.SHELLSTATUS),0)
ifeq ($(OS),Darwin)
$(VALGRIND): $(BREW)
	$(BREW) tap LouisBrunner/valgrind
	$(BREW) install --HEAD LouisBrunner/valgrind/valgrind
else
BREW_DEPENDENCY += valgrind
endif
endif
endif