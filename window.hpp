#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class manage_window
{
private:
	sf::RenderWindow window;
public:
	manage_window(void);
	bool isOpen(void) const;
	void manage_event(void);
	void display_window(void);
	void clear_window(void);
};