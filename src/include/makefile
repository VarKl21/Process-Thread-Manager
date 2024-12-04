# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Target
TARGET = $(BUILD_DIR)/process_thread_manager

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) $^ -o $@

clean:
	rm -rf $(BUILD_DIR)/*
