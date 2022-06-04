ifndef BUILD
 BUILD := debug
endif

ifdef OS
	include Windows.mk
else
	ifeq($(shell uname), Linux)
		include Linux.mk
endif

ifeq ($(BUILD),debug)
# CC := g++ -g
 CC := clang++ -g
else ifeq ($(BUILD),release)
# CC := g++ -O3
 CC := clang++ -O3
else
 $(error Invalid build type. 'make' must be run with either BUILD=debug or BUILD=release.)
endif

.DEFAULT_GOAL: $(OUT_BIN)
all: $(OUT_BIN)

clean:
	$(RM) $(OUT_DIR)

$(OUT_BIN): $(OBJECTS)
	$(MKDIR) $(OUT_DIR)
	$(CC) $(OBJECTS) -o $(OUT_BIN)

$(OBJECTS): $(OBJ_DIR)/%.o: %.cpp
	$(MKDIR) $(@D)
	$(CC) -o $@ -c $<
