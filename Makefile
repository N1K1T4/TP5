CC = g++
CFLAGS = -g -Wall -Wextra -pedantic -std=c++11

all: main

main: main.o String.o
	$(CC) $(CFLAGS) main.o String.o -o main

main.o: main.cpp String.h
	$(CC) $(CFLAGS) -c main.cpp

String.o: String.cpp String.h
	$(CC) $(CFLAGS) -c String.cpp

clean:
	rm -rf ./main ./*.o
