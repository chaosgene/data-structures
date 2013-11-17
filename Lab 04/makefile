COMPILER = g++
FLAGS = -std=c++0x
OUTPUT_NAME = makeInteresting
all: Driver.o Lab04.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME) Driver.o Lab04.o
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
Lab04.o : Lab04.cpp
	$(COMPILER) $(FLAGS) -c Lab04.cpp	
clean:
	rm -rf *.o $(OUTPUT_NAME)