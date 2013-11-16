#ifndef LAB04_H
#define LAB04_H

/*
Name: Christopher Zhang
Lab: 04
Section: A51
*/
class Lab04{

private: 
	/*We have nothing that we need to keep private for this lab.*/

public:
	/*
		Replace all occurrences of a string within another string with the desired input.
	*/
	int replaceStrings(std::string& str, const std::string& from, const std::string& to);
	int countWords(std::string str);
	bool isSpace(char c);
	int floorAndCeiling(int input, int floor, int ceiling);
	int replaceChars(std::string& str, const std::string& newWord, const std::string& to);
};

#endif /* LAB04_H */
