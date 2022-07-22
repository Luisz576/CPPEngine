#ifndef SIMPLESPRITE_HPP

#define SIMPLESPRITE_HPP

#include "GameComponent.hpp"

class SimpleSprite : public GameComponent{
    sf::Texture *texture;
    sf::Sprite *sprite;

    void reloadSprite();

public:
    SimpleSprite(const char* path);
    SimpleSprite(const sf::Image &image);
    SimpleSprite(const sf::Image &image, const sf::IntRect &area);
    SimpleSprite(const void *data, std::size_t size);
    SimpleSprite(const void *data, std::size_t size, const sf::IntRect &area);
    SimpleSprite(sf::InputStream &stream);
    SimpleSprite(sf::InputStream &stream, const sf::IntRect &area);
    SimpleSprite(sf::Texture *texture);
    ~SimpleSprite();

    void update(const float &dt);
    void render(Drawer *drawer);

    sf::Texture* getTexture();

    void setPosition(Vector2D position);
    sf::Vector2f getPosition();

    bool setTexture(const char* path);
    void setTexture(const sf::Image &image, const sf::IntRect &area = sf::IntRect());
    void setTexture(const void *data, std::size_t size, const sf::IntRect &area = sf::IntRect());
    void setTexture(sf::InputStream &stream, const sf::IntRect &area = sf::IntRect());
    void setTexture(sf::Texture *texture);
};

#endif