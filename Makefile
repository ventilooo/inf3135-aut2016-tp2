CC = gcc
CFLAGS = -Wall
LFLAGS =
OBJECTS := $(patsubst %.c,%.o,$(wildcard src/*.c))
EXEC = bin/tp2
$(EXEC): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS) -ljansson
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
.PHONY: clean data

clean:
	rm -f $(EXEC) $(OBJECTS)

data:
	git submodule update --init --recursive ./data/countries
