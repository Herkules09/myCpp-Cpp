#include "Header.h"
#include"Wordle.h"



void clear() {
	cout << "\x1B[2J\x1B[H";
}

bool play_again() {
	char decision;
	cout << endl << "Do you want to play again?" << endl;
	cout << "(Y/N)";
	cin >> decision;
	if (decision == 'Y') {
		clear();
		return true;
		
	}
	else {
		return false;
		
	}
}

struct result {
	string word;
	bool wynik;
	int tries;
};

void writeToFile(list<result>w) {
	ofstream f;
	f.open("results.txt", ios::out | ios::app);
	if (!f.is_open()) {
		cout << "Nie udalo sie otworzyc pliku";
	}
	for (result t:w) {
		f << "Word: " << t.word << " wynik: " << t.wynik << " proba: " << t.tries << endl;
	}
	
}



int main()
{
	vector<pair<string, bool>>pairs;
	list<result>wyniki;
	
    bool x;
	do {
		Wordle w;
		x=play_again();
		result op;
		string k = w.getWord();
		bool s = w.getWinCondition();
		pair<string, bool>p = { w.getWord(),w.getWinCondition() };
		op.word = k;
		op.wynik=s;
		op.tries = w.proba;
		wyniki.push_back(op);
		pairs.push_back(p);
	} while (x);
	cout << "SCORE" << endl;
	
		auto print = [pairs](int i) {

			cout << pairs[i].first << " - ";
			if (pairs[i].second == true) {
				cout << "GUESSED" << endl;
			}
			else {
				cout << "UNGUESSED" << endl;
			}
		};
		for (size_t i = 0; i < pairs.size(); ++i) {
			print(i);
		}

		writeToFile(wyniki);
}
	
	


	

