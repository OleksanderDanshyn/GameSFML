//
//We need to kill enemies and draw bullets, nothing hard again
//

#include "Bullet.h"
#include "Player.h"
#include "Walls.h"
#include "Enemy.h"
Bullet::Bullet(const sf::Vector2f& gunPos, const sf::Vector2f& trajectory, float speed)
        : direction(trajectory), speed(speed) {
    pellet.setSize(sf::Vector2f(5.f, 5.f));
    pellet.setPosition(gunPos);
    pellet.setFillColor(sf::Color::Red);
}

void Bullet::drawBullet(sf::RenderWindow& window) {
        window.draw(pellet);
    }

void Bullet::update(float deltaTime){
    pellet.move(direction*speed*deltaTime);
}

bool Bullet::collide(const Walls& wall){
    return pellet.getGlobalBounds().intersects(wall.getBounds());
}
bool Bullet::kill(const Enemy& enemy){
    return pellet.getGlobalBounds().intersects(enemy.getHitBox());
}




