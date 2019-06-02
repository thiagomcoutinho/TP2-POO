H_D = ./Headers/
S_D = ./Source/

RM=rm -f

OBJS=main.o Interface.o 

main:	$(OBJS)
	g++ -std=c++11 -lncurses $(OBJS) -o main

main.o:	main.cpp
	g++ -std=c++11 -c main.cpp

Interface.o:	main.cpp $(S_D)Interface.cpp	$(H_D)Interface.h
	g++ -std=c++11 -c main.cpp $(S_D)Interface.cpp 

clean: 
	$(RM) $(OBJS)