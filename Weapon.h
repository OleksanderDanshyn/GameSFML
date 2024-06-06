//
// Created by HACKERMAN on 006 06.06.24.
//

#ifndef GAMEPROJECT_WEAPON_H
#define GAMEPROJECT_WEAPON_H
#include <SFML/Graphics.hpp>
#include "Player.h"

class Weapon {
private:
    sf::Sprite gun;
    sf::Texture texture;
public:
    Weapon(const std::string &textureDir, Player player);
    void drawWeapon(sf::RenderWindow &window);

    void drawWeapon(sf::RenderWindow &window, Player player);

    void rotateWithMouse(sf::RenderWindow &window);
};


#endif //GAMEPROJECT_WEAPON_H
