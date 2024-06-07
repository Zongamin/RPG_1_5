#ifndef ITEMS_H
#define ITEMS_H

#include <string>

class Item
{
    protected:
        std::string itemName;
        int weight;
    
    public:
        Item(const std::string& name, int weight) 
            : itemName(name), weight(weight) {}

        std::string getName() const {
            return itemName;
        }

        int getWeight() const {
            return weight;
        }
};

class HealthPotion : public Item
{
    public:
        HealthPotion() : Item("Heiltrank", 0.25) {}
};

class ManaPotion : public Item
{
    public:
        ManaPotion() : Item("Manatrank", 0.30) {}
};

class RegenPotion: public Item
{
    public:
        RegenPotion() : Item("Regenerationstrank", 0.35) {}
};

class ScrapMetal: public Item
{
    public:
        ScrapMetal() : Item("Altmetall", 0.5) {}
};

class Copper: public Item 
{
    public:
        Copper() : Item("Kupfer", 0.4) {}
};

class Aluminum: public Item
{
    public:
        Aluminum() : Item("Aluminium", 0.2) {}

};

class Herbs: public Item
{
    public:
        Herbs() : Item("Kraeuter", 0.01) {}
};

class Weapon: public Item
{
    public:
        Weapon() : Item("Schwert", 2.5) {}
};

#endif