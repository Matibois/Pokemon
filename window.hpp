#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class manage_window
{
private:
	sf::RenderWindow window;
	sf::Event evt;
public:
	manage_window(void);
	bool isOpen(void) const;
	void manage_event(void);
	void display_window(void);
	void clear_window(void);
	void open_close_window();
	void menu_create();
};