// WordCounter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Word.h"

using namespace std;

string PATH = "../WordCounter/text.txt";

int main()
{
	Word word;

	cout << word.read_file(PATH) << endl << endl;

	map<string, int> cw = word.count_words();

	cout << word.format_output() << endl;

	cout << endl << word.read_file(PATH) << endl << endl;

	cw = word.count_words();

	cout << word.format_output() << endl;

	return EXIT_SUCCESS;
}
