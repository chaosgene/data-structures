#include <iostream>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

bool isPalindrome(string s);

int main( int argc, char* argv[])
{
	string s;
	int linecount = 0;
	ifstream foofile(argv[1]);
	if (foofile.is_open())
	{
		while (getline(foofile, s))
		{
			linecount++;
			if (isPalindrome(s))
				cout << linecount << endl;
		}
	}
	else cout << "Unable to open file";
	return 0;
}

bool isPalindrome(string s)
{
	deque<char> dq0;
	for (char &c : s)
	{
		if (isalnum(c)) // Ignore whitespace and non-alphanums
			dq0.push_back(c);
	}
	
	int strSize = dq0.size();
	if (strSize <= 1) // If the result is empty or has a single char, return true
		return true;
	
	for (int i = 0; i < (strSize / 2) + 1; ++i)
	{
		if (dq0[i] != dq0[strSize - i - 1]) // Check if the first element is the same as the last, and so forth
		{
			return false;
		}
	}
	return true;
}
