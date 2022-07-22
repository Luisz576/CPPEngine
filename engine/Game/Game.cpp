#include "Game.hpp"

void Game::initWindowAndDrawer(){
    sf::VideoMode window_bounds(this->config->window_size->x, this->config->window_size->y);
    this->window = new sf::RenderWindow(window_bounds, this->config->title);
    this->window->setFramerateLimit(this->config->framerate_limit);
    this->window->setVerticalSyncEnabled(this->config->vertical_sync_enabled);

    this->drawer = new Drawer(this->window);
}

void Game::updateSFMLEvents(){
    this->delta = this->clock.restart().asSeconds();

    while(this->window->pollEvent(this->sfEvent)){
        if(this->sfEvent.type == sf::Event::Closed){
            this->onCloseGame();
            this->window->close();
        }
    }
}

void Game::_update(){
    this->updateSFMLEvents();

    this->update(this->delta);

    if(!this->screens.empty())
        this->screens.top()->update(this->delta);
    else{
        this->onStopGame();
        this->window->close();
    }
}

void Game::_render(){
    this->window->clear();

    if(!this->screens.empty())
        this->screens.top()->render(this->drawer);

    this->window->display();
}

Game::Game(GameConfigs *config){
    this->config = config;
}

Game::~Game(){
    delete this->drawer;
    delete this->window;
}

void Game::run(){
    this->initWindowAndDrawer();
    this->onStartGame();
    while (this->window->isOpen())
    {
        this->_update();
        this->_render();
    }
}

void Game::newScreen(Screen *screen){
    this->screens.push(screen);
    this->screens.top()->onStartScreen();
}

void Game::popScreen(){
    this->screens.top()->onEndScreen();
    delete this->screens.top();
    this->screens.pop();
}

void Game::onStartGame(){}

void Game::onCloseGame(){}

void Game::onStopGame(){}