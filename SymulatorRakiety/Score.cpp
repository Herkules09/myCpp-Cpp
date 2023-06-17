#include "Score.h"

void Score::initText()
{
	this->score_text->setFillColor(sf::Color::White);
	this->data->assets.loadFont("Game font", FONT_FILEPATH);
	this->score_text->setFont(data->assets.getFont("Game font"));

}

Score::Score(GameDataRef data):data(data)
{
	this->history_scores = this->getScoresFromFile(HISTORY_SCORES_PATH, HIGHTSCORE_PATH);
}

Score::~Score()
{
}

void Score::setActualScore(int score)
{
	this->actual_score = score;
	this->history_scores.push_back(std::to_string(score));
	if (score > this->hight_score) {
		setHightScore(score);
	}
}

void Score::setHightScore(int score)
{
	this->hight_score = score;
}

const int& Score::getActualScore() const
{
	return this->actual_score;
}

const int& Score::getHightScore() const
{
	return this->hight_score;
}

std::vector<std::string> Score::getScoresFromFile(std::string pathname,std::string hightscory_path)
{
	const int number_of_scores = NUMBER_OF_HISCORY_SCORES;
	std::vector<std::string>scores;
	std::string tmp;
	std::ifstream file(pathname);
	std::string l[number_of_scores];
	int size = 0;
	
	std::ifstream hightscory_file(hightscory_path);
	if (hightscory_file.is_open()) {
		hightscory_file >> this->hight_score;
	}


	while (file.good()) {
		getline(file, l[size % number_of_scores]);
		size++;
	}

	int start = size > number_of_scores ? (size % number_of_scores) : 0; 
	int count = std::min(number_of_scores, size); 

	for (int i = 0; i < count; i++) {
		scores.push_back(l[(start + i) % number_of_scores]);
	}
	return scores;
}

std::vector<std::string> Score::getScores()
{
	return this->history_scores;
}


void Score::saveScores()
{
	std::string folderPath = FOLDER_SCORES_NAME;
		;
	fs::path cel = fs::path(fs::current_path()/ folderPath);
	if (!fs::exists(cel)) {
		fs::create_directory(FOLDER_SCORES_NAME);
	}
	std::string scores = folderPath + "/historyScores.txt";
	std::string hightScore = folderPath + "/hightScore.txt";

	std::ofstream file(scores);
	std::ofstream hightscore_file(hightScore,std::ios::trunc);
	if (file.is_open()) {
		for (size_t i = 0; i < this->history_scores.size(); i++)
		{
			file << this->history_scores[i] << std::endl;
		}
	}
	file.close();
	if (hightscore_file.is_open()) {
		hightscore_file << this->hight_score;
	}

}

void Score::resetScores()
{
	fs::remove(HISTORY_SCORES_PATH);
	fs::remove(HIGHTSCORE_PATH);
}


