#include "Drawer.hpp"

Drawer::Drawer(sf::RenderWindow *window){
    this->window = window;
}

Drawer::~Drawer(){
    
}

void Drawer::drawRect(const Vector2D position, const Vector2D size, sf::Color &color){
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(size.x, size.y));
    shape.setPosition(position.x, position.y);
    shape.setFillColor(color);
    this->window->draw(shape);
}

void Drawer::drawCircle(const Vector2D position, const float &r, sf::Color &color){
    sf::CircleShape shape(r);
    shape.setPosition(position.x, position.y);
    shape.setFillColor(color);
    this->window->draw(shape);
}

void Drawer::drawText(const Vector2D position, const char* text, int size, sf::Font font, sf::Color &color, TextStyle style){
    sf::Text t;
    t.setString(text);
    t.setPosition(position.x, position.y);
    t.setCharacterSize(size);
    t.setFont(font);
    t.setStyle(style);
    t.setFillColor(color);
    this->window->draw(t);
}

void Drawer::draw(const sf::Drawable &drawable){
    this->window->draw(drawable);
}