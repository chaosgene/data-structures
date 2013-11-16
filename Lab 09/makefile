COMPILER = g++
FLAGS = -std=c++0x -Wall -g
OUTPUTNAME1 = lab09
all: $(OUTPUTNAME1)

$(OUTPUTNAME1): BinaryTree.a Driver.o
	$(COMPILER) $(FLAGS) -o $(OUTPUTNAME1) Driver.o BinaryTree.a
BinaryTree.o : BinaryTree.cpp BinaryTree.h 
	$(COMPILER) $(FLAGS) -c BinaryTree.cpp
BinaryTree.a : BinaryTree.o
	ar -rcs BinaryTree.a BinaryTree.o
	rm BinaryTree.o
Driver.o : Driver.cpp
	$(COMPILER) $(FLAGS) -c Driver.cpp
clean:
	rm -rf *.o *.a  $(OUTPUTNAME1)
