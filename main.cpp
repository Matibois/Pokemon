#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdbool>
#include "init.h"

void move(sf::IntRect rectSourceSprite) {


    if (rectSourceSprite.top > 90) {
        rectSourceSprite.top = 37;  // InteRect de base, perso original
    }
    else if (rectSourceSprite.top == 68) { // Si il a fait un pas alors en fait un deuxieme
        rectSourceSprite.top += 32;
    }
    else {
        rectSourceSprite.top += 31; // Change le IntRect pour que perso change de "skin" et face un pas
    }
}

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
    sf::Event event; // Var temporaire pour event

    perso.setScale(2, 2); // Taille de perso

    while (window.isOpen()) // Boucle pour maintenir la fenetre ouverte
    {
        while (window.pollEvent(event)) // Event fermer la fenetre
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Event fleche droite appuyé
        {
            right = true;

            perso.move(0.2f, 0.f);
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Event fleche gauche appuyé
        {
            left = true;
            perso.move(-0.2f, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Event fleche du haut appuyé
        {
            up = true;
            perso.move(0.f, -0.2f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // Event fleche du bas appuyé
        {
            down = true;
            perso.move(0.f, 0.2f);
        }

        if (clock.getElapsedTime().asSeconds() > 0.6f) { // Boucle d'animations
            //if (down){
                if (rectSourceSprite.top > 90) {
                    rectSourceSprite.top = 37;  // InteRect de base, perso original
                }
                else if (rectSourceSprite.top == 68) { // Si il a fait un pas alors en fait un deuxieme
                    rectSourceSprite.top += 32;
                }
                else {
                    rectSourceSprite.top += 31; // Change le IntRect pour que perso change de "skin" et face un pas
                }
            //}
        //    if (up) {
        //        if (rectSourceSprite.top > 90) {
        //            rectSourceSprite.top = 37;  // InteRect de base, perso original
        //        }
        //        else if (rectSourceSprite.top == 68) { // Si il a fait un pas alors en fait un deuxieme
        //            rectSourceSprite.top += 32;
        //        }
        //        else {
        //            rectSourceSprite.top += 31; // Change le IntRect pour que perso change de "skin" et face un pas
        //        }
        //    }
        //    if (right) {
        //        if (rectSourceSprite.top > 90) {
        //            rectSourceSprite.top = 37;  // InteRect de base, perso original
        //        }
        //        else if (rectSourceSprite.top == 68) { // Si il a fait un pas alors en fait un deuxieme
        //            rectSourceSprite.top += 32;
        //        }
        //        else {
        //            rectSourceSprite.top += 31; // Change le IntRect pour que perso change de "skin" et face un pas
        //        }
        //    }
        //    if (left) {
        //        if (rectSourceSprite.top > 90) {
        //            rectSourceSprite.top = 37;  // InteRect de base, perso original
        //        }
        //        else if (rectSourceSprite.top == 68) { // Si il a fait un pas alors en fait un deuxieme
        //            rectSourceSprite.top += 32;
        //        }
        //        else {
        //            rectSourceSprite.top += 31; // Change le IntRect pour que perso change de "skin" et face un pas
        //        }
        //    }
        //    //animation(rectSourceSprite);
            perso.setTextureRect(rectSourceSprite); // Donne la nouvelle position a perso
            clock.restart(); // Restart clock...?
        }
       
       

        window.clear();
        window.draw(bg);
        window.draw(perso);
        window.display();
    }

    return 0;
}