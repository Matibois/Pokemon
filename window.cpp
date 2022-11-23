#include "window.hpp"

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

void open_close_window()
{
    manage_window w;

    while (w.isOpen())
    {
        w.clear_window();
        w.manage_event();
        w.display_window();
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
    sf::Music music;

    music.openFromFile("song.ogg");
    music.setLoop(true);
    music.play();
}*/