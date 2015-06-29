# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
	CLEANUP          := del /F /Q
	MKDIR            := mkdir
	TARGET_EXTENSION := .exe
else
	CLEANUP          := rm -rf
	MKDIR            := mkdir -p
	TARGET_EXTENSION :=
endif


UNITY_ROOT := ../../../../Unity
C_COMPILER := gcc

CFLAGS = -std=c11
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -Wmissing-prototypes
CFLAGS += -Wmissing-declarations
CFLAGS += -g
CFLAGS += -ftest-coverage
CFLAGS += -fprofile-arcs

TARGET_BASE := test_sprintf
TARGET       = $(TARGET_BASE)$(TARGET_EXTENSION)

SRC_FILES = \
	$(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
	$(UNITY_ROOT)/src/unity.c \
	../test/SprintfTest.c \
	../test/SprintfTestRunner.c \
	../test/AllTests.c

INC_DIRS = -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS  =


all: clean tests cover


build/$(TARGET):	test/*.c
	@$(MKDIR) build
	@$(MKDIR) build/cover
	@echo "Compiling"; cd build; $(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES) -o $(TARGET)

.PHONY: tests
tests: build/$(TARGET)
	@echo "Running tests"; ./build/$(TARGET)

.PHONY: cover
cover: tests
	@echo "Preparing coverage"; cp build/*.gc* test/
	@echo "Running coverage"; cd test; gcovr -r . -b -p --html --html-details -o ../build/cover/test.html
	@echo "Clearing intermediate files"; rm test/*.gc* build/*.gc*


.PHONY: clean
clean:
	@echo "Cleaning $<"; $(CLEANUP) build

