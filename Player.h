//
//
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cmath>
#include "Walls.h"
#include "Weapon.h"
#include "RoomManager.h"
class Walls;
class RoomManager;
class Weapon;
class Player {

private:
    static sf::Texture texture;
    int score;
    float speed = 300.f;
    int curHealth;
    int maxHealth;
public:

    explicit Player();

    void drawPlayer(sf::RenderWindow& window) const;

    sf::Vector2<float> getPos();

    void rotateWithMouse(sf::RenderWindow& window);

    sf::Sprite sprite;

    sf::Sprite spriteVisible;

    void moveIfPossible(float offsetX, float offsetY, const std::vector<Walls>& rooms);

    sf::FloatRect getBounds() const;

    void movePlayer(float deltaTime, const std::vector<Walls>& rooms);

    void givePoint();

    void upgradePlayer(Weapon& gun);

    int getScore() const;

    void recieveDamage();

    int getHealth() const;

    void resetPosition(const RoomManager& roomManager);

    void reset();

    int getMaxHealth() const;
};

#endif // PLAYER_H
