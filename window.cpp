#include "window.hpp"
#include "song.hpp"
#include "sprite.hpp"

bool up = false;
bool left = false;
bool right = false;
bool down = false;
bool menu = true;
bool jeu = false;
bool dialogue = false;
bool combat = false;
bool deplacement = true;
bool next = false;
bool attaque = false;
bool choice = true;
bool degat = false;
bool fin = false;

manage_window::manage_window() : window(sf::VideoMode(960, 720), "Pokemon")
{

}

bool manage_window::isOpen(void) const
{
    return this->window.isOpen();
}

void manage_window::manage_event(void)
{
    sf::Event evt;
    while (this->window.pollEvent(evt))
    {
        if (evt.type == sf::Event::Closed)
            this->window.close();
    }
}

void manage_window::clear_window(void)
{
    this->window.clear();
}

void manage_window::display_window(void)
{
    this->window.display();
}

void manage_window::open_close_window()
{
    sf::Clock clock;
    sf::Clock lap;
    sf::Event event;
    sf::Texture texture_Background;
    texture_Background.loadFromFile("map.png");
    sf::Sprite background(texture_Background);
    background.setScale(5, 5);
    sf::Texture texture_Perso;
    texture_Perso.loadFromFile("persoo.png");
    sf::IntRect rectSourceSprite(77, 37, 25, 32);
    sf::Sprite perso(texture_Perso, rectSourceSprite);
    perso.setScale(3, 4);
    sf::Texture texture_Menu;
    texture_Menu.loadFromFile("ecran_titre.png");
    sf::IntRect rectMenu(10, 0, 120, 140);
    sf::Sprite Menu(texture_Menu);
    perso.setPosition(1015, 1600);
    sf::Texture texture_Start;
    texture_Start.loadFromFile("ecran_titre.png");
    sf::IntRect rectStart(0, 0, 320, 240);
    sf::Sprite start(texture_Start);
    start.setScale(3, 3);
    manage_sprite dealer("dealer.png", sf::IntRect(0, 0, 120, 140), 0.7, 0.9, 2735, 2530);
    sf::View view;
    view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    sf::Texture texture_mystherbe;
    texture_mystherbe.loadFromFile("mystbeuh.PNG");
    sf::Sprite mystherbe(texture_mystherbe);
    mystherbe.setPosition(-60, 240);
    mystherbe.setScale(1.8, 1.8);

    const float speed = 700.f;
    int dealtxt = 1;
    bool next = false;
    sf::Text Deal;
    sf::Font police;
    police.loadFromFile("PKM_font.ttf");
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
    sf::Texture texture_box;
    texture_box.loadFromFile("zone_texte.png");
    sf::IntRect rectBox(0, 2, 235, 44);
    sf::Sprite box(texture_box, rectBox);
    box.setScale(4, 4);
    box.setPosition(2280, 2900);

    sf::Texture texture_Bgc;
    texture_Bgc.loadFromFile("terrain_combat.png");
    sf::IntRect rectBgc(320, 0, 320, 240);
    sf::Sprite bgc(texture_Bgc, rectBgc);
    bgc.setPosition(-200, -200);
    bgc.setScale(3.12, 4.2);


    sf::Texture texture_Fleche;
    sf::Texture texture_Vie_Zero;
    //texture fleche
    texture_Fleche.loadFromFile("fleche.PNG");
    sf::IntRect rect_fleche(0, 0, 26, 42);
    //sprite fleche view gauche
    sf::Sprite Sfleche_attaque(texture_Fleche, rect_fleche);
    Sfleche_attaque.setPosition(475, 667);
    //sprite fleche view droite
    sf::Sprite Sfleche_fight(texture_Fleche, rect_fleche);
    Sfleche_fight.setPosition(-160, 670);
    //vie zero
    texture_Vie_Zero.loadFromFile("vie_zero.png");
    sf::Sprite Svie_zero(texture_Vie_Zero);
    Svie_zero.setPosition(53, 112);
    Svie_zero.setScale(1.22, 0.25);

    //text view droite
    sf::Text text_debut;
    sf::Text text_attaque;
    //text view gauche
    sf::Text text_DERACINEMENT;
    sf::Text text_TOXICO;
    sf::Text text_BEDODO;
    sf::Text text_RAILDECOCO;

    sf::Text text_attaque_DERACINEMENT;

    text_debut.setFont(police);
    text_debut.setString("Qu'est-ce que\nMystherbe doit faire ?");
    text_debut.setCharacterSize(40);
    text_debut.setPosition(-160, 670);

    text_attaque.setFont(police);
    text_attaque.setString("C'est super efficace !");
    text_attaque.setCharacterSize(40);
    text_attaque.setFillColor(sf::Color::Black);
    text_attaque.setPosition(-160, 670);

    //texte sur la view de gauche
    text_DERACINEMENT.setFont(police);
    text_DERACINEMENT.setString("DERACINEMENT");
    text_DERACINEMENT.setCharacterSize(40);
    text_DERACINEMENT.setFillColor(sf::Color::Black);
    text_DERACINEMENT.setPosition(-140, 670);

    text_TOXICO.setFont(police);
    text_TOXICO.setString("TOXICO");
    text_TOXICO.setCharacterSize(40);
    text_TOXICO.setFillColor(sf::Color::Black);
    text_TOXICO.setPosition(-140, 710);

    text_BEDODO.setFont(police);
    text_BEDODO.setString("BEDODO");
    text_BEDODO.setCharacterSize(40);
    text_BEDODO.setFillColor(sf::Color::Black);
    text_BEDODO.setPosition(210, 710);

    text_RAILDECOCO.setFont(police);
    text_RAILDECOCO.setString("RAIL DE COCO");
    text_RAILDECOCO.setCharacterSize(40);
    text_RAILDECOCO.setFillColor(sf::Color::Black);
    text_RAILDECOCO.setPosition(210, 670);

    text_attaque_DERACINEMENT.setFont(police);
    text_attaque_DERACINEMENT.setString("MYSTHERBE\nlance DERACINEMENT");
    text_attaque_DERACINEMENT.setCharacterSize(40);
    text_attaque_DERACINEMENT.setFillColor(sf::Color::Black);
    text_attaque_DERACINEMENT.setPosition(-160, 690);

    Musique m;
    m.song_menu_principal();
    while (isOpen())
    {
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
            if (this->window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    this->window.close();
                if (event.type == sf::Event::KeyPressed) {

                    menu = false;
                    jeu = true;
                    this->window.setView(view);

                }
            }
            this->window.clear();
            this->window.draw(start);
            this->window.display();
        }
        if (jeu) {
            if (clock.getElapsedTime().asSeconds() > 0.2f) {
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
            float time;
            if (lap.getElapsedTime().asSeconds() > 0.1f) {
                clock.restart();
            }
            time = lap.restart().asSeconds();
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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                right = true;
                up = false;
                down = false;
                left = false;
                perso.move(speed * time, 0.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                right = false;
                up = false;
                down = false;
                left = true;
                perso.move(-speed * time, 0.f);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                right = false;
                up = true;
                down = false;
                left = false;
                perso.move(0.f, -speed * time);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
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
                while (this->window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        this->window.close();
                    }
                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::Escape) {
                            menu_create();
                        }
                    }
                    if (next) {
                        if (event.type == sf::Event::KeyPressed) {
                            jeu = false;
                            dialogue = true;

                        }
                    }
                }
            }
            clear_window();
            this->window.setView(view);
            this->window.draw(background);
            this->window.draw(dealer.get_sprite());
            this->window.draw(perso);
            manage_event();
            display_window();
        }
        if (dialogue) {
            this->window.clear();
            this->window.setView(view);
            this->window.draw(background);
            this->window.draw(dealer.get_sprite());
            this->window.draw(perso);
            if (dealtxt == 1) {
                this->window.draw(box);
                this->window.draw(Deal);
            }
            if (dealtxt == 2) {
                this->window.draw(box);
                this->window.draw(Deal2);
            }
            if (dealtxt == 3) {
                this->window.draw(box);
                this->window.draw(Deal3);
            }
            if (this->window.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed) {
                    if (dealtxt == 1) {
                        dealtxt++;
                    }
                    else if (dealtxt == 2) {
                        dealtxt++;
                    }
                    else if (dealtxt == 3) {
                        combat = true;
                        dialogue = false;
                    }
                }
                if (event.type == sf::Event::Closed) {
                    this->window.close();
                }
            }
            this->window.display();
        }
        if (combat) {
            view.setCenter(300, 300);
            window.setView(view);

            window.clear();
            window.draw(bgc);
            window.draw(mystherbe);

            if (choice) {
                window.draw(text_debut);
                window.draw(Sfleche_attaque);
            }

            /*window.draw(text_debut);
            window.draw(Sfleche_fight);



            window.draw(text_attaque);*/


            if (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed) {

                    if (event.key.code == sf::Keyboard::Enter && attaque == true) {
                        degat = true;
                        attaque = false;


                    }

                    else if (event.key.code == sf::Keyboard::Enter) {
                        attaque = true;
                        choice = false;


                    }

                }
            }
            if (attaque) {
                rectBgc.left = 0;
                bgc.setTextureRect(rectBgc);
                window.draw(Sfleche_fight);
                window.draw(text_DERACINEMENT);
                window.draw(text_TOXICO);
                window.draw(text_BEDODO);
                window.draw(text_RAILDECOCO);
            }
            if (degat) {
                window.draw(text_attaque);
                window.draw(Svie_zero);

            }


            if (clock.getElapsedTime().asSeconds() > 0.6f) {

                if (rect_fleche.left > 0) {
                    rect_fleche.left = 0;
                }

                else {
                    rect_fleche.left += 26;
                }
                Sfleche_attaque.setTextureRect(rect_fleche);
                Sfleche_fight.setTextureRect(rect_fleche);

                clock.restart();
            }






            window.display();
        }
    }
}
