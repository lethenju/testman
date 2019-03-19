# Makefile for Testman source and examples
# MIT License
# Julien LE THENO

all: setup clean test 

SHELL:=/bin/bash
MAKE=make

BUILD_DIR=build
OBJECTS_DIR=$(BUILD_DIR)/obj
EXE_DIR=$(BUILD_DIR)/exe
SRC_DIR=src
TEST_DIR=example
INC_DIR+=inc
INC_PARAM=$(foreach d, $(INC_DIR), -I$d)

F1_EXISTS=$(shell [ -e $(BUILD_DIR) ] && echo Y || echo N )

.PHONY: all test clean

### EXAMPLES TARGETS

# TEST EXAMPLE
test: example_test.o 
	gcc -o $(EXE_DIR)/test_exe $(OBJECTS_DIR)/*.o

example_test.o: example.o testman.o $(TEST_DIR)/example_test.c 
	gcc -g -c $(TEST_DIR)/example_test.c $(SRC_DIR) $(INC_PARAM) -o  $(OBJECTS_DIR)/example_test.o

# LIB EXAMPLE

example.o: $(TEST_DIR)/example.c
	gcc -g -c $(TEST_DIR)/example.c -o  $(OBJECTS_DIR)/example.o

### END EXAMPLE TARGETS

### LIB TARGET
lib: testman.o

testman.o: $(SRC_DIR)/testman.c
	gcc -g -c $(SRC_DIR)/testman.c $(INC_PARAM) -o $(OBJECTS_DIR)/testman.o

### END LIB TARGET

setup:
ifeq ($(F1_EXISTS),N)
	@echo "Creating build directory"
	mkdir $(BUILD_DIR)
	mkdir $(EXE_DIR)
	mkdir $(OBJECTS_DIR)
endif

make clean:
	rm -f $(EXE_DIR)/*
	rm -f $(OBJECTS_DIR)/*

make rebuild: clean all