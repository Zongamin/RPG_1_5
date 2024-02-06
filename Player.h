#include <string>
#include <iostream>

class Player
{
    private:

    public:
    std::string playerName = "Spielername";
    
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
    



    // Buffs
    int fireAura;
    int regenerationOn;


};