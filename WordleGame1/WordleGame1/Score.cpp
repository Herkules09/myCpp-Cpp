#include "Score.h"



Score::Score()
{
}

void Score::add_score(Word_Score wordScore){
	this->results.push_back(wordScore);
}


void Score::print_results() {
	vector<Word_Score>::iterator it=this->results.begin();

	while (it != results.end()) {
		cout << it->getWord() << " - ";
		if (it->getResult() == true) {
			cout << "GUESSED" << endl;
		}
		else {
			cout << "NOT GUESSED" << endl;
		}
		++it;
	}
}
