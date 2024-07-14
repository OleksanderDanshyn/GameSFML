//
//Same as player, everything about enemies
//

#include "Enemy.h"
#include "Walls.h"
#include "Player.h"
#include <iostream>

sf::Texture Enemy::texture;
//give every enemy static texture
Enemy::Enemy(sf::Vector2f position) : speedEnemy(300.f){
     if (!texture.loadFromFile(R"(C:\Users\User\CLionProjects\gameProject\resources\enemy.png)")) {
         std::cerr << "Failed to load enemy texture!" << std::endl;
     }
    enemy.setTexture(texture);
    invisibleSprite.setTexture(texture);

    enemy.setScale(0.7f, 0.7f);
    invisibleSprite.setScale(0.7f, 0.7f);

    enemy.setPosition(position);
    invisibleSprite.setPosition(position);
}

//https://en.sfml-dev.org/forums/index.php?topic=20359.0 logic is nearly the same
void Enemy::moveToPlayer(float deltaTime, Player& player) {
    sf::Vector2f vecToPlayer = player.getPos() - enemy.getPosition();
    float eucDist = std::sqrt(vecToPlayer.x * vecToPlayer.x + vecToPlayer.y * vecToPlayer.y);

    if (eucDist != 0) {
        vecToPlayer /= eucDist;
    }
    sf::Vector2f movement = vecToPlayer * speedEnemy * deltaTime;
    enemy.move(movement);

    //Rotate toward player https://en.sfml-dev.org/forums/index.php?topic=8977.0
    float angle = std::atan2(vecToPlayer.y, vecToPlayer.x) * 180 / 3.14159f;
    enemy.setRotation(angle);
}

void Enemy::drawEnemy(sf::RenderWindow& window) const {
    window.draw(enemy);
}

sf::FloatRect Enemy::getHitBox() const {
    return enemy.getGlobalBounds();
}

void Enemy::killPlayer(Player& player, RoomManager& roomManager){
    if(player.getBounds().intersects(enemy.getGlobalBounds())){
        player.recieveDamage();
        if(player.getHealth() == 0){
            roomManager.createRoom1();
            player.resetPosition(roomManager);
            player.reset();
        }
        else{
            player.resetPosition(roomManager);
        }
    }
}

//https://cplusplus.com/forum/beginner/283735/
//found example here, changed it into this mess
void Enemy::checkCollisions(const std::vector<Walls>& walls, const std::vector<Enemy>& enemies) {
    sf::FloatRect enemyBounds = enemy.getGlobalBounds();

    //Same as with anything, go through every wall we have, check intersection of floatRect
    for (const Walls& wall : walls) {
        sf::FloatRect wallBounds = wall.getBounds();
        if (enemyBounds.intersects(wallBounds)) {
            // We don't have method to get anything outside left top corner, so we do it this way
            //It goes like this: check how deep is right side of enemy in wall; how deep left side of enemy is in wall and so on
            //Same thing with top and bottom, we have only left/top/height/width, so we need to shuffle them between different sides
            float rightSideColl = enemyBounds.left + enemyBounds.width - wallBounds.left;
            float leftSideColl = wallBounds.left + wallBounds.width - enemyBounds.left;
            float bottomSideColl = enemyBounds.top + enemyBounds.height - wallBounds.top;
            float topSideColl = wallBounds.top + wallBounds.height - enemyBounds.top;

            // When collision happens, we check from which side it happens: shorter distance shows where wall is for enemy
            float overlapX;
            if (rightSideColl < leftSideColl) {
                overlapX = -rightSideColl;
            } else {
                overlapX = leftSideColl;
            }
            float overlapY;
            if (bottomSideColl < topSideColl) {
                overlapY = -bottomSideColl;
            } else {
                overlapY = topSideColl;
            }

            // then we check is it vertical or horizontal collision and move enemy accordingly
            if (std::abs(overlapX) < std::abs(overlapY)) {
                enemy.move(sf::Vector2f(overlapX, 0));
            } else {
                enemy.move(sf::Vector2f(0, overlapY));
            }
        }
    }

    // Check for collision with other enemies
    //https://en.sfml-dev.org/forums/index.php?topic=20359.0 source for this formula
    for (const Enemy& otherEnemy : enemies) {
        if (&otherEnemy != this) {
            if (enemyBounds.intersects(otherEnemy.getHitBox())) {
                sf::Vector2f displacement = enemy.getPosition() - otherEnemy.enemy.getPosition();
                float length = std::sqrt(displacement.x * displacement.x + displacement.y * displacement.y);
                if (length != 0) {
                    displacement /= length;
                    enemy.move(displacement);
                }
            }
        }
    }
}
