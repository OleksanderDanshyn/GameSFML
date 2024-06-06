//
// Created by HACKERMAN on 006 06.06.24.
//

#include "Weapon.h"
#include <iostream>
#include "Player.h"


Weapon::Weapon(const std::string& textureDir, Player player) {
    if (!texture.loadFromFile(textureDir)) {
        std::cout << "error loading texture";
    }
    gun.setTexture(texture);
    gun.setOrigin(player.getPos());
    gun.setScale(0.1, 0.1);

}

void Weapon::drawWeapon(sf::RenderWindow& window, Player player){
    window.draw(gun);
    gun.setPosition(player.getPos());
}
void Weapon::rotateWithMouse(sf::RenderWindow& window) {
    // Get the mouse position relative to the window
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // Convert mouse position to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

    // Calculate the angle between the sprite and the mouse position
    sf::Vector2f spritePos = gun.getPosition();
    float deltaX = worldPos.x - spritePos.x;
    float deltaY = worldPos.y - spritePos.y;
    float angle = std::atan2(deltaY, deltaX) * 180 / 3.14159f;

    // Set the rotation of the sprite
    gun.setRotation(angle);
}

