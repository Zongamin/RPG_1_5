#ifndef MENUES_H
#define MENUES_H

#include <iostream>
#include <algorithm>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Main.cpp>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Pictures.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Texts.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\System.h>

/*  Inhaltsverzeichnis
            - isRoomValid       Validierung von Speziellen Räumen für Sonderaktionen
            - gameMenue         Das Gamemenü ist das Hauptmenue des Spiels und ist verantwortlich für Spieleranzahl,
                                Spielernamen, Spielstand laden, Spiel starten oder beenden.
            - characterMenue    Das Charactermenü ist sowohl eine einfache Anzeige der Charakterwerte, als auch (sofern
                                Skillpunkte vorhanden sind) ein Menü zur Verteilung von Skillpunkten.
            - potions           Menü zur Einnahme des Spieler von diversen Tränken.
            - materials         Menü zur Anzeige aller mitgeführten Crafting Metalle und deren Gewicht.
            - armors            Menü zur Ansicht und dem Anlegen von Rüstungen.
            - weapons           Menü zur Ansicht und dem Anlegen von Waffen.
            - inventory         Menü zum Inventar des Spielers zur Weiterleitung zu Untermenüs wie poition, metals, armors
                                weapons und disposal
            - frameWork         Unterfunktion zum Aufbau des Bildes (erstellt mit übergabe der Raumdaten und der Gefahren-
                                zone den Aufbau des korrekten Bildes, der Gefahrenanzeige und des Spezial Buttons.)
            - magicMenue        Menü für die magischen Fertigkeiten des Spielers
            - menue             Ingame "Pause" - Menü zum Laden, Speichern und Beenden 
            - roomOptions       Das Spielmenü des Spielers beinhaltet alle Optionen des Spiels. Sämtliche Ingamehand-
                                lungen des Spielers werden von hier aus zugewiesen.
*/

// Spezielle Räume: 5, 6, 9, 10, 11, 12, 13, 14, 15, 19, 20

