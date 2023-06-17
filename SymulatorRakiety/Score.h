#ifndef SCORE_H
#define SCORE_H
#include"Header.h"
#include"Game.h"
#include"DEFINITIONS.h"
class Score
{
private:
	GameDataRef data;
	int actual_score;
	int hight_score;
	sf::Text* score_text;
	std::vector<std::string>history_scores;
	std::vector<sf::Text*>history_scores_text;
	void initText();
public:

	Score(GameDataRef data);
	~Score();
	void setActualScore(int score);
	void setHightScore(int score);
	const int& getActualScore() const;
	const int& getHightScore() const;
	std::vector<std::string> getScoresFromFile(std::string pathname, std::string hightscory_path);
	std::vector<std::string> getScores();
	
	void saveScores();
	void resetScores();
};

#endif
