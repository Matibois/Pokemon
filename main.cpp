#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "init.h"


int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!"); // Création fenetre

    sf::Texture texture;
    texture.loadFromFile("venusaur.png"); // Charge l'image dans "texture"
    sf::IntRect rectSourceSprite(252, 251, 54, 54); // Position du perso dans l'image Sprite.jpg -> IntRect(375, 180, 25, 30)
    sf::Sprite venusaur(texture, rectSourceSprite); // Créer le perso lui applique la texture et 
    /*perso.setTexture(texture);*/
   

    sf::Clock clock; // Boucle pour animation
    sf::Event event; // Var temporaire pour event

    venusaur.setScale(4, 4); // Taille de perso

    while (window.isOpen()) // Boucle pour maintenir la fenetre ouverte
    {
        while (window.pollEvent(event)) // Event fermer la fenetre
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime().asSeconds() > 1.0f) { // Boucle d'animations
            if (rectSourceSprite.top > 380){
                rectSourceSprite.top = 251;  // InteRect de base, perso original
            }
            else if(rectSourceSprite.top == 315) { // Si il a fait un pas alors en fait un deuxieme
              rectSourceSprite.top += 65; 
            }
            else {
                rectSourceSprite.top += 66; // Change le IntRect pour que perso change de "skin" et face un pas
            }

            venusaur.setTextureRect(rectSourceSprite); // Donne la nouvelle position a perso
            clock.restart(); // Restart clock...?
        }

        window.clear();

        window.draw(venusaur);

        window.display();
    }

    return 0;
}