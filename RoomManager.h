//
//
//

#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <vector>
#include "Walls.h"
#include "Enemy.h"
#include "RoomSwitcher.h"
#include <SFML/System/Vector2.hpp>
class Enemy;
class RoomSwitcher;
class RoomManager {
private:
    std::vector<Walls> currentRoom;
    sf::Vector2f roomChangerPosition;
    sf::Vector2f playerStartPosition;
    std::vector<Enemy> enemies;
    sf::Vector2f roomChangerSize;
public:
    RoomManager();

    const std::vector<Walls>& getCurrentRoom() const;

    void createRoom1();

    void createRoom2();

    sf::Vector2f getRoomChangerPosition() const;

    sf::Vector2f getPlayerStartPosition() const;

    std::vector<Enemy> &getEnemies();

    sf::Vector2f getRoomChangerSize();

    void createRoom3();

    void createRoom4();
};

#endif // ROOMMANAGER_H
