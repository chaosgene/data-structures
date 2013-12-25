COMPILER = g++
FLAGS = -std=c++0x -Wall
OUTPUT_NAME1 = Lab03Test
all: $(OUTPUT_NAME1)

$(OUTPUT_NAME1): Tester.o StatisticsProcessor.o DynamicArray.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME1) Tester.o StatisticsProcessor.o \
    DynamicArray.o
Tester.o : Tester.cpp
	$(COMPILER) $(FLAGS) -c Tester.cpp
StatisticsProcessor.o : StatisticsProcessor.cpp
	$(COMPILER) $(FLAGS) -c StatisticsProcessor.cpp	
DynamicArray.o : DynamicArray.cpp
	$(COMPILER) $(FLAGS) -c DynamicArray.cpp	

clean:
	rm -rf *.o $(OUTPUT_NAME1)

