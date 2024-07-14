//
//Printing interface on screen
//

#include "GUI.h"
GUI::GUI(){
    if (!font.loadFromFile(R"(C:\Users\User\CLionProjects\gameProject\resources\ShogunsClan.ttf)")) {
        std::cout << "error loading texture";
    }
healthText.setFont(font);
healthText.setCharacterSize(40);
healthText.setFillColor(sf::Color::White);
healthText.setPosition(10.f, 10.f);

ammoText.setFont(font);
ammoText.setCharacterSize(40);
ammoText.setFillColor(sf::Color::White);
ammoText.setPosition(10.f, 110.f);

scoreText.setFont(font);
scoreText.setCharacterSize(40);
scoreText.setFillColor(sf::Color::White);
scoreText.setPosition(1600.f, 10.f);
}
void GUI::updateGUI(const Player& player, const Weapon& gun) {
    healthText.setString("Health: " + std::to_string(player.getHealth()) + "//" + std::to_string(player.getMaxHealth()));

    ammoText.setString("Ammo: " + std::to_string(gun.getAmmoCur()) + "//" + std::to_string(gun.getMaxAmmo()));

    scoreText.setString("Score: " + std::to_string(player.getScore()));
}
void GUI::draw(sf::RenderWindow &window) {
    window.draw(healthText);

    window.draw(ammoText);

    window.draw(scoreText);
}