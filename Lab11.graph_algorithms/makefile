COMPILER = g++
FLAGS = -std=c++0x -Wall -g -Ofast
OUTPUTNAME1 = GraphLab

all: $(OUTPUTNAME1)

$(OUTPUTNAME1) : Graph.a Driver.o
	$(COMPILER) $(FLAGS) -o $(OUTPUTNAME1) Driver.o Graph.a
Graph.o : Graph.cpp Graph.h
	$(COMPILER) $(FLAGS) -c Graph.cpp
Graph.a : Graph.o
	ar -rcs Graph.a Graph.o
	rm Graph.o
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp 
clean:
	rm -rf *.o *.a $(OUTPUTNAME1)
