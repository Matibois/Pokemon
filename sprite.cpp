#include "window.hpp"
#include "sprite.hpp"

manage_sprite::manage_sprite()
{
    this->texture.loadFromFile("background.jpg");
    this->rect = sf::IntRect(0, 0, 800, 600);
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(rect);
}

sf::Sprite &manage_sprite::get_sprite()
{
    return this->sprite;
}

const sf::Sprite &manage_sprite::get_sprite() const
{
    return this->sprite;
}