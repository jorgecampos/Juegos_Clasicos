/*#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>


int main() {

    sf::Renderwindow ventana(sf::Videomode(320,240), "pantallajuego");
    */
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(7.f);
    shape.setFillColor(sf::Color::White);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        window.clear();
        window.draw(shape);
        window.display();
    }

    
    return 0;
}
/*
    return EXIT_SUCCESS;

}

*/
