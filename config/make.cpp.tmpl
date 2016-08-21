# TODO comment

RM := rm -f

# -Wall -W -std=c++11
CXXFLAGS := -Wall -W -std=c++11

SRC := BinaryCode.cpp


REL_OUT := release.out



DBG_OUT := debug.out


OUT := $(REL_OUT) $(DBG_OUT)

all: release
release : $(REL_OUT)
debug : $(DBG_OUT)

define build
	@echo $(SRC)
	@echo "Building..."
	$(CXX) $(CXXFLAGS) $< -o $@
endef

# -DDEBUG -g3
$(DBG_OUT): CXXFLAGS += -DDEBUG -g3
$(DBG_OUT): $(SRC)
	@echo "Debug build"
	$(call build)

# -O2 -s -pipe
$(REL_OUT): CXXFLAGS +=  -O2 -s -pipe
$(REL_OUT): $(SRC)
	@echo "Release build"
	$(call build)

run: release
	./$(REL_OUT)

drun: debug
	./$(DBG_OUT)

clean:
	@echo "Cleaning..."
	$(RM) $(OUT)

.PHONY: all debug release run clean
