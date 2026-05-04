#ifndef MAIN_CPP
#define MAIN_CPP

#include <windows.h>
#include <string>
#include <iostream>
#include <mmsystem.h>
#include "Player.h"
#include "Enemy.h"
#include "System.h"
#include "Menues.h"
#include "Headlines.h"
#include "Pictures.h"
#include "Texts.h"
#include "Log.h"

#pragma comment(lib, "winmm.lib")

// Main Game
            
int main() 
{   
    SetConsoleOutputCP(65001);
    
    // Globale Variablen

    const int roomNumbers = 21;
    short numberOfPlayers = 1;
    short roundManager = 0;
    short zone = 0;
    
    // Initialisierung Player
    
    Player player[4];
    player[0].setName("Max Mustermann");
    player[1].setName("Maxine Mustermann");
    player[2].setName("Hans Wurst");
    player[3].setName("Helga Wurst");
    
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
    PlaySound(TEXT("sounds\\Title.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    getKey();
    PlaySound(NULL,0,0);
        
    // Gamemenue mit Spielerinitialisierung

    bool loaded = gameMenue(player, roundManager, numberOfPlayers, zone);
    
    // Erste Werteverteilung der Spieler
    if (!loaded)
    {
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
            short zone = 1;

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
    }
    
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

