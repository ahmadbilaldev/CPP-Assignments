#include<iostream>
#include<string>
using namespace std;
int main()
{
	string firstWord, secondWord, thirdWord;
		
		cout << "Enter a word: ";
		cin >> firstWord;
		cout << "Enter a word again: ";
		cin >> secondWord;
		cout << "Enter a word again: ";
		cin >> thirdWord;
		
		cout << firstWord << " " << secondWord << " " << thirdWord << endl;
		cout << secondWord << " " << thirdWord << " " << firstWord << endl;
		cout << secondWord << " " << firstWord << " " << thirdWord << endl;
		cout << firstWord << " " << thirdWord << " " << secondWord << endl;
		cout << thirdWord << " " << firstWord << " " << secondWord << endl;
		cout << thirdWord << " " << secondWord << " " << firstWord;
		
	return 0;
}
