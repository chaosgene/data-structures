COMPILER = g++
FLAGS = -std=c++0x
OUTPUT_NAME = labone.exe
all: Driver.o Lab01.o
	$(COMPILER) $(FLAGS) -o $(OUTPUT_NAME) Driver.o Lab01.o
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
Lab01.o : Lab01.cpp
	$(COMPILER) $(FLAGS) -c Lab01.cpp	
clean:
	rm -rf *.o $(OUTPUT_NAME)
