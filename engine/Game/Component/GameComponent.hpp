#ifndef GAMECOMPONENT_HPP

#define GAMECOMPONENT_HPP

class Screen;

#include "../Drawer/Drawer.hpp"

class GameComponent{
public:
    GameComponent();
    virtual ~GameComponent();

    virtual void update(const float &dt);
    virtual void render(Drawer *drawer);

    virtual void onRegistered(Screen *screen);
    virtual void onUnregistered(Screen *screen);
};

#endif