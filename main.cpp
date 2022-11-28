#include <SFML/Graphics.hpp>
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
    sf::RenderWindow window(sf::VideoMode(960, 720), "Pokemon Stone"); // Création 
    sf::View view;
    view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));

    sf::Texture texture_Perso;
    texture_Perso.loadFromFile("persoo.PNG"); // Charge l'image dans "texture"
    sf::IntRect rectSourceSprite(77, 37, 25, 32); // Position du perso dans l'image Sprite.jpg -> IntRect(77, 37, 25, 3)
    sf::Sprite perso(texture_Perso, rectSourceSprite); // Créer le perso lui applique la texture et le IntRect
    perso.setScale(3, 4); // Taille de perso
    perso.setPosition(1015, 1600); // Position du sprite au départ
    const float speed = 1500.f;

    sf::Texture texture_Background;
    texture_Background.loadFromFile("map.PNG"); // Charge l'image dans "texture"
    sf::Sprite bg;
    bg.setTexture(texture_Background);
    bg.setScale(5,5); // Taille de perso

    sf::Texture texture_Dealo;
    texture_Dealo.loadFromFile("dealer.PNG"); // Charge l'image dans "texture"
    sf::IntRect rectDealo(10, 0, 120, 140); // Position du perso dans l'image Sprite.jpg -> IntRect(77, 37, 25, 3)
    sf::Sprite dealo(texture_Dealo,rectDealo);
    dealo.setScale(0.7, 0.9); // Taille de perso
    dealo.setPosition(2735, 2530); // Position du sprite au départ

    sf::Texture texture_Join;
    texture_Join.loadFromFile("join.PNG"); // Charge l'image dans "texture"
    //sf::IntRect rectJoin(10, 0, 120, 140); // Position du perso dans l'image Sprite.jpg -> IntRect(77, 37, 25, 3)
    sf::Sprite join(texture_Join);
    join.setScale(0.3, 0.3); // Taille de perso
    join.setRotation(-25.f);
    join.setPosition(2735, 2600); // Position du sprite au départ




    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;

    sf::IntRect* rect;
    rect = &rectSourceSprite;
    sf::Clock clock; // Boucle pour animation
    sf::Clock lap; // Boucle pour déplacement
    sf::Event event; // Var temporaire pour event


    while (window.isOpen()) // Boucle pour maintenir la fenetre ouverte
    {
        while (window.pollEvent(event)) // Event fermer la fenetre
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      

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

        float posX = perso.getPosition().x;
        float posY = perso.getPosition().y;
        view.setCenter(posX, posY);

        //if (posX > 1200/*posX < 1050 && posX > 1000 && posY < 1560 && posY > 1580*/) {
            //while (lap.getElapsedTime().asSeconds() < 0.9f) {
                //view.rotate(0.1f);
                

            //}
        //}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Event fleche droite appuyé
        {
            right = true;
            up = false;
            down = false;
            left = false;
            perso.move(speed* time, 0.f);
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
        window.setView(view);
        window.draw(bg);
        window.draw(perso);
        window.draw(dealo);
        window.draw(join);
        window.display();

    }
    return 0;
}
