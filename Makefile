CC = gcc
CFLAGS = -Wall
OBJECTS := $(patsubst %.c,%.o,$(wildcard src/*.c))
TEST_OBJECTS := $(patsubst %.c,%.o,$(wildcard test/*.c))
EXEC = bin/tp2
EXEC_TEST = bin/test

$(EXEC): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS) -ljansson

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean data test

clean:
	rm -f $(EXEC) $(OBJECTS)

data:
	git submodule init
	git submodule update

test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $(EXEC_TEST) $(TEST_OBJECTS)
