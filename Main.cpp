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

        backgroundColor(1);
        clearScreen();
        gambler();
        getNumber(roundManager);
        std::cout << "\n\n\n Spieler " << player[roundManager].getName() << " ist jetzt am Zug!";
        getKey();
        backgroundColor(0);
        short zone = dangerZone();

        while (running)
        {
            clearScreen();
            line();
            std::cout << player[roundManager].getName();
            position(25, 3); std::cout << "Gold: " << player[roundManager].gold;
            position(60, 3); std::cout << "EXP: " << player[roundManager].realExp << "/" << player[roundManager].exp << std::endl;
            line();
            doubleDoor();
            position(60, 7);  std::cout << "Sie befinden sich vor der legendaeren Eingangstuer";
            position(60, 8);  std::cout << "zum Endlosen Dungeon.";
            position(60, 9);  std::cout << "Der Eingang wirkt sehr alt und verheissungsvoll.";
            position(60, 10); std::cout << "Sie bilden sich ein, Goblin und Orkfuerze riechen zu";
            position(60, 11); std::cout << "koennen. Daher wissen Sie, dass Sie hier richtig sind.";
            position(60, 14); std::cout << "-------------------------------------------------------------" << std::endl;
            position(60, 16); std::cout << "Gefahrenstufe: ";
            getKey();

            running = false;
            break;
        }
        player[roundManager].rooms++;
        break;
    }
    roundManager = 0;

    // Endlosspiel

bool playGame = true;

    while (playGame)
        {
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

