#include "AssetManager.h"



void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
	{
		this->textures[name] = tex;
	}
	else {
		throw "Cannot load texture from file\n";
	}
}

sf::Texture& AssetManager::getTexture(std::string name)
{
	return this->textures.at(name);
}

void AssetManager::loadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
	}
	else {
		throw "Cannot load font from file\n";
	}
}

sf::Font& AssetManager::getFont(std::string name)
{
	return this->fonts.at(name);
}

void AssetManager::loadSoundBuffer(std::string name, std::string fileName)
{
	sf::SoundBuffer soundBuffer;
	
	if (soundBuffer.loadFromFile(fileName)) {
		this->soundBuffers[name] = soundBuffer;
	}
	else {
		throw "Cannot load sound from file\n";
	}
}

sf::SoundBuffer& AssetManager::getSoundBuffer(std::string name)
{
	return this->soundBuffers.at(name);
}
