#include "window.hpp"
#include "sprite.hpp"

manage_sprite::manage_sprite(std::string file, sf::IntRect rect)
{
    this->texture.loadFromFile(file);
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(rect);
}

sf::Sprite &manage_sprite::get_sprite()
{
    return this->sprite;
}

const sf::Sprite &manage_sprite::get_sprite() const
{
    return this->sprite;
}

void manage_sprite::sprite_animation()
{

}

/*#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdbool>
#include "Sprite.h"

//void move(sf::IntRect rectSourceSprite) {
//
//
//    if (rectSourceSprite.top > 90) {
//        rectSourceSprite.top = 37;  // InteRect de base, perso original
//    }
//    else if (rectSourceSprite.top == 68) { // Si il a fait un pas alors en fait un deuxieme
//        rectSourceSprite.top += 32;
//    }
//    else {
//        rectSourceSprite.top += 31; // Change le IntRect pour que perso change de "skin" et face un pas
//    }
//}

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(771, 432), "Pokemon Stone"); // Création fenetre

    sf::Texture texture_Perso;
    sf::Texture texture_Background;
    texture_Perso.loadFromFile("persoo.PNG"); // Charge l'image dans "texture"
    sf::IntRect rectSourceSprite(77, 37, 25, 32); // Position du perso dans l'image Sprite.jpg -> IntRect(77, 37, 25, 3)
    sf::Sprite perso(texture_Perso, rectSourceSprite); // Créer le perso lui applique la texture et le IntRect
    texture_Background.loadFromFile("bg.PNG"); // Charge l'image dans "texture"
    sf::Sprite bg;
    bg.setTexture(texture_Background);
    bg.setScale(3, 3); // Taille de perso

    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;
    sf::IntRect* rect;
    rect = &rectSourceSprite;

    sf::Clock clock; // Boucle pour animation
    sf::Clock lap; // Boucle pour déplacement
    sf::Event event; // Var temporaire pour event

    perso.setScale(2, 2); // Taille de perso

    while (window.isOpen()) // Boucle pour maintenir la fenetre ouverte
    {
        while (window.pollEvent(event)) // Event fermer la fenetre
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        const float speed = 200.f;


        if (clock.getElapsedTime().asSeconds() > 0.2f) { // Boucle d'animations


            if (down) {

                if (rectSourceSprite.top == 68 && rectSourceSprite.left == 77) { // Si il a fait un pas alors en fait un deuxieme
                    rectSourceSprite.top = 100;
                }
                else {  // Change le IntRect pour que perso change de "skin" et face un pas
                    rectSourceSprite.top = 68;
                    rectSourceSprite.left = 77;
                }
            }
            if (up) {

                if (rectSourceSprite.top == 4 && rectSourceSprite.left == 77) { // Si il a fait un pas alors en fait un deuxieme
                    rectSourceSprite.top = 100;
                    rectSourceSprite.left = 45;
                }
                else {
                    rectSourceSprite.top = 4;
                    rectSourceSprite.left = 77;
                }
            }
            if (right) {

                if (rectSourceSprite.top == 68 && rectSourceSprite.left == 45) { // Si il a fait un pas alors en fait un deuxieme
                    rectSourceSprite.top = 36;
                    rectSourceSprite.left = 45;
                }
                else {
                    rectSourceSprite.top = 68;
                    rectSourceSprite.left = 45;
                }
            }
            if (left) {

                if (rectSourceSprite.top == 100 && rectSourceSprite.left == 11) { // Si il a fait un pas alors en fait un deuxieme
                    rectSourceSprite.top = 36;
                }
                else {
                    rectSourceSprite.top = 100;
                    rectSourceSprite.left = 11;
                }
                //animation(rectSourceSprite);

            }

            perso.setTextureRect(rectSourceSprite); // Donne la nouvelle position a perso
            clock.restart(); // Restart clock...?
        }

        float time;
        if (lap.getElapsedTime().asSeconds() > 0.1f) {

            clock.restart(); // Restart clock...?
        }
        time = lap.restart().asSeconds();




        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Event fleche droite appuyé
        {
            right = true;
            up = false;
            down = false;
            left = false;
            perso.move(speed * time, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Event fleche gauche appuyé
        {
            right = false;
            up = false;
            down = false;
            left = true;
            perso.move(-speed * time, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Event fleche du haut appuyé
        {
            right = false;
            up = true;
            down = false;
            left = false;
            perso.move(0.f, -speed * time);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // Event fleche du bas appuyé
        {
            right = false;
            up = false;
            down = true;
            left = false;
            perso.move(0.f, speed * time);
        }

        else if (sf::Event::KeyReleased) {

            if (event.key.code == sf::Keyboard::Left) {
                left = false;
                rectSourceSprite.left = 11;
                rectSourceSprite.top = 68;
            }
            if (event.key.code == sf::Keyboard::Right) {
                right = false;
                rectSourceSprite.left = 45;
                rectSourceSprite.top = 4;
            }
            if (event.key.code == sf::Keyboard::Up) {
                up = false;
                rectSourceSprite.left = 11;
                rectSourceSprite.top = 4;
            }
            if (event.key.code == sf::Keyboard::Down) {
                down = false;
                rectSourceSprite.left = 77;
                rectSourceSprite.top = 37;
            }

        }
        window.clear();
        window.draw(bg);
        window.draw(perso);
        window.display();

    }
    return 0;
}*/