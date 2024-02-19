#ifndef MAIN_CPP
#define MAIN_CPP

#include <string>
#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Enemy.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Menues.h>

// Main Game
            
int main() 
{   
    // Initialisierung
    
    Player player[4];
    player[0].setName("Max Mustermann");
    player[1].setName("Maxine Mustermann");
    player[2].setName("Hans Wurst");
    player[3].setName("Lasmiranda Densivilla");

    short numberOfPlayers = 1;
    short roundManager = 0;

    // Title

    clearScreen();
    textTitle();
    textRising();
    getKey();
    
    // Gamemenue mit Spielerinitialisierung

    gameMenue(player, numberOfPlayers);
    
    // Erste Werteverteilung der Spieler

    for (; roundManager < numberOfPlayers; roundManager++)
    {
    characterMenue(player, roundManager); 
    }
    roundManager = 0;

    // Eingangsraum
    
    for (; roundManager < numberOfPlayers; roundManager++)
    {
        bool running = true;

        while (running)
        {
            
        }
        player[roundManager].rooms++;
    }
    roundManager = 0;

    // Endlosspiel
    
    return 0;
}

#endif

