CXX = clang++
CXXFLAGS = -std=c++14

BUILD_DIR = build
SRC_DIR = src

MAIN_SRC = main.cpp
MAIN_BIN = main
BFS_SRC = $(SRC_DIR)/bfs.cpp
BFS_OBJ = $(BUILD_DIR)/bfs.o

all: $(MAIN_BIN)

$(MAIN_BIN): $(MAIN_SRC) $(BFS_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BFS_OBJ): $(BFS_SRC)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf build

.PHONY:
	all clean
