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
	if [ ! -d ./data/countries ]; then git submodule add https://github.com/ablondin/countries.git/ ./data/countries ; fi
	git submodule init ./data/countries
	git submodule update ./data/countries
