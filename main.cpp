#include <SFML/Graphics.hpp>


#include "Player.h"
#include "Walls.h"
#include "Weapon.h"

int main()
{
    //creating a window and locking at monitor refresh rate
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Window");
    window.setVerticalSyncEnabled(true);
//    window.setMouseCursorVisible(false);

    //view
    sf::View view(sf::Vector2f(0.f,0.f), sf::Vector2f(700.f,  700.f));

    //gun

    //neco arc
    Player neco("chaos.png");
    Weapon gun("Gun.png", neco);
    //our room
    std::vector<Walls> room1;
    std::vector<Walls> room2;
    std::vector<std::vector<Walls>> rooms;


    //Object of wall to draw it in while loop
    Walls wall1 = Walls(300.f, 100.f,50.f, 500.f, sf::Color::Green);
    Walls wall2 = Walls(600.f, 100.f,50.f, 500.f, sf::Color::Red);
    Walls wall3 = Walls(300.f, 100.f,350.f, 50.f, sf::Color::Blue);
    Walls wall4 = Walls(300.f, 900.f,500.f, 50.f, sf::Color::Cyan);

    Walls wall11 = Walls(700.f, 100.f, 50.f, 500.f, sf::Color::Yellow);
    Walls wall21 = Walls(1000.f, 100.f,50.f, 500.f, sf::Color::Magenta);
    Walls wall31 = Walls(700.f, 100.f,350.f, 50.f, sf::Color::Blue);
    Walls wall41 = Walls(700.f, 900.f,500.f, 50.f, sf::Color::Cyan);

    room2.push_back(wall11);
    room2.push_back(wall21);
    room2.push_back(wall31);
    room2.push_back(wall41);

    room1.push_back(wall1);
    room1.push_back(wall2);
    room1.push_back(wall3);
    room1.push_back(wall4);

    rooms.push_back(room1);
    rooms.push_back(room2);

    //to evade problem of movement relying on frame rate
    sf::Clock clock;

    //if window is open, our game starts processing
    while(window.isOpen()){

        //to check for event's on window directly
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // pressing X to close window
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {

                    }
                    if(event.mouseButton.button == sf::Mouse::Right){

                    }
                    break;
                //todo pausing game
                default:
                    break;
            }
        }

        //
        sf::Time elapsed = clock.restart();
        float deltatime = elapsed.asSeconds();

        //character movement
        neco.movePlayer(deltatime, rooms, window);
        neco.rotateWithMouse(window);

        //Clear previous frame
        window.clear(sf::Color::Black);

        window.setView(view);
        for(const auto& room : rooms){
            for(auto wall : room){
                wall.drawWall(window);
        }}
        //Draw character after clearing previous frame
        neco.drawPlayer(window);
        gun.drawWeapon(window, neco);
        gun.rotateWithMouse(window);
        view.setCenter(neco.getPos());

        //next frame
        window.display();

    }


}
