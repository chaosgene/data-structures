COMPILER = g++
FLAGS = -std=c++0x -Wall -g
OUTPUTNAME1 = lab11

#all : run 
#run: $(OUTPUTNAME1)
#	./$(OUTPUTNAME1)

all: $(OUTPUTNAME1)

$(OUTPUTNAME1) : Graph.o Driver.o
	$(COMPILER) $(FLAGS) -o $(OUTPUTNAME1) Graph.o Driver.o
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp 
Graph.o : Graph.cpp
	$(COMPILER) $(FLAGS) -c Graph.cpp
clean:
	rm -rf *.o $(OUTPUTNAME1)
