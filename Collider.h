//
// Created by HACKERMAN on 016 16.05.24.
//

#ifndef GAMEPROJECT_COLLIDER_H
#define GAMEPROJECT_COLLIDER_H
class Wall{
private:
    float side1;
    float side2;
public:
    Wall(float side1, float side2) : side1(side1), side2(side2) {}

    auto drawWall(){

        sf::Rect<float>rectangle = sf::FloatRect(1000, 1000, 100, 100);
        return rectangle;
    }
    auto collisionTest(Player player){
        return drawWall().intersects(player.sprite.getGlobalBounds());
    }
};
#endif //GAMEPROJECT_COLLIDER_H
