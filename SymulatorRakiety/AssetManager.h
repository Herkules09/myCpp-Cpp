#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include"Header.h"
class AssetManager
{
private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::SoundBuffer>soundBuffers;


public:
	AssetManager() { }
	~AssetManager() { }

	void loadTexture(std::string name, std::string fileName);
	sf::Texture& getTexture(std::string name);

	void loadFont(std::string name, std::string fileName);
	sf::Font& getFont(std::string name);

	void loadSoundBuffer(std::string name, std::string fileName);
	sf::SoundBuffer& getSoundBuffer(std::string name);

};
#endif