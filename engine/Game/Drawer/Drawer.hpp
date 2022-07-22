#ifndef DRAWER_HPP

#define DRAWER_HPP

#include "../../lib/SFMLLibs.hpp"

class Drawer{
    sf::RenderWindow *window;

public:
    enum TextStyle{
        UNDERLINE = sf::Text::Underlined,
        BOLD = sf::Text::Bold,
        ITALIC = sf::Text::Italic,
        STRIKETHROUGH = sf::Text::StrikeThrough,
        REGULAR = sf::Text::Regular
    };

    Drawer(sf::RenderWindow *window);
    virtual ~Drawer();

    void drawRect(const Vector2D position, const Vector2D size, sf::Color &color);
    void drawCircle(const Vector2D position, const float &r, sf::Color &color);
    void drawText(const Vector2D position, const char* text, int size, sf::Font font, sf::Color &color, TextStyle style = REGULAR);

    void draw(const sf::Drawable &drawable);
};

#endif