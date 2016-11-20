CC = gcc
CFLAGS = -Wall
LFLAGS =
OBJECTS := $(patsubst %.c,%.o,$(wildcard src/*.c))
EXEC = bin/tp2
$(EXEC): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
.PHONY: clean data

clean:
	rm -f $(EXEC) $(OBJECTS)

data:
	git submodule add git@github.com:ablondin/countries.git ../data
	git submodule init
	git submodule update

		
