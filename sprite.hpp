#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdbool>

class manage_sprite
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect rect;
public:
    manage_sprite(std::string file, sf::IntRect rect, double x, double y, float posx, float posy);

    sf::Sprite &get_sprite();
    const sf::Sprite& get_sprite() const;
};