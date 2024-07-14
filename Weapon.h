//
//
//

#ifndef GAMEPROJECT_WEAPON_H
#define GAMEPROJECT_WEAPON_H
#include <SFML/Graphics.hpp>
#include "Player.h"
class Weapon {
private:
    sf::Sprite gun;
    sf::Texture texture;
public:
    int ammoCur;
    int maxAmmo;
    explicit Weapon(int maxAmmo);

    void useAmmo();

    void reload();

    bool canShoot() const;

    void upgradeAmmoMax();

    int getAmmoCur() const;

    int getMaxAmmo() const;

};
#endif //GAMEPROJECT_WEAPON_H
