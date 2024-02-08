#include <string>
#include <iostream>
#include "C:\\Users\\DokBa\\Desktop\\Work\\Game\\RPG_1_5\\Headlines.h"
#include "C:\\Users\\DokBa\\Desktop\\Work\\Game\\RPG_1_5\\System.h"
#include "C:\\Users\\DokBa\\Desktop\\Work\\Game\\RPG_1_5\\Enemy.h"
#include "C:\\Users\\DokBa\\Desktop\\Work\\Game\\RPG_1_5\\Player.h"

int main() 
{
    int player[4];
    Player newPlayer[0];
    newPlayer[0].health = 100;
    newPlayer[0].setName("Doktor");
    std::cout << newPlayer[0].health;
    std::cout << newPlayer[0].getName();
    return 0;
}