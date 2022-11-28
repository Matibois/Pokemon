#include <SFML/Graphics.hpp>
#include <string>

class MSprite {

public :
	sf::Sprite sprite;
	sf::Texture texture;
	void ApplyTexture(std::string t);
	sf::IntRect rect;
	void setRect(int a, int b, int c, int d);
	void afficheSprite();
	sf::RenderWindow window;
private :

};