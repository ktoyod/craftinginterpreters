CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BIN = a.out

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f *.o $(BIN)