bool isRoomValid(int room) 
{
    if (room == 5 || room == 6 || room == 9 || room == 10 || room == 11 || room == 12 || room == 13 || room == 14 || room == 15 || room == 19 || room == 20 || room == 21)
    {
        return true;
    }
    return false;
}

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
                        bool running = true;

                        while(running)
                        {
                            std::string playerName;
                            std::cout << "\nBitte geben Sie Ihren Spielernamen ein Spieler " << index + 1 << " (max. 25 Zeichen): \n";
                            std::getline(std::cin, playerName);
                            if(playerName.length() <= 25)
                            {
                                player[index].setName(playerName);
                                std::cout << "\nDer Name von Spieler " << index + 1 << " wurde in " << player[index].getName() << " geaendert!" << std::endl;
                                running = false;
                            } 
                            else
                            {
                                std::cout << "\nDer Name ist zu lang!" << std::endl;
                            }
                        }
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
                        exit(0);
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
        std::cout << "\033[36mTragekapazitaet\033[0m -> \033[36m" << player[roundManager].capacity << "\033[0m" << std::endl;
        std::cout << "\033[0mWaffenschaden\033[0m ---> \033[0m" << player[roundManager].weaponDmg << "\033[0m" << std::endl;
        std::cout << "\033[90mRuestungswert\033[0m ---> \033[90m" << player[roundManager].armorDmgReduce << "\033[0m" << std::endl;
        line();
        std::cout << "\033[35mSkillpunkte\033[0m -------> \033[35m" << player[roundManager].skillPoints << "\033[0m" << std::endl;
        line();
        
        attitude = condition(player, roundManager, strength, intelligence, dexterity, endurance);
        
        if (attitude == true) 
        { 
            position(35, 15); std::cout << " (" << strength << ") (Staerke beeinflusst die Angriffsstaerke, die Tragekapazitaet und das Leben.) \033[0m";
            position(35, 16); std::cout << " (" << intelligence << ") (Intelligenz beeinflusst die Zauberintensitaet, verfuegbare Zauber und das Mana.)\033[0m";
            position(35, 17); std::cout << " (" << endurance << ") (Ausdauer beeinflusst sowohl das Leben, das Mana als auch das Glueck.)\033[0m";
            position(35, 18); std::cout << " (" << dexterity << ") (Geschick beeinflusst das Glueck, die Qualitaet gefundener Beute und die Kritischen Treffer.)\033[0m";
            position(35, 22); std::cout << " (Leben wird durch die Werte Staerke und Ausdauer beeinflusst.)\033[0m";
            position(35, 23); std::cout << " (Mana wird durch die Werte Intelligenz und Ausdauer beeinflusst.)\033[0m";
            position(35, 24); std::cout << " (Glueck beeinflusst die Kritische Trefferquote und die Beute und kann durch Geschick erhoeht werden.)\033[0m";
            position(35, 25); std::cout << " (Tragekapazitaet wird durch die Staerke und die Ausdauer beeinflusst.)\033[0m";
            position(35, 26); std::cout << " (Der Waffenschaden wird durch Anlegen von Waffen beeinflusst und steigert den ausgeteilten Schaden.)\033[0m";
            position(35, 27); std::cout << " (Der Ruestwert wird durch das Tragen von Ruestungen beeinflusst und reduziert erlittenen Schaden.)\033[0m";
            position(0, 35);    
            std::cout << " \033[30;102m[ 1 ]\033[0m ------> \033[31mStaerke     (+)\033[0m                          \033[41;97m[ 5 ]\033[0m ------> \033[31mStaerke     (-)\033[0m \n\n";
            std::cout << " \033[30;102m[ 2 ]\033[0m ------> \033[34mIntelligenz (+)\033[0m                          \033[41;97m[ 6 ]\033[0m ------> \033[34mIntelligenz (-)\033[0m \n\n";
            std::cout << " \033[30;102m[ 3 ]\033[0m ------> \033[33mAusdauer    (+)\033[0m                          \033[41;97m[ 7 ]\033[0m ------> \033[33mAusdauer    (-)\033[0m \n\n";
            std::cout << " \033[30;102m[ 4 ]\033[0m ------> \033[32mGeschick    (+)\033[0m                          \033[41;97m[ 8 ]\033[0m ------> \033[32mGeschick    (-)\033[0m \n\n";
            std::cout << " \033[30;47m[ 9 ]\033[0m ------> Fertig\n";

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
                    std::cout << "\n\033[31mDas ist leider nicht moeglich!\033[0m";
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

void potions(Player player[], short roundManager)
{
    bool running = true;
    bool need = false;
    bool have = false;
        
    while(running)
    {
        clearScreen();
        textPotion();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 10); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 10); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "\033[31mHeiltraenke\033[0m ------------> \033[31m" << player[roundManager].healthPotion << "\033[0m"; 
        miniLine(0, 15);
        std::cout << "\033[34mManatraenke\033[0m ------------> \033[34m" << player[roundManager].manaPotion << "\033[0m";
        miniLine(0, 17);
        std::cout << "\033[35mRegenerationstraenke\033[0m ---> \033[35m" << player[roundManager].regenPotion << "\033[0m" << std::endl; 
        line();
        position(10, 22); std::cout << "\033[41;97m[ 1 ]\033[0m ------> \033[31mHeiltrank benutzen\033[0m             \033[45;97m[ 3 ]\033[0m ------> \033[35mRegenerationstrank benutzen\033[0m" << std::endl;
        position(10, 24); std::cout << "\033[44;97m[ 2 ]\033[0m ------> \033[34mManatrank benutzen\033[0m             \033[47;30m[ 4 ]\033[0m ------> Zurueck" << std::endl;
                
        short input = choice();

        switch(input)
        {
            case 1:
                have = potionCheck(player, roundManager, 0);
                need = checkRegen(player, roundManager, 0);
                if (need == false | have == false)
                {
                    break;
                }
                potionDrink(player, roundManager, 0);
                break; 

            case 2:
                have = potionCheck(player, roundManager, 1);
                need = checkRegen(player, roundManager, 1);
                if (need == false | have == false)
                {
                    break;
                }
                potionDrink(player, roundManager, 1);
                break; 
                
            case 3:
                have = potionCheck(player, roundManager, 2);
                need = checkRegen(player, roundManager, 2);
                if (need == false | have == false)
                {
                    break;
                }
                potionDrink(player, roundManager, 2);
                break; 

            case 4:
                running = false;
                break;
        }        
    }
    return;
}

