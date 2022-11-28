#include "Sprite.h"



void MSprite::ApplyTexture(std::string t) {
	texture.loadFromFile(t);
	sprite.setTexture(texture);
}

void MSprite::setRect(int a, int b, int c, int d) {
	rect.left = a;
	rect.top = b;
	rect.width = c;
	rect.top = d;
	sprite.setTextureRect(rect);

}

void MSprite::afficheSprite() {
	window.draw(sprite);
}