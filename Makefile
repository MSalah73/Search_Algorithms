TESTING ?= 0
CFLAGS =

ifeq ($(TESTING), 1)
CFLAGS += -DON
endif

all:
	g++ *.cpp -Wall -g $(CFLAGS) -o Searching_Algorithms

clean:
	rm Searching_Algorithms
