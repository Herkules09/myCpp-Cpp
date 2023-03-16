#include"Header.h"
#include"Word_Score.h"
class Score
{
private:
	vector<Word_Score>results;

public:
	Score();
	void add_score(Word_Score wordScore);
	void print_results();
};

