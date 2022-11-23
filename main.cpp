#include "window.hpp"

/*int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!"); // Création fenetre

    sf::Texture texture;
    texture.loadFromFile("Sprite.jpg"); // Charge l'image dans "texture"
    sf::IntRect rectSourceSprite(375, 181, 25, 32); // Position du perso dans l'image Sprite.jpg -> IntRect(375, 180, 25, 30)
    sf::Sprite perso(texture, rectSourceSprite); // Créer le perso lui applique la texture et 
    /*perso.setTexture(texture);
   

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

        if (clock.getElapsedTime().asSeconds() > 1.0f) { // Boucle d'animations
            if (rectSourceSprite.top > 240){
                rectSourceSprite.top = 181;  // InteRect de base, perso original
            }
            else if(rectSourceSprite.top == 212) { // Si il a fait un pas alors en fait un deuxieme
                rectSourceSprite.top += 32; 
            }
            else {
                rectSourceSprite.top += 31; // Change le IntRect pour que perso change de "skin" et face un pas
            }

            perso.setTextureRect(rectSourceSprite); // Donne la nouvelle position a perso
            clock.restart(); // Restart clock...?
        }

        window.clear();
        window.draw(perso);
        window.display();
    }
    return 0;
}
*/


int main()
{
    
    open_close_window();


    return 0;
}