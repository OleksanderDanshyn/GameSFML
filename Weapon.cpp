//
//Ammo system, could implement it somewhere else, was using it for drawing weapon previously. Can add more types of weapons
//

#include "Weapon.h"

//ammo is limited, need to reload from time to time
Weapon::Weapon(int maxAmmoVar) : ammoCur(maxAmmoVar) {
    maxAmmo = maxAmmoVar;
}

void Weapon::useAmmo() {
    if(ammoCur > 0){
        --ammoCur;
    }
}
bool Weapon::canShoot() const {
    return ammoCur > 0;
}
void Weapon::reload() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        ammoCur = maxAmmo;
    }
}
void Weapon::upgradeAmmoMax(){
    maxAmmo += 1;
}

int Weapon::getAmmoCur() const {
    return ammoCur;
}

int Weapon::getMaxAmmo() const {
    return maxAmmo;
}




