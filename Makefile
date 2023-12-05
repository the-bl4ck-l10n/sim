# Settings ---------------------------------------

# name for the binary executable
EXE := test

# space-separated list of dependencies
DEPS := ncurses

# compiler
CC := gcc

# compiler flags
CF := -Wall

# ------------------------------------------------

# create directories if not present already
$(shell mkdir -p build)
$(shell mkdir -p bin)

# get source and object file paths
SRCS = $(wildcard src/**/*.c) $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))

# get compiler flags for dependencies
LIBS := $(foreach dep, $(DEPS), $(shell pkg-config --libs $(dep)))
INCL := $(foreach dep, $(DEPS), $(shell pkg-config --cflags $(dep)))

# Compilation ------------------------------------

# target
all: bin/$(EXE)

# linking
bin/$(EXE): $(OBJS)
	$(CC) $(CF) -Iinclude $^ -o $@ $(LIBS)

# compiling
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CF) -Iinclude $(INCL) $< -o $@

# Commands ---------------------------------------

# run the executable
run:
	./bin/$(EXE)

# clean the project directory
clean:
	rm -rf build bin

# ------------------------------------------------

.PHONY: all run clean

# DISCLAIMER: 	this Makefile will not work if the
# 				src directory has more than one level
# 				of subdirectories
