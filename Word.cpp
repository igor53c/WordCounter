#include "Word.h"

string Word::read_file(const string& filepath)
{
	ifstream datei(filepath, ios::in);
	char byte = 0;
	document = "";

	if (datei.fail())
		return document;

	while (datei.get(byte))
	{
		document += byte;
	}

	datei.close();

	return document;
}

map<string, int> Word::count_words()
{
	string word;
	string text;
	words_counted.clear();

	for (char c : document)
	{
		if (c == ',' || c == '.' ||
			c == '\n' || c == '\r')
			text += ' ';
		else
			text += c;
	}

	stringstream iss(text);

	while (iss >> word)
	{
		if (words_counted.find(word) != words_counted.end())
			words_counted[word] += 1;
		else
			words_counted[word] = 1;
	}

	return words_counted;
}

string Word::format_output()
{
	string retValue;
	int count = 0;

	for (const auto& c : words_counted)
	{
		count += c.second;

		retValue += "\t" + c.first + ": " + to_string(c.second) + ",\n";
	}

	retValue += "--------------------------\n";

	retValue += "Total Words: ";

	retValue += to_string(count);

	return retValue;
}

string Word::getDocument()
{
	return this->document;
}

map<string, int> Word::getWordsCounted()
{
	return this->words_counted;
}
