CC=g++
CPPFLAGS=-ansi -pedantic -Wall -std=c++11
#DEFINEMAP= -DMAP
MAIN=MenuCatalogue
SRCS=logMap.cpp 
HEADERS=logMap.h

$(MAIN): $(SRCS) $(HEADERS)
	$(CC) -g  $(CPPFLAGS) $(DEFINEMAP) $(SRCS) -o $(MAIN)

.PHONY: clean
clean:
	rm *.o $(MAIN)
