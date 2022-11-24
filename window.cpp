#include "window.hpp"
//#include "sprite.hpp"

manage_window::manage_window() : window(sf::VideoMode(800, 600), "Pokemon")
{
    //sound();
}

bool manage_window::isOpen(void) const
{
    return this->window.isOpen();
}

void manage_window::manage_event(void)

{
    sf::Event evt;
    while (this->window.pollEvent(evt))
    {
        if (evt.type == sf::Event::Closed)
            this->window.close();
    }
}

void manage_window::clear_window(void)
{
    this->window.clear();
    sf::Color::Black;
}

void manage_window::display_window(void)
{
    this->window.display();
}

/*void sound()
{
}*/