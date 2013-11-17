#include <iostream>
#include "Lab04.h"
#include <sstream>
using namespace std;

int Lab04::replaceStrings(string& str, const string& newWord, const string& to) {

	// don't change if it is followed by punctuation
    int replacements = 0;
	if(!newWord.empty())
	{
		size_t position = 0;
		while((position = str.find(newWord, position)) != string::npos) // Travel through the various positions where newWord occurs
		{
			//cout << "POSITION: " << position << endl;
			if ((position == 0) && (str.length() > newWord.length())) // When the string is at the beginning of the string and there are more characters in the total string
			{
				//cout << "this word has appeared at the beginning of the longer string" << endl;
				if (isSpace(str[newWord.length()]))
				{
					//cout << "this means the first word is followed by a space or punctuation and thus is valid" << endl;
					str.replace(position, newWord.length(), to); // Find the first occurrence and change it
					replacements += 1;
				}
				else // if what follows is invalid (not a whole word), update the position
				{
					position += to.length();
				}
			}
			else if ((position == str.length() - newWord.length()) && (str.length() > newWord.length()))// when string is at the end and there are more characters in the total string
			{
				//cout << "this word has appeared at the end of the longer string" << endl;
				if (isSpace(str[str.length()-(newWord.length() + 1)]))
				{
					//cout << "this means the last word is preceded by a space or punctuation and thus is valid" << endl;
					str.replace(position, newWord.length(), to); // Find the first occurrence and change it
					replacements += 1;
				}
				else // if what precedes is invalid (not a whole word), update the position
				{
					position += to.length();
				}
			}
			// consider if a string is the only item in the array
			else if (str.length() == newWord.length())
			{
				//cout << "this word is the only thing in this string so it's okay to replace it" << endl;
				str.replace(position, newWord.length(), to); // Find the first occurrence and change it
				replacements += 1;
			}
			// left with the scenario that the string is NOT at the beginning or the end of a multi-substring string
			else
			{
				//cout << "this word is not at the beginning or the end of a longer string" << endl;
				// if bordering head and tail characters are valid
				//cout << "is preceding character: " << str[position-1] << " a space or punctuation mark? " << isSpace(str[position - 1]) << endl;
				//cout << "is following character: " << str[position + newWord.length()] << " a space or punctuation mark? " << isSpace(str[position + newWord.length()]) << endl;
				if (isSpace(str[position - 1]) && (isSpace(str[position + newWord.length()])))
				{
					str.replace(position, newWord.length(), to); // Find the first occurrence and change it
					replacements += 1;
				}
				else
				{
					position += to.length();
				}
			}
		}
	}
	return replacements;
}


int Lab04::replaceChars(string& str, const string& newWord, const string& to) {
    int replacements = 0;
	if(!newWord.empty())
	{
		size_t position = 0;
		while((position = str.find(newWord, position)) != string::npos) 
		{
			str.replace(position, newWord.length(), to);
			position += to.length(); 
			replacements += 1;
		}
	}
	return replacements;
}

int Lab04::countWords(std::string str)
{
	int numWords = 0;
	stringstream ss(str);
	string word;
	while (ss >> word)
		++numWords;
	return numWords;
}

bool Lab04::isSpace(char c)
{
	//return (ispunct(c) || (c == ' '));
	return (c == ' ');
}