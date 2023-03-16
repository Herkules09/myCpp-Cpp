#include "WordleWord.h"


WordleWord::WordleWord() {
	WordsBase wb;
	wordleWord = wb.getRandomWord();
}

string WordleWord::getWordleWord() {
	return wordleWord;
}