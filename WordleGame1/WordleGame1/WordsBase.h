#ifndef WORDSBASE
#define WORDSBASE
#include"Header.h"
#include"Validation.h"
#include"LinkedList.h"
class WordsBase :public Validation
{
	LinkedList<string> words;
public:
	
	LinkedList<string> getWords();
	string getRandomWord();

};

#endif