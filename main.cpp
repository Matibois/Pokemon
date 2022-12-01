#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdbool>
#pragma warning(disable : 4996);

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(960, 720), "Pokemon Stone"); 
    sf::View view;
    //view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));

    // ----------------------------------Sprite du personnage jouable-------------------------
    sf::Texture texture_Perso;
    texture_Perso.loadFromFile("persoo.PNG"); 
    sf::IntRect rectSourceSprite(77, 37, 25, 32); // Position du perso dans l'image persoo.png -> IntRect(77, 37, 25, 3)
    sf::Sprite perso(texture_Perso, rectSourceSprite); // Créer le perso lui applique la texture et le IntRect
    perso.setScale(3, 4); // Taille de perso
    perso.setPosition(1015, 1600); // Position du sprite au départ
    const float speed = 150000.f; // Vitesse de déplacement du perso

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

    // -----------------------------------------Sprite boite de dialog-----------------------------
    sf::Texture texture_box;
    texture_box.loadFromFile("box.JPG");
    sf::IntRect rectBox(0, 2, 235, 44);
    sf::Sprite box(texture_box, rectBox);
    box.setScale(4,4);
    box.setPosition(2280, 2900);

    // -----------------------------------------Sprite du join-------------------------------
    /*sf::Texture texture_Join;
    texture_Join.loadFromFile("join.PNG"); 
    sf::Sprite join(texture_Join);
    join.setScale(0.3, 0.3); 
    join.setRotation(-25.f);
    join.setPosition(2735, 2600);*/ 

    // --- Sprite invisible ----
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
    bool dialogue = false;
    bool combat = false;
    bool deplacement = true;

    // -----------------------------------------------Texte Intro-------------------------------------------
    sf::Text Intro;
    sf::Font police;
    police.loadFromFile("police.ttf");
    Intro.setFont(police);
    Intro.setString("Hello world");
    Intro.setCharacterSize(240); 
    Intro.setFillColor(sf::Color::Red);
    Intro.setStyle(sf::Text::Bold | sf::Text::Underlined);

    // -----------------------------------------------Texte Deal-------------------------------------------
    int dealtxt = 1;
    bool next = false;
    sf::Text Deal;
    Deal.setFont(police);
    Deal.setString("Donne la cam");
    Deal.setCharacterSize(50);
    Deal.setFillColor(sf::Color::White);
    Deal.setPosition(2320, 2950);
    sf::Text Deal2;
    Deal2.setFont(police);
    Deal2.setString("Non");
    Deal2.setCharacterSize(50);
    Deal2.setFillColor(sf::Color::White);
    Deal2.setPosition(2320, 2950);
    sf::Text Deal3;
    Deal3.setFont(police);
    Deal3.setString("ok");
    Deal3.setCharacterSize(50);
    Deal3.setFillColor(sf::Color::White);
    Deal3.setPosition(2320, 2950);

    //--------------------------------------------code Alexis--------------------------------------------
    sf::Texture texture_Bgc;

    texture_Bgc.loadFromFile("scene_combat.png");            
    sf::IntRect rectBgc(960, 0, 960, 720);                            
    sf::Sprite bgc(texture_Bgc, rectBgc);                      
    bgc.setScale(1, 1);
    bgc.setPosition(-200, -200);

    sf::Text text_debut;
    sf::Text text_debut2;


    text_debut.setFont(police);                                          // select the font, font is a sf::Font
    text_debut.setString("Qu'est ce que\nMustherbe doit faire ?");                                            // set the string to display
    text_debut.setCharacterSize(55);                                     // set the character size in pixels, not points!
    text_debut.setFillColor(sf::Color::Black);
    text_debut.setPosition(0, 600);

    //text_debut2.setFont(police);                                          // select the font, font is a sf::Font
    //text_debut2.setString("Mystherbe doit faire?");                                            // set the string to display
    //text_debut2.setCharacterSize(55);                                     // set the character size in pixels, not points!
    //text_debut2.setFillColor(sf::Color::Black);
    //text_debut2.setPosition(0, 650);
    //-------------------------------------------------------------------------------------------------------


    while (window.isOpen()) 
    {
        sf::Event event;


        /*dialogue = true;
        menu = false;*/


        if (menu) {

            if (clock.getElapsedTime().asSeconds() > 0.4f) { 
                if (rectStart.left == 0) {
                    rectStart.left = 320;
                }
                else {
                    rectStart.left = 0;
                }

                start.setTextureRect(rectStart); 
                clock.restart(); 
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
                
                if (deplacement) {
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


                    perso.setTextureRect(rectSourceSprite); 
                    clock.restart(); 
                }
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

            if (posX < 2800 && posX > 2700 && posY < 2770 && posY > 2500) {
                deplacement = false;
                perso.setPosition(2742, 2600);
                rectSourceSprite.left = 11;
                rectSourceSprite.top = 4;
                perso.setTextureRect(rectSourceSprite);
                next = true;
                
                   
            }

            if (window.pollEvent(event)) {
                if (deplacement) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        right = true;
                        up = false;
                        down = false;
                        left = false;
                        perso.move(speed * time, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        right = false;
                        up = false;
                        down = false;
                        left = true;
                        perso.move(-speed * time, 0.f);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        right = false;
                        up = true;
                        down = false;
                        left = false;
                        perso.move(0.f, -speed * time);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
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
                        perso.setTextureRect(rectSourceSprite);
                    }
                }
                if (next) {
                    if (event.type == sf::Event::KeyPressed) {
                        jeu = false;
                        dialogue = true;

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
            //window.draw(join);
            window.draw(dealo);
            window.draw(perso);
            //window.draw(Intro);

            window.display();

        }

        if (dialogue) {
            window.clear();
            window.setView(view);
            window.draw(bg);
            window.draw(dealo);
            window.draw(perso);
            
            /*rectDealo.left = 20;
            rectDealo.top = 0;
            rectDealo.width = 120;
            rectDealo.height = 80;*/
            //view.setCenter(2742, 2600);
            //dealo.setTextureRect(rectDealo);
            //dealo.setScale(11, 11);
            //dealo.setPosition(2100, 2100);

            if (dealtxt == 1) {
                window.draw(box);
                window.draw(Deal);
            }
            if (dealtxt == 2) {
                window.draw(box);
                window.draw(Deal2);
            }
            if (dealtxt == 3) {
                window.draw(box);
                window.draw(Deal3);
            }
            if (window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed) {
                    if (dealtxt == 1) {
                        dealtxt++;
                    }
                    else if (dealtxt == 2) {
                        dealtxt++;
                    }
                    else if (dealtxt == 3) {
                        jeu = false;
                        combat = true;
                        dialogue = false;
                    }


                }

                if (event.type == sf::Event::Closed) {
                    window.close();
                }

            }

            
            window.display();

        }
        if (combat) {
            view.setCenter(300, 300);
            window.setView(view);
            if (window.pollEvent(event))                             // Event fermer la fenetre
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            /*if (clock.getElapsedTime().asSeconds() > 0.6f) {            // Boucle d'animations

                if (rectBg.left > 0) {
                    rectBg.left = 0;                                    // IntRect de base, perso original
                }

                else {
                    rectBg.left += 960;                                 // Change le IntRect pour que perso change de "skin" et face un pas
                }

                bg.setTextureRect(rectBg);

                clock.restart();                                        // Restart clock...?
            }*/



            window.clear();

            window.draw(bgc);
            window.draw(text_debut);
            window.draw(text_debut2);



            window.display();
            
        }

        
       
    }
    return 0;
}
