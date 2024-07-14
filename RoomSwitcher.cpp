#include "RoomSwitcher.h"

RoomSwitcher::RoomSwitcher(float x, float y, float width, float height, sf::Color color, sf::Vector2f targetPosition)
        : rectangle(sf::Vector2f(width, height)) {
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
}

void RoomSwitcher::draw(sf::RenderWindow& window) {
    window.draw(rectangle);
}

sf::FloatRect RoomSwitcher::getBounds() const {
    return rectangle.getGlobalBounds();
}
void RoomSwitcher::setPositionAndSize(const sf::Vector2f& position, const sf::Vector2f& size) {
    rectangle.setPosition(position);
    rectangle.setSize(size);
}

