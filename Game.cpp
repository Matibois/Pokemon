#include "Game.h"

Game::Game() : _window(sf::VideoMode(1000, 1000), "VENUSAUR")
{
    this->_window.setFramerateLimit(60);
}

bool Game::isOpen(void) const
{
    return this->_window.isOpen();
}

void Game::handleEvents(void)
{
    sf::Event event;
    while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->_window.close();
    }
}

void Game::clear(void)
{
    this->_window.clear();
}

void Game::display(void)
{
    this->_window.display();
}

void Game::drawEntity(const Entity& entity)
{
    this->_window.draw(entity.getSprite());
}