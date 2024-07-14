//
//
//

#ifndef ROOMSWITCHER_H
#define ROOMSWITCHER_H

#include <SFML/Graphics.hpp>
#include "RoomManager.h"

class RoomSwitcher {
public:
    RoomSwitcher(float x, float y, float width, float height, sf::Color color, sf::Vector2f targetPosition);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void setPositionAndSize(const sf::Vector2f &position, const sf::Vector2f &size);
private:
    sf::RectangleShape rectangle;
    sf::Vector2f targetPosition;

};

#endif // ROOMSWITCHER_H

