#include "GameConfigs.hpp"

GameConfigs::GameConfigs(){
    this->title = "None";
    this->window_size = new Vector2D(800, 600);
    this->framerate_limit = 120;
    this->vertical_sync_enabled = false;
}
GameConfigs::GameConfigs(char* title, Vector2D &window_size, unsigned framerate_limit, bool vertical_sync_enabled){
    this->title = title;
    this->window_size = new Vector2D(window_size.x, window_size.y);
    this->framerate_limit = framerate_limit;
    this->vertical_sync_enabled = vertical_sync_enabled;
}

GameConfigs::~GameConfigs(){
    delete this->window_size;
}