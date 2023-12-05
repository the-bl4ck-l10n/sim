# Settings ---------------------------------------

# name for the binary executable
EXE := sim

# space-separated list of library dependencies to search with pkg-config
SYS_DEPS := ncurses

# space-separated list of local static libraries in the lib folder
LOC_DEPS :=

# compiler
CC := gcc

# compiler flags
CF := -Wall -Werror -Wextra

# -------------------------------------------------

$(shell mkdir -p bin)
$(shell mkdir -p build)
$(shell mkdir -p include)
$(shell mkdir -p lib)
$(shell mkdir -p src)
SRCS := $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJS := $(patsubst src/%.c, build/%.o, $(SRCS))
S_LIBS := $(foreach dep, $(SYS_DEPS), $(shell pkg-config --libs $(dep)))
S_INCL := $(foreach dep, $(SYS_DEPS), $(shell pkg-config --cflags $(dep)))
USR_LIBS := $(foreach dep, $(LOC_DEPS), -l$(dep))
USR_LIB_PATH := -Llib

all: bin/$(EXE)

bin/$(EXE): $(OBJS)
	$(CC) $(CF) -Iinclude $^ $(USR_LIB_PATH) $(USR_LIBS) -o $@ $(S_LIBS)

build/%.o: src/%.c
	@mkdir -p $(dir \$@)
	$(CC) -c $(CF) -Iinclude $(S_INCL) $< -o $@

run:
	./bin/$(EXE)

clean:
	rm -rf build bin

.PHONY: all run clean
