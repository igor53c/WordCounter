#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Word
{
public:
	string read_file(const string& filepath);
	map<string, int> count_words();
	string format_output();

	string getDocument();
	map<string, int> getWordsCounted();

private:
	string document;
	map<string, int> words_counted;

};

