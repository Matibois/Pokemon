#include "menu.hpp"
#include "window.hpp"
#include "sprite.hpp"

int main()
{
    RenderWindow window(VideoMode(960, 720), "Pokemon");
    manage_sprite ecran_titre("ecran_titre.png", sf::IntRect(0, 0, 320, 240), 3, 3, 0, 0);
    window.draw(ecran_titre.get_sprite());
    menu_create();
    return 0;
}