////The only problem is that filepath should be full, so to execute it from different place
////filepath must be changed, i couldn't find a solution
////
#include <SFML/Graphics.hpp>
#include <random>
#include <cmath>
#include <unordered_set>

#include "Player.h"
#include "Walls.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Enemy.h"
#include "RoomSwitcher.h"
#include "RoomManager.h"
#include "GUI.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Window");
    window.setVerticalSyncEnabled(true);

    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(1400.f, 1200.f));

    Weapon gun(10);
    Player player;
    GUI gui;

    //Bullets disappear if not in vector, view jeep text in one place
    std::vector<Bullet> bullets;

    RoomManager roomManager;
    RoomSwitcher roomChanger(0, 0, 50.f, 50.f, sf::Color::Red,
                             roomManager.getRoomChangerPosition());


    sf::Clock clock;

    // This set keeps track of used rooms to not go into same one
    std::unordered_set<int> usedToggles;

    while (window.isOpen()) {
        //every frame we remove everything
        window.clear(sf::Color::Black);
        window.setView(view);
        view.setCenter(player.getPos());
        sf::Event event{};
        while (window.pollEvent(event)) {
            switch (event.type) {
                // red X in top right corner
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    ////Shooting mechanic
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (gun.canShoot()) {
                            //Those values vary depending on sprite, just so that bullet's fly
                            sf::Vector2f bulletSpawnOffset(300.f, 150.f);
                            sf::Vector2f bulletSpawnPosition = player.spriteVisible.getTransform()
                                    .transformPoint(bulletSpawnOffset);

                            // We get mouse coords and calculate distance from gun to mouse
                            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                            sf::Vector2f mouseCoords = window.mapPixelToCoords(mousePos);
                            sf::Vector2f trajectory = mouseCoords - bulletSpawnPosition;
                            //https://en.sfml-dev.org/forums/index.php?topic=20359.0 source for this formula
                            float length = std::sqrt(trajectory.x * trajectory.x + trajectory.y * trajectory.y);
                            if (length != 0) {
                                trajectory /= length;
                                bullets.emplace_back(bulletSpawnPosition, trajectory, 1200.f);
                                gun.useAmmo();
                            }
                        }
                    }
                    break;

                case sf::Event::KeyPressed:
                    gun.reload();
                    break;
                default:
                    break;
            }
        }

        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        ////Bullets hit
        for (auto bulletIt = bullets.begin(); bulletIt < bullets.end();) {
            bulletIt->update(deltaTime);
            bool collisionDetected = false;
            // Check for collisions with walls
            for (const auto &wall: roomManager.getCurrentRoom()) {
                if (bulletIt->collide(wall)) {
                    collisionDetected = true;
                    break;
                }
            }

            // Check collisions with enemies only if there isn't collision with walls
            if (!collisionDetected) {
                auto& enemies = roomManager.getEnemies();
                for (auto enemyIt = enemies.begin(); enemyIt < enemies.end(); ) {
                    if (bulletIt->kill(*enemyIt)) {
                        collisionDetected = true;
                        enemies.erase(enemyIt);
                        player.givePoint();
                        player.upgradePlayer(gun);
                        break;
                    } else {
                        ++enemyIt;
                    }
                }
            }
                if (collisionDetected) {
                    bulletIt = bullets.erase(bulletIt);
                } else {
                    ++bulletIt;
                }
            }

            for (Walls wall: roomManager.getCurrentRoom()) {
                wall.drawWall(window);
            }
            for (Enemy &enemy: roomManager.getEnemies()) {
                enemy.drawEnemy(window);
                enemy.checkCollisions(roomManager.getCurrentRoom(), roomManager.getEnemies());
                enemy.moveToPlayer(deltaTime, player);
                enemy.killPlayer(player, roomManager);
                roomChanger.setPositionAndSize(roomManager.getRoomChangerPosition(),
                                               roomManager.getRoomChangerSize());
            }


            ////Change levels
            if (roomChanger.getBounds().intersects(player.getBounds())) {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dist(1, 3);
                int randomToggle = dist(gen);

                while (usedToggles.find(randomToggle) != usedToggles.end()) {
                    randomToggle = dist(gen);
                }

                usedToggles.insert(randomToggle);
                if (randomToggle == 1) {
                    roomManager.createRoom2();
                }
                else if(randomToggle == 2){
                    roomManager.createRoom3();
                }
                else if(randomToggle == 3){
                    roomManager.createRoom4();
                }

                if (usedToggles.size() == 3) {
                    usedToggles.clear();
                }

                roomChanger.setPositionAndSize(roomManager.getRoomChangerPosition(),
                                               roomManager.getRoomChangerSize());
                player.sprite.setPosition(roomManager.getPlayerStartPosition());
                player.spriteVisible.setPosition(roomManager.getPlayerStartPosition());
            }
            for (Bullet &bullet: bullets) {
                bullet.drawBullet(window);
            }
            player.drawPlayer(window);

            player.movePlayer(deltaTime, roomManager.getCurrentRoom());

            player.rotateWithMouse(window);

            roomChanger.draw(window);

            //https://www.reddit.com/r/sfml/comments/pwlme7/how_can_i_keep_the_text_in_a_fixed_position_even/
            window.setView(window.getDefaultView());

            gui.updateGUI(player, gun);

            gui.draw(window);

            window.display();
        }

        return 0;
    }
