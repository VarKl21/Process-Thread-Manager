C=g++
CFLAGS=-std=c++11 -pthread

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)
BIN=bin/process_manager

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

debug: CFLAGS += -g
debug: $(BIN)

clean:
	rm -f $(OBJ) $(BIN)

install: $(BIN)
	cp $(BIN) /usr/local/bin/


























