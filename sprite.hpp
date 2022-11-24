#pragma once

#include <SFML/Graphics.hpp>

class Sprite
{
private:
    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect rect;
public:
    void display_background();
}; 


