#ifndef MENUES_H
#define MENUES_H

#include <iostream>


/*  Inhaltsverzeichnis
    16      - gameMenue         Das Gamemenü ist das Hauptmenue des Spiels und ist verantwortlich für Spieleranzahl,
                                Spielernamen, Spielstand laden, Spiel starten oder beenden.
    109     - characterMenue    Das Charactermenü ist sowohl eine einfache Anzeige der Charakterwerte, als auch (sofern
                                Skillpunkte vorhanden sind) ein Menü zur Verteilung von Skillpunkten.
    235     - roomOptions       Das Spielmenü des Spielers beinhaltet alle Optionen des Spiels. Sämtliche Ingamehand-
                                lungen des Spielers werden von hier aus zugewiesen.

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
            std::cout << "\033[41m[ 5 ]\033[0m ------> \033[31mSpiel beenden\n\033[0m";
            line();
            short input = choice();
            switch (input)
            {
                case 1:            
                    std::cout << "\n\nSpieleranzahl : " << numberOfPlayers << std::endl;
                    for (int index = 0; index < numberOfPlayers; index++)
                    {
                    std::cout << "\nSpielername Spieler "<< index + 1 << " : " << player[index].getName() << std::endl;            
                    }
                    std::cout << "\nSind Sie mit den Eingaben zufrieden (J/N) ?";
                    trueOrFalse = question();
                    if (trueOrFalse == true) 
                    {
                        running = false;
                        break;
                    } 
                    break;
        
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
                        error(0);
                        continue;
                    }

                case 3:
                    
                    for (int index = 0; index < numberOfPlayers; index++)
                    {
                        std::string playerName;

                        std::cout << "\nBitte geben Sie Ihren Spielernamen ein Spieler " << index + 1 << " : \n";
                        std::cin >> playerName;
                        player[index].setName(playerName);
                        std::cout << "\nDer Name von Spieler " << index + 1 << " wurde in " << player[index].getName() << " geaendert!" << std::endl;
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
                    error(0);
                    break;
            }
    }
    assignment(player, numberOfPlayers);
}

void characterMenue(Player player[], short roundManager)
{
    bool running = true;
    bool attitude = false;
    double strength = 0;
    double intelligence = 0;
    double dexterity = 0;
    double endurance = 0;

    while(running)
    {
        clearScreen();
        textCharacter();
        line();
        charCalc(player, roundManager);
        std::cout << "\033[93m" << player[roundManager].getName() << "s Werte\033[0m\n";
        line();
        std::cout << "\033[95mLevel\033[0m -----------> \033[95m" << player[roundManager].level << "\033[0m" << std::endl;
        std::cout << "\033[31mStaerke\033[0m ---------> \033[31m" << player[roundManager].strength << "\033[0m" << std::endl;
        std::cout << "\033[34mIntelligenz\033[0m -----> \033[34m" << player[roundManager].intelligence << "\033[0m" << std::endl;
        std::cout << "\033[33mAusdauer\033[0m --------> \033[33m" << player[roundManager].endurance << "\033[0m" << std::endl;
        std::cout << "\033[32mGeschick\033[0m --------> \033[32m" << player[roundManager].dexterity << "\033[0m" << std::endl;
        line();
        std::cout << "\033[91mLeben\033[0m -----------> \033[91m" << player[roundManager].health << "\033[0m" << std::endl;
        std::cout << "\033[94mMana\033[0m ------------> \033[94m" << player[roundManager].mana << "\033[0m" << std::endl;
        std::cout << "\033[92mGlueck\033[0m ----------> \033[92m" << player[roundManager].luck << "\033[0m" << std::endl;
        std::cout << "\033[37mTragekapazitaet\033[0m -> \033[37m" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "\033[35mSkillpunkte\033[0m -------> \033[35m" << player[roundManager].skillPoints << "\033[0m" << std::endl;
        line();
        
        attitude = condition(player, roundManager, strength, intelligence, dexterity, endurance);
        
        if (attitude == true) 
        { 
            position(35, 15); std::cout << " (" << strength << ") (Staerke beeinflusst die Angriffsstaerke und das Leben.) \033[0m";
            position(35, 16); std::cout << " (" << intelligence << ") (Intelligenz beeinflusst die Zauberintensitaet und das Mana.)\033[0m";
            position(35, 17); std::cout << " (" << endurance << ") (Ausdauer beeinflusst sowohl Leben, Mana als auch Glueck.)\033[0m";
            position(35, 18); std::cout << " (" << dexterity << ") (Geschick beeinflusst das Glueck.)\033[0m";
            position(35, 22); std::cout << " (Leben wird durch die Werte Staerke und Ausdauer beeinflusst.)\033[0m";
            position(35, 23); std::cout << " (Mana wird durch die Werte Intelligenz und Ausdauer beeinflusst.)\033[0m";
            position(35, 24); std::cout << " (Glueck beeinflusst die Kritische Trefferquote und die Beute.)\033[0m";
            position(35, 25); std::cout << " (Tragekapazitaet wird durch Staerke und Auddauer beeinflusst.)\033[0m";
            position(0, 33);    
            std::cout << " \033[30;102m* 1 *\033[0m ------> \033[31mStaerke (+)\033[0m                              \033[41;97m* 5 *\033[0m ------> \033[31mStaerke (-)\033[0m \n\n";
            std::cout << " \033[30;102m* 2 *\033[0m ------> \033[34mIntelligenz (+)\033[0m                          \033[41;97m* 6 *\033[0m ------> \033[34mIntelligenz (-)\033[0m \n\n";
            std::cout << " \033[30;102m* 3 *\033[0m ------> \033[33mAusdauer (+)\033[0m                             \033[41;97m* 7 *\033[0m ------> \033[33mAusdauer (-)\033[0m \n\n";
            std::cout << " \033[30;102m* 4 *\033[0m ------> \033[32mGeschick (+)\033[0m                             \033[41;97m* 8 *\033[0m ------> \033[32mGeschick (-)\033[0m \n\n";
            std::cout << " \033[30;47m* 9 *\033[0m ------> Fertig\n";

            short input = choice();
                       
            switch (input)
            {
                case 1:
                    if (player[roundManager].skillPoints > 0) {player[roundManager].strength++; player[roundManager].skillPoints--; strength++; break;}
                    error(1);
                    break;
    
                case 2:
                    if (player[roundManager].skillPoints > 0) {player[roundManager].intelligence++; player[roundManager].skillPoints--; intelligence++; break;}
                    error(1);
                    break;

                case 3:
                    if (player[roundManager].skillPoints > 0) {player[roundManager].endurance++; player[roundManager].skillPoints--; endurance++; break;}
                    error(1);
                    break;
    
                case 4:
                    if (player[roundManager].skillPoints > 0) {player[roundManager].dexterity++; player[roundManager].skillPoints--; dexterity++; break;}
                    error(1);
                    break;

                case 5:
                    if (strength > 0) {strength--; player[roundManager].skillPoints++; player[roundManager].strength--; break;}
                    error(2);
                    break;

                case 6:
                    if (intelligence > 0) {intelligence--; player[roundManager].skillPoints++; player[roundManager].intelligence--; break;}
                    error(2);
                    break;

                case 7:
                    if (endurance > 0) {endurance--; player[roundManager].skillPoints++; player[roundManager].endurance--; break;}
                    error(2);
                    break;

                case 8:
                    if (dexterity > 0) {dexterity--; player[roundManager].skillPoints++; player[roundManager].dexterity--; break;}
                    error(2);
                    break;
    
                case 9:
                    bool choice;
                    if (player[roundManager].skillPoints > 0)
                    {
                        std::cout << "\n\n\033[31mEs sind noch Skillpunkte vorhanden, sind Sie sicher, dass Sie fortfahren moechten? (J/N)\033[0m" << std::endl;
                        choice = question();
                        if (choice == false){break;}
                    }
                    std::cout << "\n\nSind Sie mit Ihren Aenderungen zufrieden? (J/N)" << std::endl;
                    choice  = question();
                    if (choice == true)
                    {
                        player[roundManager].realHealth += (strength * 15) + (endurance * 5);
                        if(player[roundManager].realHealth > player[roundManager].health)
                        {
                            player[roundManager].realHealth = player[roundManager].health;
                        }
                        player[roundManager].realMana += (intelligence * 3) + (endurance * 2);
                        if(player[roundManager].realMana > player[roundManager].mana)
                        {
                            player[roundManager].realMana = player[roundManager].mana;
                        } 
                        running = false; 
                        break;
                    }
                    break;

                default:
                    std::cout << "\033[31mDas ist leider nicht moeglich!\033[0m";
                    getKey();       
                    break;
            }
        }
        else
        {
        getKey();
        running = false;
        break;
        }   
    }
    return;
}

// Ingame Hauptmenü

void roomsOptions()
{
    position(27, 0);
    return;
}

#endif