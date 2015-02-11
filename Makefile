CC=clang++
CFLAGS=-c -std=c++11 -stdlib=libc++ -I eigen -I include

all: test

test: test.o
	$(CC) test.o -o test

test.o: src/test.cpp include/PCA.hpp
	$(CC) $(CFLAGS) src/test.cpp
