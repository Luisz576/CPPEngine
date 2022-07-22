#ifndef GAMECONFIGS_HPP

#define GAMECONFIGS_HPP

#include <string>
#include "../Utils/Vector2D.hpp"

struct GameConfigs{
    std::string title;
    Vector2D *window_size;
    unsigned framerate_limit;
    bool vertical_sync_enabled;

    GameConfigs();
    GameConfigs(char* title, Vector2D &window_size, unsigned framerate_limit, bool vertical_sync_enabled);
    virtual ~GameConfigs();
};

#endif