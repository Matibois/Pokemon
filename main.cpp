#include "Game.h"
#include "Venusaur.h"
#include "Config.h"

int main(void)
{
    Game g;

    sf::Texture texture;
    if (!texture.loadFromFile(VENUSAUR_TEXTURE_PATH))
    {
        // error...
    }

    Venusaur venusaur = Venusaur(texture);

    int count = 0;
    while (g.isOpen())
    {
        g.clear();
        g.handleEvents();
        if (count % 20 == 0)
        {
            venusaur.nextAnimation();
            count = 0;
        }
        count++;
        g.drawEntity(venusaur);
        g.display();
    }

    return 0;
}