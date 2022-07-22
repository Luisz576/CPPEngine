#ifndef GAME_HPP

#define GAME_HPP

#include "Screen/Screen.hpp"
#include "GameConfigs.hpp"

class Game{
    sf::Clock clock;
    float delta;

    sf::Event sfEvent;

    void initWindowAndDrawer();
    void updateSFMLEvents();
    void _update();
    void _render();

protected:
    sf::RenderWindow *window;
    std::stack<Screen*> screens;
    Drawer *drawer;
    GameConfigs *config;

public:
    Game(GameConfigs *config);
    virtual ~Game();

    void newScreen(Screen *screen);
    void popScreen();

    void run();

    virtual void update(const float &dt) = 0;
    
    virtual void onStartGame();
    virtual void onStopGame();
    virtual void onCloseGame();
};

#endif