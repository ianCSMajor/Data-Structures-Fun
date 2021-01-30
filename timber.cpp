#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>

using namespace sf;

using namespace std;

int main()
{
    //creates video mode object
VideoMode vm(1920, 1080);
//creates and opens window for game
RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    return 0;
}