void materials(Player player[], short roundManager)
{
    bool running = true;

    while (running)
    {
        clearScreen();
        textMetal();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 10); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 10); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "\033[90mAltmetall\033[0m ------> " << player[roundManager].scrapMetal; position(40,14); std::cout << " (" << player[roundManager].scrapMetal * 0.3 << " kg)";
        miniLine(0, 15);
        std::cout << "\033[0mAluminium\033[0m ------> " << player[roundManager].aluminum; position(40,16); std::cout << " (" << player[roundManager].aluminum * 0.1 << " kg)\033[0m";
        miniLine(0, 17);
        std::cout << "\033[31mKupfer\033[0m ---------> " << player[roundManager].copper; position(40,18); std::cout << " (" << player[roundManager].copper * 0.2 << " kg)" << std::endl;
        miniLine(0, 19);
        std::cout << "\033[92mKraeuter\033[0m -------> " << player[roundManager].herbs; position(40,20); std::cout << " (" << player[roundManager].herbs * 0.1 << " kg)" << std::endl;
        miniLine(0, 21);
        std::cout << "\033[0mGesamtgewicht --> "; position(40,22); std::cout << " (" << (player[roundManager].scrapMetal * 0.3) + (player[roundManager].aluminum * 0.1) + (player[roundManager].copper * 0.2) + (player[roundManager].herbs * 0.1) << " kg)" << std::endl;
        line();
        if (player[roundManager].currentRoom == 10) // Schmiede als currentRoom einfügen!!!!!! <-------
        { 
            std::cout << "\n\nSie befinden sich derzeit an einer Schmiede, diese kann ueber die Spezial-Option in den Raumoptionen betreten werden.";
                      
        }
        getKey();
        running = false;  
        break;

    }
    return;
}

void armors(Player player[], short roundManager)
{
    bool running = true;
    int input = 0;
    int arraySize = 0;
    double armorDmgNow = 0;

    while (running)
    {
        arraySize = 0;

        for (int index = 0; index < 500; index++) 
        {
            if(player[roundManager].armor[index] == 0) 
            {
                break;
            }
            arraySize++;
        }

        clearScreen();
        textArmor();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 12); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 12); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "\033[90mIhre derzeitige Ruestung: ";
        if (player[roundManager].armorDmgReduce == 0) {std::cout << "Sie haben momentan keine Ruestung angelegt.\033[0m" << std::endl;} else {std::cout << player[roundManager].armorDmgReduce << " RST.\033[0m" << std::endl;}
        line();
        if (player[roundManager].armor[0] == 0)
        {
            std::cout << "\n\033[31mSie haben keine Ruestungen im Inventar!\033[0m" << std::endl;
            getKey();
            running = false;
            break;
        }
        std::cout << "\n\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
        for (int index = 0; index < 500; index++)
        {
            if (player[roundManager].armor[index] == 0)
            {
                break;
            }
            std::cout << "\n\033[100;30m[ " << index +1 <<" ]\033[0m ------> \033[90m" << player[roundManager].armor[index] << " RST\033[0m" << std::endl;
        }
        line();
        std::cout << "\nWelche Ruestung moechten Sie anlegen (0 - " << arraySize << ") ?"; std::cin >> input;
        if (input == 0) {running = false; break;}
        if (input > arraySize) {std::cout << "\n\033[31mDas geht nicht!\033[0m"; getKey(); break;}
        if (player[roundManager].armorDmgReduce > 0) {armorDmgNow = player[roundManager].armorDmgReduce;}
        player[roundManager].armorDmgReduce = player[roundManager].armor[input - 1];
        player[roundManager].armor[(input - 1)] = 0;
        if (armorDmgNow > 0) {player[roundManager].armor[(input - 1)] = armorDmgNow; armorDmgNow = 0;}
        arraySort(player, roundManager, "armor");
        std::cout << "\n\033[32mDie Ruestung wurde angelegt!\033[0m" << std::endl;
        std::cout << "\nMoechten Sie weiter im Ruestungsinventar stoebern ? (J/N)" << std::endl;
        bool answer = question();
        switch (answer)
        {
            case true:
                break;
            
            case false:
                running = false;
                break;
        }

    }
    return;
}

