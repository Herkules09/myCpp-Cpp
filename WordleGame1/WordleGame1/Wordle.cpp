#include "Wordle.h"


void Wordle::isWordleWordEqualTo(string guessedWord) {
	Validation v;
	
	bool grey=true;
	bool yellow=true;
	string wordleWord = wordleW.getWordleWord();
	
	const char* wordleCharacters = wordleWord.c_str();
	v.toUpperCase(guessedWord);
	const char* guessedCharacters = guessedWord.c_str();
	if (wordleWord == guessedWord) {
		winCondition = true;
		cout << "\033[32m" << guessedWord << " ";
	}
	else {
		for (int i = 0; i < 5; i++) {
			
			yellow = true;
			grey = true;
			if (guessedCharacters[i] == wordleCharacters[i]) {
				cout << "\033[32m" << guessedCharacters[i] << " ";
				
			}
			else {
				for (int j = 0; j < 5; j++) {
					if (guessedCharacters[i] == wordleCharacters[j]&& yellow) {
						cout << "\033[33m" << guessedCharacters[i] << " ";
						yellow = false;
						grey = false;
					}

				}
				if (grey) {
					cout << "\033[0m" << guessedCharacters[i] << " ";
				}
			}
		}
	}
	cout << "\033[0m";

}


void Wordle::play() {
	
		Validation v;
		int count = 0;
		string input;
		cout << "Enter a five-letter word" << endl;
		//cout << wordleW.getWordleWord();
		do {
			
			cin >> input;
			v.toUpperCase(input);
			
			if (v.isValidWord(input)) {
				++count;
				cout << count << ". ";
				
				
				isWordleWordEqualTo(input);
			}
			else {
				cout << "The entered word is incorrect. Enter again." << endl;
			}
			cout << endl << "----------" << endl;

			if (winCondition) {
				cout << "You win :) The word is " << wordleW.getWordleWord();
				break;
				
			}

			if (count == 5 && winCondition == false) {

				cout << "You lose :( The correct word is " << wordleW.getWordleWord();
				break;
				
			}
			proba++;
		} while (count <= 5 );
	
  
	
}




Wordle::Wordle() {
	
		play();
	
	}

Wordle::Wordle(const Wordle& w )
{
	winCondition = w.winCondition;
	wordleW = w.wordleW;
}


string Wordle::getWord() {
	return wordleW.getWordleWord();
}

bool Wordle::getWinCondition() {
	return winCondition;
}