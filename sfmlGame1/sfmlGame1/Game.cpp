#include "Game.h"

void Game::initVariables()
{
    this->window = nullptr;
  
    //Game logic
    this->points = 0;
    this->endGame = false;
    this->health = 20;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
    this->mouseHeld = false;

}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	
	this->window = new sf::RenderWindow(this->videoMode, "Aim Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initFont()
{
    if (this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
        std::cout << "ERROR::GAME::INITFONTS::Failed to load font" << "\n";
    }
}

void Game::initText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::White);
    
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f,100.f));
    //this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
   // this->enemy.setOutlineColor(sf::Color::Red);
   //this->enemy.setOutlineThickness(1.f);


}

Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->initFont();
    this->initText();
    this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}




const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
    return this->endGame;
}

void Game::spawnEnemy()
{
    /*
     @ return void

     Spawns enemies and sets their types,colors and their positions randomly.
     -Set a random type
     -Sets a random position
     -Sets a random color 
     -Adds enemy to vector
    */
    this->enemy.setPosition(
      static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
      0.f
    );

    //Randomize enemy type
    int type = rand() % 5;

    switch (type) {
        
    case 0:
        this->enemy.setSize(sf::Vector2f(20.f, 20.f));
        this->enemy.setFillColor(sf::Color::Magenta);
        break;
    case 1:
        this->enemy.setSize(sf::Vector2f(40.f, 40.f));
        this->enemy.setFillColor(sf::Color::Blue);
        break;
    case 2:
        this->enemy.setSize(sf::Vector2f(50.f, 50.f));
        this->enemy.setFillColor(sf::Color::Cyan);
        break;
    case 3:
        this->enemy.setSize(sf::Vector2f(60.f, 60.f));
        this->enemy.setFillColor(sf::Color::Red);
        break;
    case 4:
        this->enemy.setSize(sf::Vector2f(70.f, 70.f));
        this->enemy.setFillColor(sf::Color::Green);
        break;

    default:
        this->enemy.setSize(sf::Vector2f(100.f, 100.f));
        this->enemy.setFillColor(sf::Color::Yellow);
        break;
    }

    //Spawn the enemy
    this->enemies.push_back(this->enemy);

    //Remove enemies at the end of the screen


}

void Game::poolEvents()
{
    //Event polling
    while (this->window->pollEvent(this->ev)) {

        switch (this->ev.type) {

        case sf::Event::Closed:
           this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            break;
        }
    }
}

void Game::updateText()
{
    std::stringstream ss;
    
    ss << "Points: " << this->points<<"\n"
        <<"Health: "<<this->health;
    this->uiText.setString(ss.str());
}

void Game::updateMousePosition()
{
    /*
    @ return void 

    Updates the mouse positions:
    - Mouse position relative to window (Vector2i)
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}

void Game::updateEnemies()
{
    /*
     @ return void 

     Update the enemy spawn timer and spawn enemies
     when the total amount of enemies is smaller than the maximum.
     Moves the enemies downwards.
     Removes the enemies at the edge of the screen

    */

    //Updating the timer for the enemy spawning
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else {
            this->enemySpawnTimer += 1.f;
        }
    }
    //Moving and updating enemies
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;
        this->enemies[i].move(0.f, 3.f);

        if (this->enemies[i].getPosition().y > this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
        }

    }

    //Check if clicked upon
   
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        if (this->mouseHeld==false) {
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++) {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {

                    //Gain points
                    if (this->enemies[i].getFillColor() == sf::Color::Magenta) {
                        this->points += 10;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Blue) {
                        this->points += 7;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Cyan) {
                        this->points += 5;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Red) {
                        this->points += 3;
                    }
                    else if (this->enemies[i].getFillColor() == sf::Color::Green) {
                        this->points += 1;
                    }
                    


                    //Deleted the enemy
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);
                   
                }
            }
        }

    }
    else {
        this->mouseHeld = false;
    }
   
}

void Game::update()
{
    this->poolEvents();
    if (this->endGame==false) {
        this->updateMousePosition();
        this->updateEnemies();
        this->updateText();
    }
   //Emd game condition
    if (this->health <= 0) {
        this->endGame = true;
    }
}

void Game::renderText(sf::RenderTarget & target)
{
    target.draw(this->uiText);
}

void Game::renderEnemies(sf::RenderTarget& target)
{
    for (auto& e : this->enemies) {
        target.draw(e);
    }
}

void Game::render()
{
    /* 
       - clear old frame
       - render objects
       -display frame in window

       Renders the game objects.
    */

    this->window->clear();
    //Draw game
    
    this->renderEnemies(*this->window);
    this->renderText(*this->window);
    this->window->display();
}
