CC=g++
objects = pureClassDemoImp.o

CFLAGS+=-g -Wall -DDEBUG



all:$(objects)
#	$(CC) $<

debug:
	$(CC) $(objects).cpp $(CFLAGS) -o $(objects).debug

.PHONY:clean
clean:
	rm -rf $(objects) $(objects).debug
