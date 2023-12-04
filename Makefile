EXE := sim

LIBS := $(shell pkg-config --libs ncurses)
INCLUDES := $(shell pkg-config --cflags ncurses)

CC := gcc
CFLAGS := -Wall -Iinclude

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(BIN_DIR))

SRC_FILES := $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

SRC_SUBDIRS := $(wildcard $(SRC_DIR)/*)

BUILD_SUBDIRS := $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SRC_SUBDIRS))
$(shell mkdir -p $(BUILD_SUBDIRS))

all: $(BIN_DIR)/$(EXE)

$(BIN_DIR)/$(EXE): $(OBJ_FILES)
	$(CC) $^ -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run:
	./$(BIN_DIR)/$(EXE)

clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

.PHONY: all run clean 
