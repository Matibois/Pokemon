#include "window.hpp"
#include "song.hpp"
#include "sprite.hpp"

bool up = false;
bool left = false;
bool right = false;
bool down = false;

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
    texture_Background.loadFromFile("map.PNG");
    sf::Sprite background(texture_Background);
    background.setScale(5, 5);
    sf::Texture texture_Perso;
    texture_Perso.loadFromFile("persoo.PNG");
    sf::IntRect rectSourceSprite(77, 37, 25, 32);
    sf::Sprite perso(texture_Perso, rectSourceSprite);
    perso.setScale(3, 4);
    perso.setPosition(1015, 1600);
    manage_sprite dealer("dealer.png", sf::IntRect(0, 0, 120, 140), 0.7, 0.9, 2735, 2530);
    sf::View view;
    view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
    const float speed = 1500.f;
    Musique m;
    m.song_menu_principal();
    while (isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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
        }
        clear_window();
        this->window.setView(view);
        this->window.draw(background);
        this->window.draw(dealer.get_sprite());
        this->window.draw(perso);
        manage_event();
        display_window();
    }
}