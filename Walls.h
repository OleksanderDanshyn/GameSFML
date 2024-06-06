// Walls.h
// Created by HACKERMAN on 006 06.06.24

#ifndef GAMEPROJECT_WALLS_H
#define GAMEPROJECT_WALLS_H

#include <SFML/Graphics.hpp>

class Walls {
private:
    sf::RectangleShape rectangle;

public:
    Walls(float x, float y, float width, float height, sf::Color color);

    void drawWall(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
};

#endif //GAMEPROJECT_WALLS_H
