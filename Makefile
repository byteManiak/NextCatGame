ifndef BUILD
 BUILD := debug
endif

ifeq ($(BUILD),debug)
 CC := g++ -g
else ifeq ($(BUILD),release)
 CC := g++ -O3
else
 $(error Invalid build type. 'make' must be run with either BUILD=debug or BUILD=release.)
endif

OUT_DIR ?= build
OBJ_DIR = $(OUT_DIR)/obj
OUT_BIN := $(OUT_DIR)/NextCatGame

SOURCES := \
	src/main.cpp

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.cpp=.o))

.DEFAULT_GOAL: $(OUT_BIN)
all: $(OUT_BIN)

clean:
	rm -rf $(OUT_DIR)

$(OUT_BIN): $(OBJECTS)
	@mkdir -p $(OUT_DIR)
	$(CC) $(OBJECTS) -o $(OUT_BIN)

$(OBJECTS): $(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) -o $@ -c $<
