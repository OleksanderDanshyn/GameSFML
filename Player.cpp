// Player.cpp
// Created by HACKERMAN on 015 15.05.24

#include "Player.h"
#include "Walls.h"
#include <iostream>

// Default constructor
Player::Player() = default;

// Constructor with texture loading
Player::Player(const std::string& textureDir) {
    if (!texture.loadFromFile(textureDir)) {
        std::cout << "error loading texture";
    }
    sprite.setTexture(texture);
    spriteVisible.setTexture(texture);
    // Making it a bit smaller
    sprite.setScale(sf::Vector2f(0.2f, 0.15f));
    spriteVisible.setScale(sf::Vector2f(0.2f, 0.15f));

    // Changing origin point from (0,0) to the middle of the bounding box
    sf::FloatRect boundingBox = sprite.getLocalBounds();
    sprite.setOrigin(boundingBox.width / 2.f, boundingBox.height / 2.f);
    spriteVisible.setOrigin(boundingBox.width / 2.f, boundingBox.height / 2.f);
}

// Draw player
void Player::drawPlayer(sf::RenderWindow& window) const {
    window.draw(spriteVisible);
}

// Get position of the player
sf::Vector2f Player::getPos() {
    // Get the origin point coordinates of the sprite
    return sprite.getPosition();
}
void Player::rotateWithMouse(sf::RenderWindow& window) {
    // Get the mouse position relative to the window
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // Convert mouse position to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

    // Calculate the angle between the sprite and the mouse position
    sf::Vector2f spritePos = sprite.getPosition();
    float deltaX = worldPos.x - spritePos.x;
    float deltaY = worldPos.y - spritePos.y;
    float angle = std::atan2(deltaY, deltaX) * 180 / 3.14159f;

    // Set the rotation of the sprite
    spriteVisible.setRotation(angle);
}
// Move player
void Player::movePlayer(float deltaTime, std::vector<std::vector<Walls>> rooms, sf::RenderWindow& window) {
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

    // Normalize speed if moving diagonally
    if (movement.x != 0.f && movement.y != 0.f) {
        movement /= std::sqrt(2.f);
    }

    // Move separately to handle collisions better
    moveIfPossible(movement.x, 0.f, rooms);
    moveIfPossible(0.f, movement.y, rooms);
}

// Move if possible considering walls
void Player::moveIfPossible(float offsetX, float offsetY, std::vector<std::vector<Walls>>& rooms) {
    // Check where the player tries to walk to avoid getting stuck in walls
    sf::FloatRect hitBox = sprite.getGlobalBounds();
    hitBox.left += offsetX;
    hitBox.top += offsetY;

    // Check every wall passed to this function
    bool canMove = true;
    for (const auto& room : rooms) {
        for (const auto& wall : room) {
            if (hitBox.intersects(wall.getBounds())) {
                canMove = false;
                break; // Exit loop once a collision is detected
            }
        }
    }

    // Move only when there is no collision in the direction of movement
    if (canMove) {
        sprite.move(offsetX, offsetY);
        spriteVisible.move(offsetX, offsetY);
    }
}

