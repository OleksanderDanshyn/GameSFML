// Player.h
// Created by HACKERMAN on 015 15.05.24

#ifndef GAMEPROJECT_PLAYER_H
#define GAMEPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <string>

// Forward declaration of Walls class
class Walls;

class Player {
public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite spriteVisible;
    float speed = 200.f;

    Player();
    explicit Player(const std::string& textureDir);

    void drawPlayer(sf::RenderWindow& window) const;
    sf::Vector2f getPos();
    void movePlayer(float deltaTime, std::vector<std::vector<Walls>> rooms, sf::RenderWindow& window);

    void rotateWithMouse(sf::RenderWindow &window);
private:
    void moveIfPossible(float offsetX, float offsetY, std::vector<std::vector<Walls>>& rooms);


};

#endif //GAMEPROJECT_PLAYER_H