void weapons(Player player[], short roundManager)
{
    bool running = true;
    int input = 0;
    int arraySize = 0;
    double weaponDmgNow = 0;
       
    while (running)
    {
        arraySize = 0;

        for (int index = 0; index < 500; index++) 
        {
            if(player[roundManager].weapons[index] == 0) 
            {
                break;
            }
            arraySize++;
        }

        clearScreen();
        textWeapons();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 10); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 10); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "\033[90mDerzeitiger Waffenschaden: ";
        if (player[roundManager].weaponDmg == 0) {std::cout << "Sie haben momentan keine Waffe angelegt!\033[0m" << std::endl;} else {std::cout << player[roundManager].weaponDmg << " DMG\033[0m" << std::endl;}
        line();
        if (player[roundManager].weapons[0] == 0)
        {
            std::cout << "\n\033[31mSie haben keine Waffen im Inventar!\033[0m" << std::endl;
            getKey();
            running = false;
            break;
        }
        std::cout << "\n\033[47;30m[ 0 ]\033[0m ------> Zurueck" << std::endl;
        for (int index = 0; index < 500; index++)
        {
            if(player[roundManager].weapons[index] == 0)
            {
                break;
            }
            std::cout << "\n\033[100;30m[ " << index + 1 <<" ]\033[0m ------> \033[90m" << player[roundManager].weapons[index] << " DMG\033[0m" << std::endl;
        }
        line();
        std::cout << "\nWelche Waffe moechten Sie anlegen (0 - " << arraySize << ") ?"; std::cin >> input;
        if (input == 0) {running = false; break;}
        if (input > arraySize) {std::cout << "\n\033[31mDas geht nicht!\033[0m"; getKey(); break;}
        if (player[roundManager].weaponDmg > 0) {weaponDmgNow = player[roundManager].weaponDmg;}
        player[roundManager].weaponDmg = player[roundManager].weapons[input - 1];
        player[roundManager].weapons[(input - 1)] = 0;
        if (weaponDmgNow > 0) {player[roundManager].weapons[(input - 1)] = weaponDmgNow; weaponDmgNow = 0;}
        arraySort(player, roundManager, "weapon");
        std::cout << "\n\033[32mDie Waffe wurde angelegt!\033[0m" << std::endl;
        std::cout << "\nMoechten Sie weiter im Waffeninventar stoebern ? (J/N)" << std::endl;
        bool answer = question();
        switch (answer)
        {
            case true:
                break;
            
            case false:
                running = false;
                break;
        }

    }
    return;
}

void inventory(Player player[], short roundManager)
{
    int weapon = 0;
    int armor = 0;
    bool running = true;
        
    while(running)
    {
        weapon = 0;
        for (int index = 0; index < 500; index++) 
        {
            if(player[roundManager].weapons[index] == 0) 
            {
                break;
            }
            weapon++;
        }
        
        armor = 0;
        for (int index = 0; index < 500; index++) 
        {
            if(player[roundManager].armor[index] == 0) 
            {
                break;
            }
            armor++;
        }

        if (player[roundManager].weaponDmg > 0) {weapon += 1;}
        if (player[roundManager].armorDmgReduce > 0) {armor += 1;}

        clearScreen();
        textInventory();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName();
        position(40, 10); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 10); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        std::cout << "\n\033[31mHeiltraenke\033[0m ------------> " << player[roundManager].healthPotion; position(50, 15); std::cout << "\033[90mAltmetall\033[0m --------------> " << player[roundManager].scrapMetal << std::endl;
        std::cout << "\n\033[34mManatraenke\033[0m ------------> " << player[roundManager].manaPotion; position(50, 17); std::cout << "\033[0mAluminium\033[0m --------------> " << player[roundManager].aluminum << std::endl;
        std::cout << "\n\033[95mRegenerationstraenke\033[0m ---> " << player[roundManager].regenPotion; position(50, 19); std::cout << "\033[31mKupfer\033[0m -----------------> " << player[roundManager].copper << std::endl;
        std::cout << "\n\033[92mKraeuter\033[0m ---------------> " << player[roundManager].herbs << std::endl;
        std::cout << "\n\033[90mRuestungen\033[0m -------------> " << armor; position(50, 23); std::cout << "\033[0mWaffen\033[0m -----------------> " << weapon << "\n" << std::endl;
        line();
        position(15, 28); std::cout << "\033[47;30m[ 1 ]\033[0m ------> Waffen                   \033[100;30m[ 4 ]\033[0m ------> \033[90mMaterial\033[0m" << std::endl;
        position(15, 30); std::cout << "\033[100;30m[ 2 ]\033[0m ------> \033[90mRuestungen\033[0m               \033[41;37m[ 5 ]\033[0m ------> \033[31mEntsorgen\033[0m" << std::endl;
        position(15, 32); std::cout << "\033[44;97m[ 3 ]\033[0m ------> \033[34mTraenke                  \033[47;30m[ 6 ]\033[0m ------> Zurueck" << std::endl; 
        
        short input = choice();

        switch(input)
        {
            case 1: // Waffen
                weapons(player , roundManager);
                break;

            case 2: // Ruestung
                armors(player, roundManager);
                break;

            case 3: // Tränke
                potions(player, roundManager);
                break;

            case 4: // Metalle
                materials(player, roundManager);
                break;

            case 5: // Entsorgen
                disposal(player, roundManager, 0);
                break; 

            case 6: // Zurück
                running = false;
                break;

        }
    }
    return;
}

