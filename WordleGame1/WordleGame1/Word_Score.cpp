#include "Word_Score.h"

Word_Score::Word_Score(){}


Word_Score::Word_Score(string word, bool result) {
	this->word = word;
	this->result = result;
}

string Word_Score::getWord() {
	return this->word;
}

bool Word_Score::getResult() {
	return this->result;
}

void Word_Score::setWord(string word) {
	this->word = word;
}

void Word_Score::setResult(bool result) {
	this->result = result;
}