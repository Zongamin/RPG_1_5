#ifndef FIGHTING_H
#define FIGHTING_H

#include <string>
#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Enemy.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Texts.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Pictures.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>

void initializeEnemy(Enemy enemy[],Player player[], short roundManager, short dangerZone, std::string kindOf, short enemyNumber)
{
    double factor = 0;
    short variation = 0;
    short chance = 0;

    enemy[enemyNumber].permaDeath = false; 

    if (kindOf == "Imp") { factor = 1; enemy[enemyNumber].picture = 0; enemy[enemyNumber].setName("Imp " + std::to_string(enemyNumber)); }
    if (kindOf == "Goblin") { factor = 1.5; enemy[enemyNumber].picture = 1; enemy[enemyNumber].setName("Goblin " + std::to_string(enemyNumber)); }
    if (kindOf == "Ork") { factor = 2; enemy[enemyNumber].picture = 2; enemy[enemyNumber].setName("Ork " + std::to_string(enemyNumber)); }
    if (kindOf == "Oger") { factor = 3; enemy[enemyNumber].picture = 3; enemy[enemyNumber].setName("Oger " + std::to_string(enemyNumber)); }
    if (kindOf == "Killer-Karnickel") { factor = 4; enemy[enemyNumber].picture = 4; enemy[enemyNumber].setName("Killer-Karnickel " + std::to_string(enemyNumber)); }
    if (kindOf == "Drache") { factor = 5; enemy[enemyNumber].picture = 5; enemy[enemyNumber].setName("Drache " + std::to_string(enemyNumber)); }
    if (kindOf == "Mimik") { factor = 3.5; enemy[enemyNumber].picture = 6; enemy[enemyNumber].setName("Mimik " + std::to_string(enemyNumber)); }
    if (kindOf == "Groghar") { factor = 4; enemy[enemyNumber].picture = 7; enemy[enemyNumber].setName("Groghar " + std::to_string(enemyNumber)); }
    if (dangerZone == 0) { variation = 0; };
    if (dangerZone == 1) { variation = random(0, 2); }
    if (dangerZone == 2) { variation = random(1, 5); }
    enemy[enemyNumber].level = (player[roundManager].level + variation);
    enemy[enemyNumber].health = round(((player[roundManager].health / 2) * factor) + variation);
    enemy[enemyNumber].realHealth = enemy[enemyNumber].health;
    enemy[enemyNumber].mana = round(((player[roundManager].mana / 2) * factor) + variation);
    enemy[enemyNumber].realMana = enemy[enemyNumber].mana;
    enemy[enemyNumber].strength = round(((player[roundManager].strength / 4) * factor) + variation);
    enemy[enemyNumber].intelligence = round(((player[roundManager].intelligence / 4) * factor) + variation);
    enemy[enemyNumber].dexterity = round(((player[roundManager].dexterity / 2) * factor) + variation);
    enemy[enemyNumber].luck = (player[roundManager].luck / 2) * factor;
    if (enemy[enemyNumber].luck < 1) { enemy[enemyNumber].luck = 1; }
    enemy[enemyNumber].endurance = round(((player[roundManager].endurance / 2) * factor) + variation);

    // Inventar

    enemy[enemyNumber].gold = (player[roundManager].level * 2) + variation;
    enemy[enemyNumber].exp = {};
    chance = random(1, 100);
    if (chance >= 1 && chance <= 50) { enemy[enemyNumber].scrapMetal = round(random(1, 1 + (player[roundManager].level - 1) * 1)); }
    chance = random(1, 100);
    if (chance >=50 && chance <= 100) { enemy[enemyNumber].aluminum = round(random(1, 1 + (player[roundManager].level - 1) * 1)); }
    chance = random(1, 100);
    if (chance >= 1 && chance <= 50) { enemy[enemyNumber].copper = round(random(1, 1 + (player[roundManager].level - 1) * 1)); }
    chance = random(1, 100);
    if (chance >= 50 && chance <= 100) { enemy[enemyNumber].manaPotion = random(1, (3 + variation)); }
    chance = random(1, 100);
    if (chance >= 1 && chance <=50) { enemy[enemyNumber].healthPotion = random(1,(3 + variation)); }
    chance = random(1, 100);
    if (chance >= 35 && chance <= 65) {enemy[enemyNumber].weapons = (player[roundManager].level + variation); }
    chance = random(1, 100);
    if (chance >= 35 && chance <= 65) { enemy[enemyNumber].armor = (player[roundManager].level + variation); }
    
    // Buffs

    enemy[enemyNumber].frozen = 0;
    enemy[enemyNumber].fireAura = 0;
    enemy[enemyNumber].poisoned = 0;
    enemy[enemyNumber].regenerationOn = 0;
            
    return;
}

#endif