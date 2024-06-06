// Walls.cpp
// Created by HACKERMAN on 006 06.06.24

#include "Walls.h"

// Constructor
Walls::Walls(float x, float y, float width, float height, sf::Color color) {
    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
}

// Draw wall
void Walls::drawWall(sf::RenderWindow& window) {
    window.draw(rectangle);
}

// Get bounds of the wall
sf::FloatRect Walls::getBounds() const {
    return rectangle.getGlobalBounds();
}
