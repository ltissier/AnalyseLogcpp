CC=g++
CPPFLAGS=-ansi -pedantic -Wall -std=c++11
DEFINEMAP= -DMAP
MAIN = main
SRCS=logMap.cpp main.cpp logreader.cpp
HEADERS=logMap.h logreader.h

$(MAIN): $(SRCS) $(HEADERS)
	$(CC) -g  $(CPPFLAGS) $(DEFINEMAP) $(SRCS) -o $(MAIN)

