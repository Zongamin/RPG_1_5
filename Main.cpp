#include <string>
#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Enemy.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>

// Global Settings

short numberOfPlayers = 2;
short roundManager = 0;
    
Player player[4];

// Main Game
            
int main() 
{   
    clearScreen();
    textTitle();
    textRising();
    getKey();
    return 0;
}



