COMPILER = g++
FLAGS = -std=c++0x -Wall
OUTPUT_NAME = lab02a
all: Driver.o DynamicArray.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME) Driver.o DynamicArray.o
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
DynamicArray.o : DynamicArray.cpp
	$(COMPILER) $(FLAGS) -c DynamicArray.cpp	
clean:
	rm -rf *.o $(OUTPUT_NAME)