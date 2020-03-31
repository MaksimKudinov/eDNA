#!/bin/bash
-std=c++11
#compil flag = -lglut -lGL

botworld: botworld.o food.o
	g++ $^ -lglut -lGL -o  $@
.cpp.o:
	g++ -c $<

botworld.o: botworld.cpp food.cpp food.h 
food.o: food.cpp food.h

clean:
	rm -i *.o botworld

install:
	cp botworld /usr/local/bin/botworld
uninstall: 
	rm -f /usr/local/bin/botworld
