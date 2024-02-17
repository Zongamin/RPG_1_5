#ifndef MENUES_H
#define MENUES_H

#include <iostream>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>

/*  Inhaltsverzeichnis
        - gameMenue         Das Gamemenue ist das Hauptmenue des Spiels und ist verantwortlich für Spieleranzahl,
                            Spielernamen, Spielstand laden, Spiel starten oder beenden
        -
*/

int gameMenue(Player player[], short& numberOfPlayers)
{
        bool running = true;
        int trueOrFalse;

        while(running)
        { 
            clearScreen();
            textMainMenue();
            line();
            std::cout << "\033[42m[ 1 ]\033[0m ------> \033[32mSpiel starten\n\n\033[0m";
            std::cout << "\033[107;30m[ 2 ]\033[0m ------> Spieleranzahl\n\n";
            std::cout << "\033[107;30m[ 3 ]\033[0m ------> Spielernamen\n\n";
            std::cout << "\033[107;30m[ 4 ]\033[0m ------> Spielstand laden\n\n";
            std::cout << "\033[41m[ 5 ]\033[0m ------> \033[31mSpiel beenden\n\n\033[0m";
            line();
            short input = choice();
            switch (input)
            {
                case 1:            
                    std::cout << "\n\nSpieleranzahl : " << numberOfPlayers << std::endl;
                    for (int index = 1; index < numberOfPlayers + 1; index++)
                    {
                    std::cout << "\nSpielername Spieler "<< index << " : " << player[index].getName() << std::endl;            
                    }
                    std::cout << "\nSind Sie mit den Eingaben zufrieden (J/N) ?";
                    trueOrFalse = question();
                    if (trueOrFalse == true) 
                    {
                        running = false; break;
                    } 
                    continue;
        
                case 2:
                    std::cout << "\n\nBitte geben Sie die Anzahl der Spieler ein (1 - 4) :\n";
                    numberOfPlayers = choice();
                    if (numberOfPlayers > 0 && numberOfPlayers < 5) 
                    {
                        std::cout << "\n\nDie Spieleranzahl wurde auf " << numberOfPlayers << " geaendert." << std::endl;
                        getKey();
                        break;
                    }
                    else
                    {
                        error();
                        continue;
                    }

                case 3:
                    
                    for (int index = 1; index < numberOfPlayers + 1; index++)
                    {
                        std::string playerName;

                        std::cout << "\nBitte geben Sie Ihren Spielernamen ein Spieler " << index << " : \n";
                        std::cin >> playerName;
                        player[index].setName(playerName);
                        std::cout << "\nDer Name von Spieler " << index << " wurde in " << player[index].getName() << " geaendert!" << std::endl;
                    }
                    getKey();
                    break;

                case 4:
            
                    loadGame();
                    break;
        
                case 5:
            
                    std::cout << "\n\nSind Sie sicher, dass Sie das Spiel beenden moechten (J/N)?\n";
                    trueOrFalse = question();

                    if (trueOrFalse == true) 
                    {
                        clearScreen();
                        textEnd();
                        getKey();
                        return 0;
                    }
                    else
                    {
                        break;
                    }

                default:
                    error();
                    break;
            }
        }
}


#endif