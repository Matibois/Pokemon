#include "window.hpp"

void open_close_window()
{
    manage_window w;
    //Sprite background;


    sf::Music music;

    if (!music.openFromFile("song.ogg"))
        throw;
    else
        std::cout << "trouve" << std::endl;
    music.setLoop(true);
    music.play();

    while (w.isOpen())
    {
        w.clear_window();
        //background.display_background();
        w.manage_event();
        w.display_window();
    }

}

int main()
{
    open_close_window();
    return 0;
}