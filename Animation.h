#pragma once

#include "Entity.h"

class Animation : public Entity
{
protected:
    size_t _count;
    std::vector<sf::IntRect> _animation_pos;

public:
    Animation(const sf::Texture&, std::vector<sf::IntRect>);
    void nextAnimation(void);
};