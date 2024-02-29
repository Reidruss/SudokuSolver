CC = g++ -Wall
BIN = solver

all: $(BIN)

solver: solver.cpp support.h support.cpp
	$(CC) $(CFLAGS) -o $@ solver.cpp support.cpp

clean:
	rm -f $(BIN)
