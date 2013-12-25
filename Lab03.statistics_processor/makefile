COMPILER = g++
FLAGS = -std=c++0x -Wall
OUTPUT_NAME1 = Lab03
OUTPUT_NAME2 = Lab03Test
all: $(OUTPUT_NAME1) $(OUTPUT_NAME2)

$(OUTPUT_NAME1): Driver.o StatisticsProcessor.o DynamicArray.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME1) Driver.o StatisticsProcessor.o \
    DynamicArray.o
$(OUTPUT_NAME2): Tester.o StatisticsProcessor.o DynamicArray.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME2) Tester.o StatisticsProcessor.o \
    DynamicArray.o
Tester.o : Tester.cpp
	$(COMPILER) $(FLAGS) -c Tester.cpp
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
StatisticsProcessor.o : StatisticsProcessor.cpp
	$(COMPILER) $(FLAGS) -c StatisticsProcessor.cpp	
DynamicArray.o : DynamicArray.cpp
	$(COMPILER) $(FLAGS) -c DynamicArray.cpp	

clean:
	rm -rf *.o $(OUTPUT_NAME1)

