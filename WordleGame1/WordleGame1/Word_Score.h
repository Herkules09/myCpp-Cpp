#include"Header.h"
class Word_Score
{
private:
	string word;
    bool result;
public:
	Word_Score();
	Word_Score(string word, bool result);
	string getWord();
	bool getResult();
	void setWord(string word);
	void setResult(bool result);
};

