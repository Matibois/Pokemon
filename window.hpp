#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class manage_window
{
private:
	sf::RenderWindow window;
public:
	manage_window(void);
	bool isOpen(void) const;
	void manage_event(void);
};

void open_close_window();