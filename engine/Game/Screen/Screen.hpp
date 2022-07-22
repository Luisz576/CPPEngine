#ifndef SCREEN_HPP

#define SCREEN_HPP

#include "../../lib/SFMLLibs.hpp"
#include "../Component/GameComponent.hpp"

class Screen{
protected:
    std::vector<GameComponent*> _gameComponents;

public:
    Screen();
    virtual ~Screen();

    void registerGameComponent(GameComponent *gameComponent);
    void unregisterGameComponent(GameComponent *gameComponent);

    void update(const float &dt);
    void render(Drawer *drawer);

    virtual void onStartScreen();
    virtual void onUpdateScreen(const float &dt);
    virtual void onEndScreen();
};

#endif