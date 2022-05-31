.DEFAULT_GOAL: build/NextCatGame

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

build/NextCatGame:
	mkdir -p build
	$(CC) src/main.cpp -o build/NextCatGame
