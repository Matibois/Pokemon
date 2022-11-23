#include "window.hpp"

manage_window::manage_window() : window(sf::VideoMode(1000, 1000), "Pokemon")
{

}

bool manage_window::isOpen(void) const
{
    return this->window.isOpen();
}

void manage_window::manage_event(void)
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
    }
}

void open_close_window()
{
    manage_window w;

    while (w.isOpen())
    {
        w.manage_event();
    }

}