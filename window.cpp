#include "window.hpp"
#include "song.hpp"
#include "sprite.hpp"

manage_window::manage_window() : window(sf::VideoMode(960, 720), "Pokemon")
{

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
}

void manage_window::display_window(void)
{
    this->window.display();
}

void manage_window::open_close_window()
{
    manage_sprite background("ecran_titre.png", sf::IntRect(0, 0, 320, 240), 3, 3);
    Musique m;
    m.song_menu_principal();
    while (isOpen())
    {
        clear_window();
        this->window.draw(background.get_sprite());
        manage_event();
        display_window();
    }
}