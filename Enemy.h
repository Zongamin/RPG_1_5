#include <iostream>

class Enemy
{
    private:
        std::string enemyName = "Enemyname";

    public:
        
        // Attribute
        
        double health;
        double realHealth;
        double mana;
        double realMana;
        double strength;
        double intelligence;
        double dexterity;
        double luck;
        double endurance;

        // Inventar

        double gold;
        double scrapMetal;
        double aluminum;
        double copper;
        double manaPotion;
        double healthPotion;
        double weapons;
        double armor;

        // Buffs

        double fireAura;
        double regenerationOn;

    double damage(double damage)
    {
        this->realHealth =- damage;

        if (this->realHealth < this->health)
        {
            std::cout << "Monsterkill!";
            return 0;
        }
        return 0;
    }

    double heal(double heal)
    {
        this->realHealth =+ heal;
        if (this->realHealth > this->health)
        {
            this->realHealth = this->health;
        }
    }

    void setName(std::string enemyName)
    {
        this->enemyName = enemyName;
        return; 

    }
};