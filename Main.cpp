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

    // Globale Variablen

    short numberOfPlayers = 1;
    short roundManager = 0;
    bool roomCleared = false;

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
    
        bool running = true;

        for(; roundManager < numberOfPlayers; roundManager++)
        {
        backgroundColor(1);
        clearScreen();
        gambler();
        getNumber(roundManager);
        line();
        std::cout << "\n\n                   \033[32;40m Spieler: " << player[roundManager].getName() << " ist jetzt am Zug! " << "\033[102m \n";
        getKey();
        backgroundColor(0);
        short zone = dangerZone();

        if (zone > 1) 
        {
            player[roundManager].traps = trapCall(player, roundManager, zone);
        }

        while (running)
        {
            clearScreen();
            line();
            std::cout << "\033[36mSpieler: " << player[roundManager].getName();
            position(40, 3); std::cout << "\033[93mGold: " << player[roundManager].gold << "\033[0m";
            capacityColor(player, roundManager); position(80, 3); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
            line();
            doubleDoor();
            position(58, 8);  std::cout << "Sie stehen vor der gewaltigen Pforte zum sagenumwobenen";
            position(58, 9);  std::cout << "endlosen Dungeon. Die Tuer scheint so alt, dass selbst der";
            position(58, 10); std::cout << "Schimmel darauf in Rente gehen koennte. Doch da ist auch";
            position(58, 11); std::cout << "dieser Hauch von Abenteuer, der in der Luft liegt (oder";
            position(58, 12); std::cout << "vielleicht ist es einfach nur der Gestank von alten"; 
            position(58, 13); std::cout << "Goblinfuerzen, der seit Aeonen in den Tiefen dieses Dungeons";
            position(58, 14); std::cout << "rumhaengt). Sie wissen geanu: Der Weg vor Ihnen ist gespickt";
            position(58, 15); std::cout << "mit Reichtuemern, Gefahren und vielleicht sogar einer alten,";
            position(58, 16); std::cout << "vergessenen Socke eines Ogers. Also,schnappen Sie sich Ihren";
            position(58, 17); std::cout << "Mut und treten Sie ein in den endlosen Dungeon!";
            miniLine(58, 19);
            position(68, 21); dangerDisplay(zone);
            miniLine(58, 23);
            line();
            lifeDisplay(player, roundManager, 4, 28);
            line();
            roomCleared = roomsOptions(player, roundManager, zone, 0);
            if (roomCleared == true)
            {  
            running = false;
            break;
            }
            break;
        }
        player[roundManager].traps = 0;
        player[roundManager].rooms++;
        }
        roundManager = 0;

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

