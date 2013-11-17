COMPILER = g++
FLAGS = -std=c++0x -Wall -g -ggdb
OUTPUTNAME0 = lab08
OUTPUTNAME1 = palindrome

all: $(OUTPUTNAME0) $(OUTPUTNAME1)

$(OUTPUTNAME0): BigOh.o
	$(COMPILER) $(FLAGS) -o $(OUTPUTNAME0) BigOh.o

$(OUTPUTNAME1): Driver.o
	$(COMPILER) $(FLAGS) -o $(OUTPUTNAME1) Driver.o

Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp

BigOh.o : BigOh.cpp
	$(COMPILER) $(FLAGS) -c BigOh.cpp

clean:
	rm -rf *.o $(OUTPUTNAME0) $(OUTPUTNAME1)