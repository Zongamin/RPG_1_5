#include <string>
#include <iostream>


class Player
{
    private:
            
        std::string playerName = "Spielername";
    
    public:
        
        // Attribute
    
        double exp;
        double realExp;
        double health = 100;
        double realHealth;
        double mana;
        double realMana;
        double strength;
        double intelligence;
        double dexterity;
        double luck;
        double endurance;
        int skillPoints;

        // Inventar

        double capacity;
        double gold;
        double scrapMetal;
        double aluminum;
        double copper;
        double manaPotion;
        double healthPotion;
        double weapons[500];
        double armor[500];
        

        // Buffs
        int fireAura;
        int regenerationOn;

        // Statistics
        double rooms;
        double monsters;
        double bosses;
        double crafted;

    double damage(double damage)
    {
        this->realHealth =- damage;
        
        if (this->realHealth < this->health)
        {
            std::cout << "Tod";
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
