CC = g++
CFLAGS = -g -Wall -Wextra -pedantic -std=c++11

all: main

main: main.o string.o
	$(CC) $(CFLAGS) main.o string.o -o main

main.o: main.cpp string.h
	$(CC) $(CFLAGS) -c main.cpp

string.o: string.cpp string.h
	$(CC) $(CFLAGS) -c string.cpp

clean:
	rm -rf ./main ./*.o

cleantemp:
	rm -rf ./*~ ./.*~
