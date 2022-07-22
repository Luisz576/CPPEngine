#include "SimpleSprite.hpp"

void SimpleSprite::reloadSprite(){
    this->sprite->setTexture(*this->texture);
}

SimpleSprite::SimpleSprite(const char* path){
    this->sprite = new sf::Sprite();
    this->setTexture(path);
}
SimpleSprite::SimpleSprite(const sf::Image &image){
    this->sprite = new sf::Sprite();
    this->setTexture(image);
}
SimpleSprite::SimpleSprite(const sf::Image &image, const sf::IntRect &area){
    this->sprite = new sf::Sprite();
    this->setTexture(image, area);
}
SimpleSprite::SimpleSprite(const void *data, std::size_t size){
    this->sprite = new sf::Sprite();
    this->setTexture(data, size);
}
SimpleSprite::SimpleSprite(const void *data, std::size_t size, const sf::IntRect &area){
    this->sprite = new sf::Sprite();
    this->setTexture(data, size, area);
}
SimpleSprite::SimpleSprite(sf::InputStream &stream){
    this->sprite = new sf::Sprite();
    this->setTexture(stream);
}
SimpleSprite::SimpleSprite(sf::InputStream &stream, const sf::IntRect &area){
    this->sprite = new sf::Sprite();
    this->setTexture(stream, area);
}
SimpleSprite::SimpleSprite(sf::Texture *texture){
    this->sprite = new sf::Sprite();
    this->texture = new sf::Texture();
    this->setTexture(texture);
}

SimpleSprite::~SimpleSprite(){
    delete this->sprite;
    delete this->texture;
}

sf::Texture* SimpleSprite::getTexture(){
    return this->texture;
}

void SimpleSprite::setPosition(Vector2D position){
    this->sprite->setPosition(position.x, position.y);
}

sf::Vector2f SimpleSprite::getPosition(){
    return this->sprite->getPosition();
}

void SimpleSprite::update(const float &dt){}

void SimpleSprite::render(Drawer *drawer){
    drawer->draw(*this->sprite);
}

bool SimpleSprite::setTexture(const char* path){
    this->texture = new sf::Texture();
    if(this->texture->loadFromFile(path)){
        this->reloadSprite();
        return true;
    }
    return false;
}
void SimpleSprite::setTexture(const sf::Image &image, const sf::IntRect &area){
    this->texture = new sf::Texture();
    this->texture->loadFromImage(image, area);
    this->reloadSprite();
}
void SimpleSprite::setTexture(const void *data, std::size_t size, const sf::IntRect &area){
    this->texture = new sf::Texture();
    this->texture->loadFromMemory(data, size, area);
    this->reloadSprite();
}
void SimpleSprite::setTexture(sf::InputStream &stream, const sf::IntRect &area){
    this->texture = new sf::Texture();
    this->texture->loadFromStream(stream, area);
    this->reloadSprite();
}
void SimpleSprite::setTexture(sf::Texture *texture){
    delete this->texture;
    this->texture = texture;
    this->reloadSprite();
}