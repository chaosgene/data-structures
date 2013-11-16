#include <iostream>
#include <fstream>
#include "Lab04.h"
#include <regex>
using namespace std;
int main(int argc, char* argv[])
{
	Lab04 lab4;
	
	
	
	std::string currLine;
	ifstream mybook(argv[1]);
	ofstream newbook(argv[2]);
	
	int totalWords = 0;
	int totalChanges = 0;
	if (mybook.is_open() && newbook.is_open())
	{
		while (getline(mybook,currLine))
		{
			totalWords += lab4.countWords(currLine);
			totalChanges += lab4.replaceStrings(currLine, "people", "zombie");
			totalChanges += lab4.replaceStrings(currLine, "wounded", "bitten");
			totalChanges += lab4.replaceStrings(currLine, "died", "turned");
			totalChanges += lab4.replaceStrings(currLine, "die", "turn");
			totalChanges += lab4.replaceStrings(currLine, "bullets", "teeth marks");
			totalChanges += lab4.replaceStrings(currLine, "cannon ball", "plague bomb");
			totalChanges += lab4.replaceStrings(currLine, "cannon", "infected");
			totalChanges += lab4.replaceStrings(currLine, "bayonet", "pitchfork");
			totalChanges += lab4.replaceStrings(currLine, "Prince", "Leiche");
			totalChanges += lab4.replaceChars(currLine, "gloom", "GLOOM");
			totalChanges += lab4.replaceChars(currLine, "happy", "HAPPY");
			totalChanges += lab4.replaceChars(currLine, "vanish", "vAnIsH");
			//cout << currLine << endl;
			newbook << currLine << endl;
		}
		mybook.close();
		newbook.close();
	}
	//cout << "Total Words: " << totalWords << endl;
	//cout << "Total Changes: " << totalChanges << endl;
	cout << "Processing " << argv[1] << " resulted in change rate of " << 100 * ((float) totalChanges / (float) totalWords) << "%" << endl;
	
	return 0;
}
