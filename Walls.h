#ifndef WALLS_H
#define WALLS_H

#include <SFML/Graphics.hpp>
#include <functional>

class Walls {
public:
    // Constructor
    Walls(float x, float y, float width, float height, sf::Color color);

    // Draw wall
    void drawWall(sf::RenderWindow& window);

    // Get bounds of the wall
    sf::FloatRect getBounds() const;

    // Set the wall color (optional)
    void setColor(sf::Color color);

    // Get the vertex array for rendering
    const sf::VertexArray& getVertexArray() const;

private:
    sf::RectangleShape rectangle; // Used for collision detection
    sf::VertexArray vertices; // Used for rendering

    void initializeVertices(float x, float y, float width, float height, sf::Color color);
};

#endif // WALLS_H
