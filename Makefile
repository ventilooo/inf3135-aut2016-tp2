CC = gcc
CFLAGS = `pkg-config --cflags jansson`
LFLAGS = `pkg-config --libs jansson`
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
	git submodule init ./data/countries
	git submodule update ./data/countries
