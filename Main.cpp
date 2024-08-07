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
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Log.h>

// Main Game
            
int main() 
{   
    // Globale Variablen

    const int roomNumbers = 21;
    short numberOfPlayers = 1;
    short roundManager = 0;
    
    // Initialisierung Player
    
    Player player[4];
    player[0].setName("Max Mustermann");
    player[1].setName("Maxine Mustermann");
    player[2].setName("Hans Wurst");
    player[3].setName("Lasmiranda Densivillia");

    // Initialisierung Waffen- und Ruestungs - Arrays der Spieler

    for (int dex = 0; dex == 3; dex++)
    {
        for (int index = 0; index < 500; index++)
        {
            player[dex].weapons[index] = 0;
            player[dex].armor[index] = 0;
        }
    }
    
    // Initialisierung Enemy

    Enemy enemy[5];
    enemy[0].setName("Zero 01");
    enemy[1].setName("Zero 02");
    enemy[2].setName("Zero 03");
    enemy[3].setName("Zero 04");
    enemy[4].setName("Zero 05");
        
    // Initialisierung von PermaDeath für Enemy

    for (short index = 0; index < 5; index++)
    {
        enemy[index].permaDeath = true;
    }

    // Initialisieren des LogText - Arrays

    Log log;
    log.eraseLog();
    
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
      
    for (; roundManager < numberOfPlayers; roundManager++)
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
            roomOptions(player, enemy, log, roundManager, zone, numberOfPlayers);
            running = false;
            player[roundManager].roomCleared = false;
            player[roundManager].realActionPoints = player[roundManager].actionPoints;
            player[roundManager].traps = 0;
            break;
        }
        break;
    }
    roundManager = 0;    
    player[roundManager].currentRoom = random(1, roomNumbers);

    // Endlosspiel

bool playGame = true;

    while (playGame)
    {
        if (player[roundManager].permaDeath == true)
        {
            std::cout << "Spieler: " << player[roundManager].getName() << " ist leider gerade Tod!" << std::endl;
            getKey();
            roundManager++;
            continue;
        }
        
        if (numberOfPlayers > 1 && player[roundManager].realActionPoints == 0)
        {
            player[roundManager].realActionPoints = player[roundManager].actionPoints;
            roundManager++;
            continue;
        }

        if (player[roundManager].roomCleared == true) 
        {
            player[roundManager].traps = 0;
            player[roundManager].rooms++;
            player[roundManager].roomCleared = false;
            player[roundManager].specialRoom = false;
            player[roundManager].currentRoom = random(1, roomNumbers);
            roundManager++;
            continue;
        }

        if(roundManager >= numberOfPlayers)
        {
            roundManager = 0;
            continue;
        }
                    
        short zone = dangerZone();

        backgroundColor(1);
        clearScreen();
        textPlayer();
        getNumber(roundManager);
        line();
        std::cout << "\n\n                             \033[32;40m *** Spieler " << player[roundManager].getName() << " ist jetzt am Zug! *** " << "\033[102m \n";
        getKey();
        backgroundColor(0);
        
        if (zone >= 2) 
        {
            trapCall(player, roundManager, zone);
        }
        bool running = true;
            
        while (running)
            {
                roomOptions(player, enemy, log, roundManager, zone, numberOfPlayers);
                running = false;
                break;
            }
    }
    return 0;
}

#endif

