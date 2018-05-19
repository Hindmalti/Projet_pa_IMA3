CC = gcc #Variable compilateur
CFLAGS = -Wall -Wextra -pedantic -g #Variable flags compilation
LDFLAGS = #Variable flags linkage (-lm par exemple pour la libmath )
SRC = $(wildcard *.c) #Variable contenant automatiquement la liste des .c SRC = table.c struct.c
OBJ = $(SRC:.c=.o) #Variable contenant la liste des .o en fonction des .c OBJ = table.o struct.o
EXEC = executable

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)

#Explication : google -> "devellopez.net makefile"
