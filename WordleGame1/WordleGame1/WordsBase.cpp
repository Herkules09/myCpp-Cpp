#include "WordsBase.h"


LinkedList<string> WordsBase::getWords() {
	
	LinkedList<string> words;
	string w;
	ifstream file("words.txt");
	if (!file.is_open()) cout << "Plik nie zostal odworzony" << endl;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> w;
			if (isValidWord(toUpperCase(w))) {
				words.push(w);
			}
			

		}

	}
	file.close();
	this->words = words;
	return words;
}

string WordsBase::getRandomWord()
{
	return getWords().getRandomElement();
}


