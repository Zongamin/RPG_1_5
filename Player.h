#include <string>
#include <iostream>


class Player
{
    private:
            
        std::string playerName = "Spielername";
    
    public:
        
        // Attribute
    
        long exp;
        long realExp;
        long health;
        long realHealth;
        long mana;
        long realMana;
        long strength;
        long intelligence;
        long dexterity;
        long luck;
        long endurance;
        int skillPoints;

        // Inventar

        long capacity;
        long gold;
        long scrapMetal;
        long aluminum;
        long copper;
        long manaPotion;
        long healthPotion;
        long weapons[500];
        long armor[500];
        

        // Buffs
        int fireAura;
        int regenerationOn;

        // Statistics
        long rooms;
        long monsters;
        long bosses;
        long crafted;

    long damage(long damage)
    {
        this->realHealth =- damage;
        
        if (this->realHealth < this->health)
        {
            std::cout << "Tod";
            return 0;
        }
        return 0;
    }

    long heal(long heal)
    {
        this->realHealth =+ heal;
        if (this->realHealth > this->health)
        {
            this->realHealth = this->health;

        }
    }
};
