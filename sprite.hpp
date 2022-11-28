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
    sf::Event event;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect rect;
public:
    manage_sprite(std::string file, sf::IntRect rect, int x, int y);

    sf::Sprite &get_sprite();
    const sf::Sprite& get_sprite() const;
};