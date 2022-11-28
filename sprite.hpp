#pragma once

#include <SFML/Graphics.hpp>


class manage_sprite
{
private:
    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect rect;
public:
    manage_sprite();

    sf::Sprite &get_sprite();
    const sf::Sprite& get_sprite() const;
};