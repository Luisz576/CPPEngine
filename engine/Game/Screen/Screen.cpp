#include "Screen.hpp"

Screen::Screen(){

}

Screen::~Screen(){
    
}

void Screen::update(const float &dt){
    this->onUpdateScreen(dt);
    for(auto it : this->_gameComponents)
        it->update(dt);
}

void Screen::render(Drawer *drawer){
    for(auto it : this->_gameComponents)
        it->render(drawer);
}

void Screen::registerGameComponent(GameComponent *gameComponent){
    std::vector<GameComponent*>::iterator v = std::find(this->_gameComponents.begin(), this->_gameComponents.end(), gameComponent);
    if(v == this->_gameComponents.end()){
        this->_gameComponents.push_back(gameComponent);
        gameComponent->onRegistered(this);
    }
}

void Screen::unregisterGameComponent(GameComponent *gameComponent){
    std::vector<GameComponent*>::iterator v = std::find(this->_gameComponents.begin(), this->_gameComponents.end(), gameComponent);
    if(v != this->_gameComponents.end()){
        this->_gameComponents.erase(v);
        gameComponent->onUnregistered(this);
    }
}

void Screen::onStartScreen(){}

void Screen::onEndScreen(){}

void Screen::onUpdateScreen(const float &dt){}