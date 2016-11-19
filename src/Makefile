CC = gcc
CFLAGS = -Wall
LFLAGS =
OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))
EXEC = main
$(EXEC): $(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
.PHONY: clean
	clean:
	rm -f $(OBJECTS) $(EXEC)
