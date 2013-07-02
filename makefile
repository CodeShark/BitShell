SHELL=/bin/bash

include paths.mk

CXX_FLAGS = -Wall -std=c++0x

ifdef DEBUG
    CXX_FLAGS += -g
else
    CXX_FLAGS += -O3
endif

INCLUDE_DIR = \
    -I $(CONSOLE_SHELL_ROOT)/src

LIB = \
    -l ncurses

SRC = \
    $(CONSOLE_SHELL_ROOT)/src/command_interpreter.cpp \
    $(CONSOLE_SHELL_ROOT)/src/console_session.cpp \
    src/bitcoind_commands.cpp \
    src/bitshell.cpp 

HEADERS = \
    $(CONSOLE_SHELL_ROOT)/src/command_interpreter.h \
    $(CONSOLE_SHELL_ROOT)/src/console_session.h \
    src/bitcoind_commands.h

all: bitshell

bitshell: $(SRC) $(HEADERS)
	$(CXX) $(CXX_FLAGS) -o $@ $^ \
	$(INCLUDE_DIR) $(LIB)

clean:
	-rm -f bitshell
