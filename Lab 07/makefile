COMPILER = g++
FLAGS = -std=c++0x -Wall -g -ggdb
OUTPUT_NAME1 = tester 
OUTPUT_NAME2 = grader
all: $(OUTPUT_NAME1) $(OUTPUT_NAME2)

$(OUTPUT_NAME1): Tester.o Random.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME1) Tester.o Random.o
$(OUTPUT_NAME2): Driver.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME2) Driver.o
Random.o : Random.cpp
	$(COMPILER) $(FLAGS) -c Random.cpp
Tester.o : Tester.cpp
	$(COMPILER) $(FLAGS) -c Tester.cpp
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
clean:
	rm -rf *.o $(OUTPUT_NAME1) $(OUTPUT_NAME2)

