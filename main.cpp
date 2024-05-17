#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Collider.h"
int main()
{
    //creating a window and locking at monitor refresh rate
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Window");

    window.setVerticalSyncEnabled(true);


    //neco arc

    Player neco("chaos.png");

    //Object of wall to draw it in while loop
    Wall wall = Wall(100.f, 200.f);
    //this is to close it when X is pressed


    while(window.isOpen()){

        //everything considering events
        sf::Event event{};
        while (window.pollEvent(event))
        {
            //clear old frames


            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                //todo pausing game
                //case sf::Event::LostFocus:
                //case sf::Event::GainedFocus:

                //use of moving method in class, walk around
                case sf::Event::KeyPressed:
                    neco.movePlayer();
                    break;
                default:
                    break;
            }
            window.clear(sf::Color::Black);

            //to see collisions
            sf::RectangleShape rect(sf::Vector2(100.f,100.f));
            rect.setPosition(1000.f,1000.f);
            rect.setFillColor(sf::Color::Green);
            window.draw(rect);
            //unleash this monster
            neco.drawPlayer(window);
            //testing


            //next frame
            window.display();
        }
    }


}
