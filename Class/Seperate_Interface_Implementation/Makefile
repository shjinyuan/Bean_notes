CC=g++
objects = Person.o PersonImpl.o	test.o

CFLAGS+=-g -Wall -DDEBUG

target:$(objects)
	$(CC) $(objects) $(CFLAGS) -o test
	#--std=c++11

debug:
	$(CC) $(objects).cpp $(CFLAGS) -o $(objects).debug

.PHONY:clean
clean:
	rm -rf $(objects) $(objects).debug

