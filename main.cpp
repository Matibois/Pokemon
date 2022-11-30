#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdbool>


int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(960, 720), "Pokemon Stone"); 
    sf::View view;
    view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));

    // ----------------------------------Sprite du personnage jouable-------------------------
    sf::Texture texture_Perso;
    texture_Perso.loadFromFile("persoo.PNG"); 
    sf::IntRect rectSourceSprite(77, 37, 25, 32); // Position du perso dans l'image persoo.png -> IntRect(77, 37, 25, 3)
    sf::Sprite perso(texture_Perso, rectSourceSprite); // Créer le perso lui applique la texture et le IntRect
    perso.setScale(3, 4); // Taille de perso
    perso.setPosition(1015, 1600); // Position du sprite au départ
    const float speed = 15000.f; // Vitesse de déplacement du perso

    // -----------------------------------------Sprite de la map------------------------------
    sf::Texture texture_Background;
    texture_Background.loadFromFile("map.PNG"); 
    sf::Sprite bg(texture_Background);
    bg.setScale(5,5); 

    // -----------------------------------------Sprite du start-------------------------------
    sf::Texture texture_Start;
    texture_Start.loadFromFile("ecran_titre.PNG");
    sf::IntRect rectStart(0, 0, 320, 240);
    sf::Sprite start(texture_Start);
    start.setScale(3, 3);

    // -----------------------------------------Sprite du menu-------------------------------
    sf::Texture texture_Menu;
    texture_Menu.loadFromFile("ecran_titre.PNG");
    sf::IntRect rectMenu(10, 0, 120, 140);
    sf::Sprite Menu(texture_Menu);
    //bg.setScale(5, 5);

    // -----------------------------------------Sprite du Dealer-----------------------------
    sf::Texture texture_Dealo;
    texture_Dealo.loadFromFile("dealer.PNG"); 
    sf::IntRect rectDealo(10, 0, 120, 140); 
    sf::Sprite dealo(texture_Dealo,rectDealo);
    dealo.setScale(0.7, 0.9); 
    dealo.setPosition(2735, 2530);

    // -----------------------------------------Sprite du join-------------------------------
    sf::Texture texture_Join;
    texture_Join.loadFromFile("join.PNG"); 
    sf::Sprite join(texture_Join);
    join.setScale(0.3, 0.3); 
    join.setRotation(-25.f);
    join.setPosition(2735, 2600); 

    // --- Spriyte invisible ----
    sf::Texture vide;
    vide.loadFromFile("vide.jpg");
    sf::Sprite suppr(vide);

    // -----------------------------------------Bool pour deplacement---------------------------------------
    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;




    sf::Clock clock; // Boucle pour animation
    sf::Clock lap; // Boucle pour déplacement
    bool menu = true;
    bool jeu = false;

    // -----------------------------------------------Texte----------------------------------------------
    sf::Text Intro;
    sf::Text Deal;
    sf::Font police;
    police.loadFromFile("police.ttf");

    Intro.setFont(police);
    // set the string to display
    Intro.setString("Hello world");
    // set the character size
    Intro.setCharacterSize(240); // in pixels, not points!
    // set the color
    Intro.setFillColor(sf::Color::Red);
    // set the text style
    Intro.setStyle(sf::Text::Bold | sf::Text::Underlined);



    while (window.isOpen()) // Boucle pour maintenir la fenetre ouverte
    {
        sf::Event event;

        if (menu) {

            if (clock.getElapsedTime().asSeconds() > 0.4f) { // Boucle d'animations
                if (rectStart.left == 0) {
                    rectStart.left = 320;
                }
                else {
                    rectStart.left = 0;
                }

                start.setTextureRect(rectStart); // Donne la nouvelle position a perso
                clock.restart(); // Restart clock...?
            }

            if (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {

                    menu = false;
                    jeu = true;
                    window.setView(view);

                }
            }

            window.clear();
            window.draw(start);
            window.display();

        }

        if (jeu){
            
            if (clock.getElapsedTime().asSeconds() > 0.2f) { 
            //clock.getElapsedTime().asSeconds();
            
                if (down) {
                
                    if (rectSourceSprite.top == 68 && rectSourceSprite.left == 77) { 
                        rectSourceSprite.top = 100; 
                    }
                    else {  
                        rectSourceSprite.top = 68;
                     rectSourceSprite.left = 77;
                    }
                }
                if (up) {

                    if (rectSourceSprite.top == 4 && rectSourceSprite.left == 77) { 
                        rectSourceSprite.top = 100;
                        rectSourceSprite.left = 45;
                    }
                    else {
                        rectSourceSprite.top = 4;
                        rectSourceSprite.left = 77;
                    }
                }
                if (right) {

                    if (rectSourceSprite.top == 68 && rectSourceSprite.left == 45) { 
                        rectSourceSprite.top = 36;
                        rectSourceSprite.left = 45;
                    }
                    else {
                        rectSourceSprite.top = 68;
                        rectSourceSprite.left = 45;
                    }
                }
                if (left) {

                    if (rectSourceSprite.top == 100 && rectSourceSprite.left == 11) { 
                        rectSourceSprite.top = 36;
                    }
                    else {
                        rectSourceSprite.top = 100;
                        rectSourceSprite.left = 11;
                    }
                    

                }
            

                perso.setTextureRect(rectSourceSprite); // Donne la nouvelle position a perso
                clock.restart(); // Restart clock...?
            }

            float time = lap.getElapsedTime().asSeconds();
            

            float posX = perso.getPosition().x;
            float posY = perso.getPosition().y;
            view.setCenter(posX, posY);

            if (perso.getPosition().x < 500) {
                perso.setPosition(500, posY);
            }
            else if (perso.getPosition().x > 3500) {
                perso.setPosition(3500, posY);
            }
            else if (perso.getPosition().y < 500) {
                perso.setPosition(posX, 500);
            }
            else if (perso.getPosition().y > 3000) {
                perso.setPosition(posX, 3000);
            }

            //if (posX > 1200/*posX < 1050 && posX > 1000 && posY < 1560 && posY > 1580*/) {
                //while (lap.getElapsedTime().asSeconds() < 0.9f) {
                    //view.rotate(0.1f);
                //}
            //}

            if (window.pollEvent(event)) {
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
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
               
            }
                lap.restart();

                window.clear();
                window.setView(view);
                window.draw(bg);
                window.draw(join);
                window.draw(dealo);
                window.draw(perso);
                window.draw(Intro);
                window.display();

        }
       
    }
    return 0;
}
