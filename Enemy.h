//
//
//

#ifndef GAMEPROJECT_ENEMY_H
#define GAMEPROJECT_ENEMY_H
#include <SFML/Graphics.hpp>
#include "Player.h"
class Player;
class RoomManager;
class Enemy {
private:
    sf::Sprite enemy;
    sf::Sprite invisibleSprite;
    static sf::Texture texture;
    float speedEnemy;
public:

    explicit Enemy( sf::Vector2f position);
    void drawEnemy(sf::RenderWindow &window) const;

    sf::FloatRect getHitBox() const;
    void checkCollisions(const std::vector<Walls>& walls, const std::vector<Enemy>& enemies);
    void moveToPlayer(float deltaTime, Player& player);

    void killPlayer(Player& player, RoomManager& roomManager);
    bool killed();

};


#endif //GAMEPROJECT_ENEMY_H
