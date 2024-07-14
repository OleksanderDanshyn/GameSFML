//
//All rooms+enemies are stored here as methods and stuff that is needed for their correct execution
//

#include "RoomManager.h"
#include "Enemy.h"
#include "Player.h"
RoomManager::RoomManager() {
    createRoom1();
}

const std::vector<Walls>& RoomManager::getCurrentRoom() const {
    return currentRoom;
}
std::vector<Enemy>& RoomManager::getEnemies() {
    return enemies;
}
sf::Vector2f RoomManager::getRoomChangerPosition() const {
    return roomChangerPosition;
}
sf::Vector2f RoomManager::getRoomChangerSize(){
    return roomChangerSize;
}
sf::Vector2f RoomManager::getPlayerStartPosition() const {
    return playerStartPosition;
}
//
//Every room has unique walls, enemies, exit and start locations
//roomChangerPosition - exit room
//playerStartPosition - spawn point
//
void RoomManager::createRoom2() {
    enemies.clear();
    currentRoom.clear();
    currentRoom.emplace_back(100.f,-100.f, 10.f, 1100.f, sf::Color::Green);
    currentRoom.emplace_back(100.f,-100.f, 800.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(100.f, 1000.f,100.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(400.f, 1000.f,100.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(500.f, 710.f, 10.f, 300.f, sf::Color::Green);
    currentRoom.emplace_back(500.f, 700.f, 400.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(900.f,-100.f, 10.f, 250.f, sf::Color::Green);
    currentRoom.emplace_back(900.f, 460.f, 10.f, 250.f, sf::Color::Green);

    currentRoom.emplace_back(900.f, -400.f, 50.f, 20.f,sf::Color::Green );
    currentRoom.emplace_back(1150.f,-400.f, 50.f, 20.f,sf::Color::Green );
    currentRoom.emplace_back(1200.f,-400.f, 800.f,10.f,sf::Color::Green );
    currentRoom.emplace_back(900.f, -600.f, 10.f, 500.f,sf::Color::Green );
    currentRoom.emplace_back(1200.f,-600.f, 10.f, 600.f,sf::Color::Green );
    currentRoom.emplace_back(1200.f, 300.f, 10.f, 400.f,sf::Color::Green );
    currentRoom.emplace_back(1200.f, 700.f, 800.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(2000.f,-400.f, 10.f, 1110.f,sf::Color::Green );
    currentRoom.emplace_back(2000.f,710.f, 10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(1500.f,1200.f,500.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(1500.f,1200.f,10.f, 510.f, sf::Color::Green);
    currentRoom.emplace_back(900.f, 1700.f,600.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(900.f, 1500.f,10.f, 200.f, sf::Color::Green);
    currentRoom.emplace_back(900.f, 1000.f,10.f, 200.f, sf::Color::Green);
    currentRoom.emplace_back(500.f, 1000.f,400.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(100.f, 1700.f,800.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(100.f, 1000.f,10.f, 700.f, sf::Color::Green);
    roomChangerPosition = sf::Vector2f(1950.f, 700.f);
    playerStartPosition = sf::Vector2f(1000.f, -700.f);
    roomChangerSize = sf::Vector2f (50.f, 500.f);

    enemies.emplace_back( sf::Vector2f(200.f, 400.f));
    enemies.emplace_back( sf::Vector2f(600.f, 400.f));
    enemies.emplace_back( sf::Vector2f(1000.f, 400.f));
    enemies.emplace_back( sf::Vector2f(1000.f, 700.f));
    enemies.emplace_back( sf::Vector2f(1400.f, 500.f));
    enemies.emplace_back( sf::Vector2f(200.f, 400.f));
    enemies.emplace_back( sf::Vector2f(200.f, 1200.f));

}

void RoomManager::createRoom1() {
    roomChangerPosition = sf::Vector2f(2500.f, 300.f);
    roomChangerSize = sf::Vector2f (50.f, 500.f);

    enemies.clear();
    currentRoom.clear();

    currentRoom.emplace_back(-200.f, -200.f, 10.f,  1500.f, sf::Color::Green);
    currentRoom.emplace_back(-200.f, -200.f, 2700.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(-200.f,  1300.f,2710.f,10.f, sf::Color::Green);

    currentRoom.emplace_back(-200.f,300.f,100.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(200.f,-200.f,10.f,  500.f, sf::Color::Green);
    currentRoom.emplace_back(110.f, 300.f,100.f, 10.f, sf::Color::Green);

    currentRoom.emplace_back(200.f, 300.f,100.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(600.f,-200.f,10.f,  500.f, sf::Color::Green);
    currentRoom.emplace_back(510.f, 300.f,100.f, 10.f, sf::Color::Green);

    currentRoom.emplace_back(600.f,  300.f,100.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(1000.f,-200.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(910.f,  300.f,100.f,10.f, sf::Color::Green);

    currentRoom.emplace_back(1000.f, 300.f,100.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(1400.f,-200.f,10.f,  500.f, sf::Color::Green);
    currentRoom.emplace_back(1310.f, 300.f,100.f, 10.f, sf::Color::Green);

    currentRoom.emplace_back(-200.f, 800.f,100.f,10.f, sf::Color::Blue);
    currentRoom.emplace_back(200.f, -200.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(110.f,  800.f,100.f,10.f, sf::Color::Green);

    currentRoom.emplace_back(-200.f,800.f,100.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(200.f, 800.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(110.f, 800.f,100.f,10.f, sf::Color::Green);

    currentRoom.emplace_back(200.f, 800.f,100.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(600.f, 800.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(510.f, 800.f,100.f,10.f, sf::Color::Green);

    currentRoom.emplace_back(600.f, 800.f,100.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(1000.f,800.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(910.f, 800.f,100.f,10.f, sf::Color::Green);

    currentRoom.emplace_back(1000.f, 800.f,100.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(1400.f, 800.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(1310.f, 800.f,100.f,10.f, sf::Color::Green);

    currentRoom.emplace_back(2500.f, 800.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(2500.f, 300.f,500.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(2500.f, 800.f,500.f,10.f, sf::Color::Green);
    currentRoom.emplace_back(2500.f,-200.f,10.f, 500.f, sf::Color::Green);
    enemies.emplace_back( sf::Vector2f(2500.f, 400.f));
    enemies.emplace_back( sf::Vector2f(2200.f, 800.f));
    enemies.emplace_back( sf::Vector2f(1600.f, 600.f));
    enemies.emplace_back( sf::Vector2f(0.f, 800.f));

    playerStartPosition = sf::Vector2f(0.f, 0.f);


}
void RoomManager::createRoom3() {
    enemies.clear();
    currentRoom.clear();
    currentRoom.emplace_back(0.f,     1600.f,2010.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(0.f,     800.f, 10.f,  800.f, sf::Color::Green);
    currentRoom.emplace_back(2000.f , 800.f, 10.f,  800.f, sf::Color::Green);
    currentRoom.emplace_back(0.f,     800.f, 10.f,  800.f, sf::Color::Green);
    currentRoom.emplace_back(0.f,     800.f, 510.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(1500.f,  800.f, 500.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(1500.f, -200.f, 10.f,  1000.f, sf::Color::Green);
    currentRoom.emplace_back(500.f,  -200.f, 10.f,  1000.f, sf::Color::Green);
    currentRoom.emplace_back(0.f,    -200.f, 510.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(1500.f, -200.f, 510.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(2000.f, -1000.f,10.f,  800.f, sf::Color::Green);
    currentRoom.emplace_back(0.f,    -1000.f,10.f,  800.f, sf::Color::Green);
    currentRoom.emplace_back(0.f,    -1000.f,900.f,  10.f, sf::Color::Green);
    currentRoom.emplace_back(1100.f,    -1000.f,900.f,  10.f, sf::Color::Green);

    enemies.emplace_back( sf::Vector2f(100.f, 1400.f));
    enemies.emplace_back( sf::Vector2f(1600.f, 1400.f));
    enemies.emplace_back( sf::Vector2f(1000.f, 600.f));
    enemies.emplace_back( sf::Vector2f(1000.f, 400.f));
    enemies.emplace_back( sf::Vector2f(100.f, -500.f));
    enemies.emplace_back( sf::Vector2f(1600.f, -500.f));
    roomChangerPosition = sf::Vector2f(900.f, -1000.f);
    roomChangerSize = sf::Vector2f(200.f, 20.f);
    playerStartPosition = sf::Vector2f(1000.f, 1400.f);
}
void RoomManager::createRoom4(){
    roomChangerPosition = sf::Vector2f(1450.f, 1150.f);
    roomChangerSize = sf::Vector2f (50.f, 200.f);
    enemies.clear();
    currentRoom.clear();
    currentRoom.emplace_back(0.f, 0.f,1000.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(0.f, 0.f,10.f, 500.f, sf::Color::Green);
    currentRoom.emplace_back(0.f, 500.f,500.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(1000.f, 0.f,10.f, 1000.f, sf::Color::Green);
    currentRoom.emplace_back(1000.f, 1000.f,500.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(500.f, 500.f,10.f, 1000.f, sf::Color::Green);
    currentRoom.emplace_back(500.f, 1500.f,1010.f, 10.f, sf::Color::Green);
    currentRoom.emplace_back(1500.f, 1350.f,10.f, 150.f, sf::Color::Green);
    currentRoom.emplace_back(1500.f, 1000.f,10.f, 150.f, sf::Color::Green);

    enemies.emplace_back( sf::Vector2f(650.f, 150.f));
    enemies.emplace_back( sf::Vector2f(650.f, 1000.f));
    enemies.emplace_back( sf::Vector2f(1000.f, 1000.f));

    playerStartPosition = sf::Vector2f(150.f, 150.f);

}


