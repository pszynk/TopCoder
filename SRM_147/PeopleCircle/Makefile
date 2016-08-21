#Main makefile which does the build
CXXFLAGS := -Wall -W -std=c++11
RM := rm -f

ALL_SRC := $(wildcard *.cpp)
OUT_SRC := tester.cpp

SRC := $(filter-out $(OUT_SRC),$(ALL_SRC))

EXT := .out
REL_OUT := release$(EXT)
DBG_OUT := debug$(EXT)
EXC_OUT := a.out

all: release

build: $(SRC)
	@echo $(SRC)
	@echo "Building..."
	$(CXX) $(CXXFLAGS) $< -o $(EXC_OUT)

debug: CXXFLAGS += -DDEBUG -g3
debug: EXC_OUT := $(DBG_OUT)
debug: build
	@echo "Debug build"

release: CXXFLAGS +=  -O2 -s -pipe
release: EXC_OUT := $(REL_OUT)
release: build
	@echo "Release build"

run: 
	./$(REL_OUT)

clean:
	@echo "Cleaning..."
	$(RM) *.out

.PHONY: build debug release run clean
