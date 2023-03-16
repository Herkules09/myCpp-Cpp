#include "Validation.h"

#include "Validation.h"

bool Validation::isValidWord(string word) {
	return (word.length() == 5 && word.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUWVXYZ") == string::npos);
}

string Validation::toUpperCase(string& word) {
	transform(word.begin(), word.end(), word.begin(), ::toupper);
	return word;
}
