COMPILER = g++
FLAGS = -std=c++0x -Wall -g -ggdb
OUTPUT_NAME = lab06rand
all: Driver.o LinkedList.o Random.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME) Driver.o LinkedList.o Random.o
LinkedList.o : LinkedList.cpp
	$(COMPILER) $(FLAGS) -c LinkedList.cpp
Random.o : Random.cpp
	$(COMPILER) $(FLAGS) -c Random.cpp
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
clean:
	rm -rf *.o $(OUTPUT_NAME)