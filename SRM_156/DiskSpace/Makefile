#Main makefile which does the build
CXXFLAGS := -Wall -W -std=c++11
RM := rm -f

SRC := DiskSpace.cpp

EXT := .out
REL_OUT := release$(EXT)
DBG_OUT := debug$(EXT)

all: release
	
release : $(REL_OUT)
debug : $(DBG_OUT)

define build
	@echo $(SRC)
	@echo "Building..."
	$(CXX) $(CXXFLAGS) $< -o $@
endef

$(DBG_OUT): CXXFLAGS += -DDEBUG -g3
$(DBG_OUT): $(SRC)
	@echo "Debug build"
	$(call build)

$(REL_OUT): CXXFLAGS +=  -O2 -s -pipe
$(REL_OUT): $(SRC)
	@echo "Release build"
	$(call build)

run: release
	./$(REL_OUT)

clean:
	@echo "Cleaning..."
	$(RM) *$(EXT)

.PHONY: all debug release run clean
