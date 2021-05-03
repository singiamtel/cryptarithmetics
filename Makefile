CC=g++
CFLAGS=-O3

all: 
	$(CC)  $(CFLAGS) -o crypt src/cryptarithmics.cpp
