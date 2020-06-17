CC=gcc
objects=strcut_constructor_self

CFLAGS+=-g -Wall -DDEBUG

all:$(objects)
#	$(CC) $<

debug:
	$(CC) $(objects).cpp $(CFLAGS) -o $(objects).debug

.PHONY:clean
clean:
	rm -rf $(objects) $(objects).debug
