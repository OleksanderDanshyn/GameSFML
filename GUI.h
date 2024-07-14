//
//
//

#ifndef GAMEPROJECT_GUI_H
#define GAMEPROJECT_GUI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Weapon.h"
class Player;
class GUI {
private:
    sf::Font font;
    sf::Text healthText;
    sf::Text ammoText;
    sf::Text scoreText;
public:
    GUI();

    void draw(sf::RenderWindow& window);

    void updateGUI(const Player& player, const Weapon& gun);
};


#endif //GAMEPROJECT_GUI_H
