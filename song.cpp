#include "song.hpp"

void Musique::song_menu_principal(void)
{
    music.openFromFile("song.ogg");
    music.setLoop(true);
    music.play();
}