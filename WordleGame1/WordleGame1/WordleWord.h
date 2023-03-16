#ifndef WORDLEWORD
#define WORDLEWORD
#include"Header.h"
#include"WordsBase.h"

class WordleWord
{

public:
	const int WordleLentgh = 5;
	string wordleWord;

	WordleWord();
	string getWordleWord();
	WordleWord & operator =(const WordleWord& w)
	{
		if (&w != this)
		{}
		return *this;
	}
};

#endif 