#ifndef MAIN_CPP
#define MAIN_CPP

#include <string>
#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Enemy.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Menues.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Pictures.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Texts.h>


// Main Game
            
int main() 
{   
    // Globale Variablen

    short numberOfPlayers = 1;
    short roundManager = 0;
    bool roomCleared = false;

    // Initialisierung Player
    
    Player player[4];
    player[0].setName("Max Mustermann");
    player[1].setName("Maxine Mustermann");
    player[2].setName("Hans Wurst");
    player[3].setName("Lasmiranda Densivilla");

    // Initialisierung Enemy

    Enemy enemy[6];
    enemy[0].setName("Imp");
    enemy[1].setName("Goblin");
    enemy[2].setName("Ork");
    enemy[3].setName("Oger");
    enemy[4].setName("Killer Karnickel");
    enemy[5].setName("Drache");
    
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
    break; 
    }
    roundManager = 0;

    // Eingangsraum
      
    for(; roundManager < numberOfPlayers; roundManager++)
    {
        bool running = true;
        short zone = dangerZone();

        backgroundColor(1);
        clearScreen();
        textPlayer();
        getNumber(roundManager);
        line();
        std::cout << "\n\n                             \033[32;40m *** Spieler " << player[roundManager].getName() << " ist jetzt am Zug! *** " << "\033[102m \n";
        getKey();
        backgroundColor(0);
        
        if (zone > 1) 
            {
                trapCall(player, roundManager, zone);
            }

        while (running)
        {
            roomOptions(player, roundManager, zone, 0);
            running = false;
            break;
        }
        
    }
        

    // Endlosspiel

bool playGame = true;

    while (playGame)
        {
            if(roundManager > numberOfPlayers)
            {
                roundManager = 0;
                break;
            }
            bool running = true;
                
                while (running)
                    {
                        
                        running = false;
                        break;
                    }
        }
    
    return 0;
}

#endif

