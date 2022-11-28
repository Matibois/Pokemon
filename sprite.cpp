#include "window.hpp"
#include "sprite.hpp"

manage_sprite::manage_sprite(std::string file, sf::IntRect rect, int x, int y)
{
    this->texture.loadFromFile(file);
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(rect);
    this->sprite.setScale(x, y);
}

sf::Sprite &manage_sprite::get_sprite()
{
    return this->sprite;
}

const sf::Sprite &manage_sprite::get_sprite() const
{
    return this->sprite;
}