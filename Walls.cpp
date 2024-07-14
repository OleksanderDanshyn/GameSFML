#include "Walls.h"

// Constructor
Walls::Walls(float x, float y, float width, float height, sf::Color color)
        : vertices(sf::Quads, 4) {
    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setFillColor(color);

    initializeVertices(x, y, width, height, color);
}

// Initialize the vertex array
void Walls::initializeVertices(float x, float y, float width, float height, sf::Color color) {
    vertices[0].position = sf::Vector2f(x, y);
    vertices[1].position = sf::Vector2f(x + width, y);
    vertices[2].position = sf::Vector2f(x + width, y + height);
    vertices[3].position = sf::Vector2f(x, y + height);

    for (int i = 0; i < 4; ++i) {
        vertices[i].color = color;
    }
}

// Draw wall
void Walls::drawWall(sf::RenderWindow& window) {
    window.draw(vertices);
}

// Get bounds of the wall
sf::FloatRect Walls::getBounds() const {
    return rectangle.getGlobalBounds();
}

// Set the wall color
void Walls::setColor(sf::Color color) {
    rectangle.setFillColor(color);
    for (int i = 0; i < 4; ++i) {
        vertices[i].color = color;
    }
}

// Get the vertex array for rendering
const sf::VertexArray& Walls::getVertexArray() const {
    return vertices;
}
