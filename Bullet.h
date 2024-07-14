//
//
//

#ifndef GAMEPROJECT_BULLET_H
#define GAMEPROJECT_BULLET_H
#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Player.h"
#include "Enemy.h"

class Bullet {
private:
    sf::RectangleShape pellet;
    sf::Vector2f direction;
    float speed;
public:
    explicit Bullet(const sf::Vector2f& gunPos, const sf::Vector2f& trajectory, float speed);

    void drawBullet(sf::RenderWindow& window);

    void update(float deltaTime);

    bool collide(const Walls& wall);

    bool kill(const Enemy& enemy);
};


#endif //GAMEPROJECT_BULLET_H
