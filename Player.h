//
// Created by HACKERMAN on 015 15.05.24.
//

#ifndef GAMEPROJECT_PLAYER_H
#define GAMEPROJECT_PLAYER_H


class Player {


public:
    sf::Texture texture;
    sf::Sprite sprite;
    Player(){

    };

    Player(std::string textureDir){

        if (!texture.loadFromFile("chaos.png"))
        {
            std::cout << "error";
        }
        sprite.setTexture(texture);
        sprite.setScale(sf::Vector2f(0.2f, 0.15f));
    }
    auto drawPlayer(sf::RenderWindow &window){
        window.draw(sprite);
    }
    auto getSprite(){
        return sprite;
    }

    void movePlayer(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        sprite.move(10, 0);
    }
    else if(sf::Keyboard::isKeyPressed( sf::Keyboard::A)){
        sprite.move(-10, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        sprite.move(0, -10);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        sprite.move(0, 10);
    }
    }
};


#endif //GAMEPROJECT_PLAYER_H
