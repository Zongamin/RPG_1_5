#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>

class Enemy
{

    private:
        std::string enemyName = "Enemyname";

    public:
        
        // Attribute
        
        double level{};
        double health{};
        double realHealth{};
        double mana{};
        double realMana{};
        double strength{};
        double intelligence{};
        double dexterity{};
        double luck{};
        double endurance{};
        
        // Inventar

        double gold{};
        double scrapMetal{};
        double aluminum{};
        double copper{};
        double manaPotion{};
        double healthPotion{};
        double weapons{};
        double armor{};
        double exp{};

        // Buffs

        double frozen{};
        double fireAura{};
        double poisoned{};
        double regenerationOn{};
        short picture{};
        bool permaDeath = true;
        

void setName(std::string enemyName)
{
    this->enemyName = enemyName;
    return; 

}

std::string getName()
{
    return this->enemyName;
}

};

#endif 