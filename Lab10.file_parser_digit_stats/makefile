COMPILER = g++
FLAGS = -std=c++0x -Ofast
OUTPUT_NAME = lab10

all: Driver.o LinkedLines.o 
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME) Driver.o LinkedLines.o
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
LinkedLines.o : LinkedLines.cpp
	$(COMPILER) $(FLAGS) -c LinkedLines.cpp
clean:
	rm -rf *.o $(OUTPUT_NAME)
