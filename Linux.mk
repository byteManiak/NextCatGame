RM = rm -rf
MKDIR = @mkdir -p
OUT_DIR ?= build
OBJ_DIR := $(OUT_DIR)/obj
OUT_BIN := $(OUT_DIR)/NextCatGame
SOURCES := \
	src/main.cpp
OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.cpp=.o))
