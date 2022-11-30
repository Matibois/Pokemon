#include "menu.hpp"
#include "window.hpp"

MainMenu::MainMenu(float width, float height)
{
	font.loadFromFile("pkm_font.ttf");

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Green);
	mainMenu[0].setString("play");
	mainMenu[0].setCharacterSize(100);
	mainMenu[0].setPosition(150, 235);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Settings");
	mainMenu[1].setCharacterSize(100);
	mainMenu[1].setPosition(550, 235);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Credits");
	mainMenu[2].setCharacterSize(100);
	mainMenu[2].setPosition(75, 510);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(100);
	mainMenu[3].setPosition(635, 510);

	MainMenuSelected = -1;
}
MainMenu::~MainMenu()
{

}

void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 3;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Green);
	}
}

void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Green);
	}
}

void manage_window::menu_create()
{
	MainMenu mainMenu(window.getSize().x, window.getSize().y);

	RectangleShape background;
	background.setSize(Vector2f(960, 720));
	Texture Maintexture;
	Maintexture.loadFromFile("Menu.png");
	background.setTexture(&Maintexture);

	RectangleShape Pbackground;
	Pbackground.setSize(Vector2f(960, 720));
	Texture back_texture;
	back_texture.loadFromFile("");
	Pbackground.setTexture(&back_texture);

	RectangleShape Sbackground;
	Sbackground.setSize(Vector2f(960, 720));
	Texture settings_texture;
	settings_texture.loadFromFile("");
	Sbackground.setTexture(&settings_texture);

	RectangleShape Cbackground;
	Cbackground.setSize(Vector2f(960, 720));
	Texture credits_texture;
	credits_texture.loadFromFile("credits.png");
	Cbackground.setTexture(&credits_texture);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return) {
					RenderWindow Settings(VideoMode(960, 720), "Settings");
					RenderWindow Credits(VideoMode(960, 720), "Credits");

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (window.isOpen())
						{
							Event aevent;
							while (window.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									window.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										window.close();
									}
								}
							}
							Settings.close();
							Credits.close();
							window.clear();
							open_close_window();
							window.display();
						}
					}
					if (x == 1)
					{
						while (Settings.isOpen())
						{
							Event aevent;
							while (Settings.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									Settings.close();
								}
								if (aevent.type == Event::KeyPressed)
								{
									if (aevent.key.code == Keyboard::Escape)
									{
										Settings.close();
									}
								}
							}
							window.close();
							Settings.clear();
							Settings.draw(Sbackground);
							Credits.clear();
							Settings.display();
						}
					}
					if (x == 2)
					{
						while (Credits.isOpen())
						{
							Event aevent;
							while (Credits.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									Credits.close();
								}
								if (aevent.type == Event::KeyPressed) {
									if (aevent.key.code == Keyboard::Escape) {
										Credits.close();
									}
								}
							}
							window.close();
							Settings.clear();
							Credits.clear();
							Credits.draw(Cbackground);
							Credits.display();
						}
					}
					if (x == 3)
						window.close();
					break;

				}
			}
		}
		window.clear();
		window.draw(background);
		mainMenu.draw(window);
		window.display();
	}
}