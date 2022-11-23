#include "Venusaur.h"
#include "Config.h"

Venusaur::Venusaur(const sf::Texture& texture) :
    Animation(texture, std::vector<sf::IntRect>(VENUSAUR_ANIM_RECT))
{
    this->_sprite.scale(10, 10);
}