void frameWork(Player player[], short roundManager, short zone, int room, short numberOfPlayers)
{
    clearScreen();
    line();
    std::cout << "\033[36mSpieler: " << player[roundManager].getName();
    position(60, 3); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
    capacityColor(player, roundManager); position(100, 3); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
    if (numberOfPlayers > 1) { position(140, 3); std::cout << "AP: " << player[roundManager].realActionPoints << "/" << player[roundManager].actionPoints << std::endl; }
    line();
    roomPictures(room);
    roomTexts(room);
    miniLine(58, 19);
    position(76, 21); dangerDisplay(zone);
    miniLine(58, 23);
    position(0, 26); line();
    if (isRoomValid(room))
    {
        position(76, 25); std::cout << "\033[46;30m[ 0 ]\033[0m ------> \033[36mSpezial\033[0m" << std::endl; 
    }           
    lifeDisplay(player, roundManager, 4, 29);
    line();
    return;
}

// Magie - Menü

void magicMenue(Player player[], short roundManager)
{
    bool running = true;

    while(running)
    {
        clearScreen();
        textMagic();
        line();
        std::cout << "\033[36mSpieler: " << player[roundManager].getName() << "\033[0m";
        position(40, 11); std::cout << "\033[33mGold: " << player[roundManager].gold << "\033[0m";
        capacityColor(player, roundManager); position(80, 11); std::cout << "Traglast: " << player[roundManager].realCapacity << "/" << player[roundManager].capacity << "\033[0m" << std::endl;
        line();
        lifeDisplay(player, roundManager, 0, 15);
        line();
        std::cout << "\033[34mIhre magischen Faehigkeiten liegen derzeit bei: " << player[roundManager].intelligence << " Intelligenz\033[0m" << std::endl;
        line();
        position(20,30); std::cout << "\033[42;37m[ 1 ]\033[0m ------> \033[32mHeilung   (I)\033[0m";
        if (player[roundManager].intelligence >= 10) 
        {
            position(20,32); std::cout << "\033[41;37m[ 2 ]\033[0m ------> \033[31mFeuerball (I)\033[0m";
        } 
        else
        {
            position(20,32); std::cout << "\033[31mMinimum Intelligenz: \033[34m 10 Int.\033[0m";
        }
        if (player[roundManager].intelligence >= 15) 
        {
            position(20,34); std::cout << "\033[44;37m[ 3 ]\033[0m ------> \033[34mEispfeil  (I)\033[0m";
        }
        else
        {
            position(20,34); std::cout << "\033[31mMinimum Intelligenz: \033[34m 15 Int\033[0m";
        }
        if (player[roundManager].intelligence >= 20) 
        {
            position(20,36); std::cout << "\033[45;37m[ 4 ]\033[0m ------> \033[35mGiftwolke (I)\033[0m";
        }
        else
        {
            position(20,36); std::cout << "\033[31mMinimum Intelligenz: \033[34m 20 Int.\033[0m";
        }
        if (player[roundManager].intelligence >= 25)
        {
            position(65,30); std::cout << "\033[102;30m[ 5 ]\033[0m ------> \033[92m Heilung   (II)\033[0m";
        }
        else
        {
            position(65,30); std::cout << "\033[31mMinimum Intelligenz: \033[34m 25 Int.\033[0m"; 
        }
        if (player[roundManager].intelligence >= 30)
        {
            position(65,32); std::cout << "\033[101;30m[ 6 ]\033[0m ------> \033[91m Feuerball (II)\033[0m";    
        }
        else
        {
            position(65,32); std::cout << "\033[31mMinimum Intelligenz: \033[34m 30 Int.\033[0m";
        }
        if (player[roundManager].intelligence >= 35)
        {
            position(65,34); std::cout << "\033[104;30m[ 7 ]\033[0m ------> \033[94m Eispfeil  (II)\033[0m";
        }
        else
        {
            position(65,34); std::cout << "\033[31mMinimum Intelligenz: \033[34m 35 Int.\033[0m";
        }
        if (player[roundManager].intelligence >= 40)
        {
            position(65,36); std::cout << "\033[105;30m[ 8 ]\033[0m ------> \033[95m Giftwolke (II)\033[0m";
        }
        else
        {
            position(65,36); std::cout << "\033[31mMinimum Intelligenz: \033[34m 40 Int.\033[0m";
        }
        position(20,38); std::cout << "\033[47;30m[ 0 ]\033[0m ------> Zurueck\033[0m" << std::endl;

        short input = choice();
        switch(input)
        {
            case 0:
                running = false;
                break;
            
            case 1:
                if (player[roundManager].realMana < 15)
                {
                    double heal = 0;
                    double vari = 0;
                    heal = round(((player[roundManager].health / 100) * 10));
                    vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                    heal += vari;
                    line();
                    std::cout << "\n\n\033[31mSie haben nicht genug Mana!\033[0m" << std::endl;
                    std::cout << "\033[32mIhre durchschnittliche \033[42;37m* Heilung *\033[0;32m betraegt: " << heal << " HP. Dabei werden 15 Mana verbraucht.\033[0m" << std::endl;
                    
                    line();
                    getKey();
                    continue;                    
                }
                else if (player[roundManager].realHealth == player[roundManager].health)
                {
                    double heal = 0;
                    double vari = 0;
                    heal = round(((player[roundManager].health / 100) * 10));
                    vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                    heal += vari;
                    line();
                    std::cout << "\n\n\033[31mSie benoetigen keine Heilung!" << std::endl;
                    std::cout << "\033[32mIhre durchschnittliche \033[42;37m* Heilung *\033[0;32m betraegt: " << heal << " HP. Dabei werden 15 Mana verbraucht.\033[0m" << std::endl;
                    line();
                    getKey();
                    continue;
                }
                else
                {
                    double heal = 0;
                    double vari = 0;
                    heal = round(((player[roundManager].health / 100) * 10));
                    vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                    heal += vari;
                    player[roundManager].realHealth += heal;
                    player[roundManager].realMana -= 15;
                    if (player[roundManager].realHealth > player[roundManager].health) {player[roundManager].realHealth = player[roundManager].health;}
                    line();
                    std::cout << "\n\n\033[32mSie haben sich um " << heal << " HP geheilt." << std::endl;
                    std::cout << "\n\033[31mDabei wurden 15 Mana verbraucht." << std::endl;
                    std::cout << "\n\033[32mIhre durchschnittliche \033[42;37m* Heilung *\033[0;32m betraegt: " << heal << " HP.\033[0m" << std::endl;
                    line();
                    getKey();
                    continue;
                }
                continue;
            
            case 2:
                if (player[roundManager].intelligence < 10)
                {
                    error(3);
                    continue;
                }
                else
                {
                double dmg = 0;
                double vari = 0;
                dmg = round((player[roundManager].health / 100) * 10);
                vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                dmg += vari;
                line();
                std::cout << "\n\033[31mIhr durchschnittlicher Schaden fuer \033[41;37m* Feuerball *\033[0;31m betraegt " << dmg << " DMG.\nDabei werden 15 Mana verbraucht.\033[0m" << std::endl;
                line();
                getKey();
                continue;
                }
                continue;

            case 3:
                if (player[roundManager].intelligence < 15)
                {
                    error(3);
                    continue;
                }
                else
                {
                double dmg = 0;
                double vari = 0;
                dmg = round((player[roundManager].health / 100) * 12);
                vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                dmg += vari;
                line();
                std::cout << "\n\033[34mIhr durchschnittlicher Schaden fuer \033[44;37m* Eispfeil *\033[0;34m betraegt " << dmg << " DMG.\nDabei werden 15 Mana verbraucht.\033[0m" << std::endl;
                line();
                getKey();
                continue;
                }
                continue;

            case 4:
                if (player[roundManager].intelligence < 20)
                {
                    error(3);
                    continue;
                }
                else
                {
                double dmg = 0;
                double vari = 0;
                dmg = round((player[roundManager].health / 100) * 15);
                vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                dmg += vari;
                line();
                std::cout << "\n\033[35mIhr durchschnittlicher Schaden fuer \033[45;37m* Giftwolke *\033[0;35m betraegt " << dmg << " DMG.\nDabei werden 15 Mana verbraucht.\033[0m" << std::endl;
                std::cout << "\033[35mEs besteht die durchschnittliche Chance von " << vari << " %, den Gegner zu vergiften.\033[0m.";
                line();
                getKey();
                continue;
                }

            case 5:
                if (player[roundManager].intelligence < 25)
                {
                    error(3);
                    continue;
                }
                else
                {
                    double heal = 0;
                    double vari = 0;
                    heal = round(((player[roundManager].health / 100) * 25));
                    vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                    heal += vari;
                    if (player[roundManager].realMana < 25)
                    {
                        line();
                        std::cout << "\n\033[31mSie haben nicht genug Mana!\033[0m" << std::endl;
                        std::cout << "\n\033[92mIhre durchschnittliche \033[102;30m* Heilung (II) *\033[0;92m betraegt: " << heal << " HP. Dabei werden 25 Mana verbraucht.\033[0m" << std::endl;
                        line();
                        getKey();
                        continue;                    
                    }
                    else if (player[roundManager].realHealth == player[roundManager].health)
                    {
                        line();
                        std::cout << "\n\033[31mSie benoetigen keine Heilung!" << std::endl;
                        std::cout << "\n\033[92mIhre durchschnittliche \033[102;30m* Heilung (II) *\033[0;92m betraegt: " << heal << " HP. Dabei werden 25 Mana verbraucht.\033[0m" << std::endl;
                        line();
                        getKey();
                        continue;
                    }
                    else
                    {
                        player[roundManager].realHealth += heal;
                        player[roundManager].realMana -= 25;
                        if (player[roundManager].realHealth > player[roundManager].health) {player[roundManager].realHealth = player[roundManager].health;}
                        line();
                        std::cout << "\n\033[32mSie haben sich um " << heal << " HP geheilt." << std::endl;
                        std::cout << "\n\033[31mDabei wurden 25 Mana verbraucht." << std::endl;
                        std::cout << "\n\033[92mIhre durchschnittliche \033[102;30m* Heilung (II) *\033[0;92m betraegt: " << heal << " HP.\033[0m" << std::endl;
                        line();
                        getKey();
                        continue;
                    }
                    continue;
                }
                continue;
            
            case 6:
                if (player[roundManager].intelligence < 30)
                {
                    error(3);
                    continue;
                }
                else
                {
                    double dmg = 0;
                    double vari = 0;
                    dmg = round((player[roundManager].health / 100) * 20);
                    vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                    dmg += vari;
                    line();
                    std::cout << "\n\033[91mIhr durchschnittlicher Schaden fuer \033[101;30m* Feuerball (II) *\033[0;91m betraegt " << dmg << " DMG.\nDabei werden 25 Mana verbraucht.\033[0m" << std::endl;
                    std::cout << "\033[91mEs besteht die durchschnittliche Chance von " << vari << " %, den Gegner zu verbrennen.\033[0m.";
                    line();
                    getKey();
                    continue;
                }
                continue;

            case 7:
                if (player[roundManager].intelligence < 35)
                {
                    error(3);
                    continue;
                }
                else
                {
                    double dmg = 0;
                    double vari = 0;
                    dmg = round((player[roundManager].health / 100) * 20);
                    vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                    dmg += vari;
                    line();
                    std::cout << "\n\033[94mIhr durchschnittlicher Schaden fuer \033[104;30m* Eispfeil (II) *\033[0;94m betraegt " << dmg << " DMG.\nDabei werden 25 Mana verbraucht.\033[0m" << std::endl;
                    std::cout << "\033[94mEs besteht die durchschnittliche Chance von " << vari << " %, den Gegner einzufrieren.\033[0m.";
                    line();
                    getKey();
                    continue;
                }
                continue;
            
            case 8:
                if (player[roundManager].intelligence < 40)
                {
                    error(3);
                    continue;
                }
                else
                {
                    double dmg = 0;
                    double vari = 0;
                    dmg = round((player[roundManager].health / 100) * 25);
                    vari = round(random(round((player[roundManager].intelligence / 100) * 25), player[roundManager].intelligence));
                    dmg += vari;
                    line();
                    std::cout << "\n\033[95mIhr durchschnittlicher Schaden fuer \033[105;37m* Giftwolke (II) *\033[0;95m betraegt " << dmg << " DMG.\nDabei werden 30 Mana verbraucht.\033[0m" << std::endl;
                    std::cout << "\033[95mEs besteht die durchschnittliche Chance von " << vari << " %, den Gegner zu vergiften.\033[0m.";
                    line();
                    getKey();
                    continue;
                }

            default:
                error(0);
                continue;
        }
        running = false;
        break;
    }
    return;
}

