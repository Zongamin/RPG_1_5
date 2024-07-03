#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>


class Player
{
    private:
            
        std::string playerName = "Player";
    
    public:
        
        // Attribute
    
        double level{};
        double exp{};
        double realExp{};
        double health{};
        double realHealth{};
        double mana{};
        double realMana{};
        double strength{};
        double intelligence{};
        double dexterity{};
        double luck{};
        double endurance{};
        double skillPoints{};
        int actionPoints{};
        int realActionPoints{};

        // Inventar

        short key{};
        double capacity{};
        double realCapacity{};
        double gold{};
        double herbs{};
        double scrapMetal{};
        double aluminum{};
        double copper{};
        double manaPotion{};
        double healthPotion{};
        double regenPotion{};
        double resurrectionPoition{};
        double weaponDmg{};
        double armorDmgReduce{};
        double weapons[500];
        double armor[500];

        // Buffs

        int fireAura{};
        int regenerationOn{};
        int traps{};
        bool permaDeath{};
        bool specialRoom{};
        bool escape{};
        bool block{};

        // Statistics

        bool roomCleared{};
        double currentRoom{};
        double rooms{};
        double monsters{};
        double bosses{};
        double crafted{};
        double deaths{};
        
        
void damage(double damage)
{
    this->realHealth -= damage;
    
    if (this->realHealth < this->health)
    {
        std::cout << "Tod";
        return;
    }
    return;
}

void heal(double heal)
{
    this->realHealth += heal;
    if (this->realHealth > this->health)
    {
        this->realHealth = this->health;
        return;
    }
    return;
}

void setName(std::string playerName)
{
    this->playerName = playerName;
    return;
}

std::string getName() 
{
    return this->playerName;
}

};

#endif
