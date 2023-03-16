#include"Header.h"
#include"WordleWord.h"
#include"Score.h"
class Wordle
{
private:
	bool winCondition = false;
	WordleWord wordleW;
	
	

public:
	int proba = 1;
	void isWordleWordEqualTo(string guessedWord);
	void play();
	string getWord();
	bool getWinCondition();
	Wordle();
	Wordle(const Wordle&w);
};