// Spielmenü zum Speichern und beenden

void menue (Player player[], short roundManager)
{
    bool running = true;
    bool answer;
    
    while(running)
    {
        clearScreen();
        textMenue();
        line();
        std::cout << "\n\033[47;30m[ 1 ]\033[0m ------> Spielstand speichern" << std::endl;
        std::cout << "\n\033[47;30m[ 2 ]\033[0m ------> Spielstand laden" << std::endl;
        std::cout << "\n\033[47;30m[ 3 ]\033[0m ------> Spiel beenden" << std::endl;
        std::cout << "\n\033[47;30m[ 4 ]\033[0m ------> Zurueck zum Spiel" << std::endl;
        
        short input = choice();
        
        switch(input)
        {
            case 1:
                saveGame();
                continue;

            case 2:
                loadGame();
                continue;
            
            case 3:
                std::cout << "\n\033[31mSind Sie sicher, dass Sie das Spiel beenden moechten? (J/N)\033[0m" << std::endl;
                answer = question();
                if (answer == true) {std::cout << "\nHaben Sie noch einen schoenen Tag! Auf Wiedersehen :)" << std::endl; getKey(); exit(0);}
                continue;
            
            case 4:
                running = false;
                break;

            default:
                error(0);
                continue;
        }
    }
    return;
}

