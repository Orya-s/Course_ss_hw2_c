CC = gcc
AR = ar
OBJECTS_MAIN = main.o
FLAGS = -Wall -g


all: mymaths mains 

mymaths: libmyBank.a
	

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o


mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a


main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c


.PHONY: clean

clean:
	rm -f *.o *.a *.so mains 
