H_D = ./Headers/
S_D = ./Source/

RM=rm -f

HDRS = $(H_D)Interface.h
SRCS=	main.cpp $(S_D)Interface.cpp
OBJS=	main.o Interface.o

main:	$(OBJS)
	g++ -std=c++11 -lncurses $(OBJS) -o main

main.o:	main.cpp
	g++ -std=c++11 -c main.cpp

Interface.o:	$(SRCS)	$(HDRS)
	g++ -std=c++11 -c $(SRCS) 

clean: 
	$(RM) $(OBJS)