// Ingame Hauptmenü

void roomOptions(Player player[], Enemy enemy[], Log log, short roundManager, short danger, short numberOfPlayers)
{
    bool running = true;
    bool answer = false;
    
    while(running)
    {
        frameWork(player, roundManager, danger, player[roundManager].currentRoom, numberOfPlayers);
        
         if (player[roundManager].permaDeath == true)
        {
            std::cout << "\n\033[101;30m*** Leider weilen Sie derzeit nicht unter den Lebenden.... ***\033[0m" << std::endl;
            player[roundManager].roomCleared == true;
            getKey();
            return;
        }

        if (numberOfPlayers > 1 && player[roundManager].realActionPoints == 0)
        {
            position(20, 39); std::cout << "\033[101;30m*** Ihre Aktionspunkte sind aufgebraucht! Leider endet Ihr Zug hier.... ***\033[0m" << std::endl;
            getKey();
            running = false;
            break;
        }

        position(20, 39); colorSwitch(danger); std::cout << "[ 1 ]\033[0m ------> "; textColor(danger); std::cout << "Weiter zum naechsten Raum\033[0m               \033[30;46m[ 5 ]\033[0m ------> \033[36mCharakter \033[0m \n\n";
        position(20, 41); colorSwitch(danger); std::cout << "[ 2 ]\033[0m ------> "; textColor(danger); std::cout << "Umgebung absuchen       \033[0m                \033[30;105m[ 6 ]\033[0m ------> \033[95mInventar \033[0m \n\n";
        position(20, 43); colorSwitch(danger); std::cout << "[ 3 ]\033[0m ------> "; textColor(danger); std::cout << "Nach Fallen suchen      \033[0m                \033[30;104m[ 7 ]\033[0m ------> \033[94mMagie \033[0m \n\n";
        position(20, 45); colorSwitch(danger); std::cout << "[ 4 ]\033[0m ------> "; textColor(danger); std::cout << "Rasten                  \033[0m                \033[30;47m[ 8 ]\033[0m ------> Menue \n\n";
    
        short input = choice();

        switch (input)
        {
            case 0:
                if (isRoomValid(player[roundManager].currentRoom))
                {
                    specialRoom(player, roundManager, player[roundManager].currentRoom, danger, numberOfPlayers);
                    break;
                }
                error(0);
                break;
        
            case 1:
                if (player[roundManager].currentRoom == 0 || player[roundManager].currentRoom == 1 || player[roundManager].currentRoom == 4)
                {
                    if (player[roundManager].key >= 1) 
                    {
                        std::cout << "\n\nSind Sie sicher, dass Sie den Raum verlassen moechten? (J/N)" << std::endl;
                        answer = question();
                        if (answer == true)
                        {
                            std::cout << "\n\n\033[30;102m *** Sie benutzen einen Schluessel und oeffnen die Tuer. Ihr Zug endet hier aber in der naechsten Runde geht es weiter im naechsten Raum! *** \033[0m" << std::endl;
                            player[roundManager].key--;
                            player[roundManager].roomCleared = true;
                            getKey();
                            running = false;
                            break;
                        }
                        break;                
                    }
                    if (player[roundManager].key < 1)
                    {
                        std::cout << "\n\n\033[37;41m *** Sie versuchen die Tuer zu oeffnen, aber sie ist verschlossen. Sie durchsuchen Ihre Taschen aber Sie haben leider keinen Schluessel dabei! *** \033[0m" << std::endl;
                        getKey();
                        break;
                    }
                    break;
                }
                std::cout << "\n\nSind Sie sicher, dass Sie den Raum verlassen moechten? (J/N)" << std::endl;
                        answer = question();
                        if (answer == true)
                        {
                            std::cout << "\n\n\033[30;102m *** Sie verlassen den Raum. Ihr Zug endet hier aber in der naechsten Runde geht es weiter im naechsten Raum! *** \033[0m" << std::endl;
                            player[roundManager].roomCleared = true;
                            getKey();
                            running = false;
                            break;                            
                        }
                        break;

            case 2:
                loot(player, enemy, log, roundManager, danger, numberOfPlayers);
                break;
            
            case 3:
                trapSearch(player, roundManager, danger, numberOfPlayers);
                break;
            
            case 4:
                takeBreak(player, enemy, log, roundManager, danger, numberOfPlayers);
                break;
            
            case 5:
                characterMenue(player, roundManager);
                break;
            
            case 6:
                inventory(player, roundManager);
                break;
                
            case 7:
                magicMenue(player, roundManager);
                break;
            
            case 8:
                menue(player, roundManager);
                break;

            default:
                error(0);
                break;        
        }
    }
    return;
    
}



#endif