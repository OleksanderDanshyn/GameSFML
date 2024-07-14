//
// Everything for player, moving, rotating, collisions with walls and so on
//

#include "Player.h"
#include <iostream>
#include <random>
sf::Texture Player::texture;
// Loading texture, two sprites to not get stuck while rotating
Player::Player() : score(0), maxHealth(2) {
    if (!texture.loadFromFile(R"(C:\Users\User\CLionProjects\gameProject\resources\player.png)")) {
        std::cout << "error loading texture";
    }
    curHealth = maxHealth;

    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.5f, 0.5f));
    sf::FloatRect boundingBox = sprite.getLocalBounds();
    sprite.setOrigin(boundingBox.width / 2.f, boundingBox.height / 2.f);

    spriteVisible.setTexture(texture);
    spriteVisible.setScale(sf::Vector2f(0.7f, 0.7f));
    spriteVisible.setOrigin(boundingBox.width / 2.f, boundingBox.height / 2.f);
}

void Player::drawPlayer(sf::RenderWindow& window) const {
    window.draw(spriteVisible);
}

sf::Vector2<float> Player::getPos() {
    return sprite.getPosition();
}
//I need every level to have special spawn point
void Player::resetPosition(const RoomManager& roomManager) {
    sprite.setPosition(roomManager.getPlayerStartPosition());
    spriteVisible.setPosition(roomManager.getPlayerStartPosition());
}

sf::FloatRect Player::getBounds() const {
    return sprite.getGlobalBounds();
}

void Player::rotateWithMouse(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mouseCoords = window.mapPixelToCoords(mousePos);

    //https://en.sfml-dev.org/forums/index.php?topic=8977.0
    sf::Vector2f spritePos = sprite.getPosition();
    float deltaX = mouseCoords.x - spritePos.x;
    float deltaY = mouseCoords.y - spritePos.y;
    float angle = std::atan2(deltaY, deltaX) * 180 / 3.14159f;
    spriteVisible.setRotation(angle);
}
// Move when button is pressed
void Player::movePlayer(float deltaTime, const std::vector<Walls>& rooms) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += speed * deltaTime;
    }

    // To not move at double speed
    if (movement.x != 0.f && movement.y != 0.f) {
        movement /= std::sqrt(2.f);
    }

    //To move while hitting wall(pressing W and D while hitting a wall from one of those sides still let's you walk)
    moveIfPossible(movement.x, 0.f, rooms);
    moveIfPossible(0.f, movement.y, rooms);
}

//Collision check
void Player::moveIfPossible(float offsetX, float offsetY, const std::vector<Walls>& rooms) {
    // We check where player tries to go and don't let him if he does
    sf::FloatRect hitBox = sprite.getGlobalBounds();
    hitBox.left += offsetX;
    hitBox.top += offsetY;
    bool canMove = true;
    for (const auto& wall : rooms) {
            if (hitBox.intersects(wall.getBounds())) {
                canMove = false;
                break;
        }
    }
    if (canMove) {
        sprite.move(offsetX, offsetY);
        spriteVisible.move(offsetX, offsetY);
    }
}

//Pretty simple upgrades, just increasing stats when we hit 500 points
void Player::upgradePlayer(Weapon& gun){
    if(score % 500 == 0){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 3);
        int randomToggle = dist(gen);
        if(randomToggle == 1){
            speed +=100;
        }
        else if(randomToggle == 2){
            if(curHealth == maxHealth){
                maxHealth += 1;
                curHealth = maxHealth;
            }
            else{
                curHealth = maxHealth;
            }
        }
        else if(randomToggle == 3){
            gun.upgradeAmmoMax();
        }
    }
}

int Player::getScore() const {
    return score;
}

int Player::getHealth() const{
    return curHealth;
}

int Player::getMaxHealth() const{
    return maxHealth;
}

void Player::givePoint(){
    score += 200;
}

void Player::reset(){
    score = 0;
    curHealth = maxHealth;
    speed = 300.f;
}

void Player::recieveDamage(){
    if(curHealth > 0)
        curHealth -= 1;
}
