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
    const float speed = 1500.f;
    int dealtxt = 1;
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
                        jeu = false;
                        combat = true;
                    }
                }
                if (event.type == sf::Event::Closed) {
                    this->window.close();
                }
            }
            this->window.display();
        }
    }
}