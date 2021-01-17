CC=gcc
AR=ar
FLAGS=-Wall -g

all: main.o trie.o frequency
frequency: main.o trie.o 
	$(CC) $(FLAGS) main.o trie.o -o frequency
main.o: main.c trie.h
	$(CC) $(FLAGS) -c main.c -o main.o
trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c  -o trie.o


clean:
	rm -f *.o *.txt frequency
