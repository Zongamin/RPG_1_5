#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Headlines.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\player.h>

/*Inhaltsverzeichnis:
    - assignment     -- Zuweisung der Werte für neue Spieler
    - charCalc       -- Charkter Rechner zum errechnen neuer Werte bei Skillpunktverteilung
    - random         -- Zufallsgenerierte Zahlen mit Minmal und Maximal übergabe
    - getKey         -- press any key - Funktion
    - error          -- Fehlermeldung : Falsche Eingabe
    - clearScreen    -- Windows-CMD Screen leeren
    - position       -- Setzen der Cursor Position
    - miniLine       -- kleinen Trennstrich einfügen
    - line           -- Trennstrich einfügen
    - question       -- Ja/Nein - Abfrage des Spielers
    - choice         -- Zahleneingabe des Spielers (0 - 9) ohne "Enter" - Eingabe
    - condition      -- Skillpunkt ermittlung für Charactermenü 
    - lifeDisplay    -- Lebens- und Manaanzeige der Spieler
    - colorSwitch    -- Schalterfarben (Schrift mit Hintergrundfärbung) verändern
    - textColor      -- Schriftfarben verändern
    - backgroundColor-- Verändern der Hintergrund Farbe
    - levelUp        -- Anheben von Skillpunkten, Spielerlevel & geforderten Level Exp
    - expUp          -- Anheben der Spieler Exp und Level Umbruch
    - capacityCheck  -- Überprüfung der Traglast des Spielers mit evtl. Übergabe an Ablagefunktion für Gegenstände
    - arraySort      -- Sortierung von Waffen- und Rüstungsarrays der Spieler
    - loot           -- Funktion für die Suche-Option des Spielers
    - loadGame       -- Funktion zum Laden von Spielständen
    - getNumber      -- Funktion zur Ermittlung und Ausgabe des Spielernummer Schriftzuges
    - dangerZone     -- Funktion zur Ermittlung der Gefahrenstufe des derzeitigen Raums
    - dangerDisplay  -- gibt die Gefahrenstufe des Raums auf den Bildschirm aus
    - capacityColor  -- Ermittelt den Farbwert der Traglast nach Füllstand des Inventars des Spielers in Prozent
    - death          -- Ausgabe des Todes des Spielers
    - trapCall       -- Ermittelt die Anzahl von Fallen in einem Raum auf Basis der Gefahrstufe des Raumes
    - trapCheck      -- Ermittelt die verbleibende Anzahl der Fallen des Spielers und löst ggf. Fallen aus
    - trapSearch     -- Ermittelt, ob die Suche des Spielers nach einer Falle erfolgreich ist, oder sogar eine Falle auslöst
    - takeBreak      -- Ermittelt Werte beim Rasten des Spielers */

// Globale Variablen zum Eingrenzen von wiederholten Zufallszahlen

short repeater{};
short dangerRepeater{};
short danger{};

//Wertzuweisung neuer Spieler Objekte

void assignment(Player player[], short numberOfPlayers)
{
    for (int index = 0; index < numberOfPlayers; index++)
        {
            player[index].strength = 5;
            player[index].intelligence = 5;
            player[index].endurance = 5;
            player[index].dexterity = 5;
            player[index].luck = 5;
            player[index].level = 1;
            player[index].skillPoints = 5;
            player[index].exp = 1000;   
            player[index].realExp = 0;
            player[index].health = (player[index].strength * 15) + (player[index].endurance * 5);
            player[index].mana = (player[index].intelligence * 3) + (player[index].endurance * 2);
            player[index].realHealth = player[index].health;
            player[index].realMana = player[index].mana;
            player[index].luck = (player[index].endurance * 0.01) + (player[index].dexterity * 0.1);
            player[index].capacity = (player[index].strength * 15) + (player[index].endurance * 5);
            player[index].regenerationOn = 0;
            player[index].fireAura = 0;
            player[index].key = 0;
            player[index].scrapMetal = 0;
            player[index].aluminum = 0;
            player[index].copper = 0;
            player[index].healthPotion = 1;
            player[index].manaPotion = 1;
            player[index].regenPotion = 0;
            player[index].rooms = 0;
            player[index].crafted = 0;
            player[index].monsters = 0;
            player[index].bosses = 0;
            player[index].deaths = 0;
            player[index].permaDeath = false;
        }
    return;
}

// Errechnen neuer Werte bei Skillpunktverteilung

void charCalc(Player player[], short index)
{
    player[index].health = (player[index].strength * 15) + (player[index].endurance * 5);
    player[index].mana = (player[index].intelligence * 3) + (player[index].endurance * 2);
    player[index].luck = (player[index].endurance * 0.01) + (player[index].dexterity * 0.1);
    player[index].capacity = (player[index].strength * 15) + (player[index].endurance * 5);
    return;
}

// Generierung von Zufallszahlen mit min/max Wertübergabe

int random(int min, int max)
{
    bool running = true;
    int random;

    while(running)
    {
    srand(static_cast<unsigned int>(time(nullptr)));
    random = rand() % (max - min + 1) + min;
    if (random == repeater)
    {
        break;
    }
    running = false;
    break;
    }
    
    return random;
}

// Press any key 

void getKey() 
{
    char key;
    std::cout << "\n\n                                            \033[30;47m<<<< Press any key >>>>\033[0m" << std::endl;
    key = _getch();
    return;
}

// Falsche Eingaben Fehlermeldungen

void error(short error)
{
    switch(error)
    {
        case 0:
            std::cout << "\n\n\033[31mFalsche Eingabe!\033[0m" << std::endl;
            break;
        case 1:
            std::cout << "\n\n\033[31mZu wenig Skillpunkte!\033[0m" << std::endl;
            break;
        case 2:
            std::cout << "\n\n\033[31mEs wurden noch keine Skillpunkte auf dieses Attribut verteilt!\033[0m" << std::endl;
            break;
    }
    getKey();
    return;
}

// Screen säubern

void clearScreen()
{
    system("cls");
    return;
}

// Position des Cursors setzen

void position(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}

// Trennlinie zeichnen

void miniLine(int posX, int posY)
{
    position(posX, posY); std::cout << "-------------------------------------------------------------\n\n";
    return;
}

void line()
{
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
    return;
}

// Ja/Nein - Abfrage

bool question()
{
    char key;
    bool running = true;
    bool choice;

    while(running)
    {
        key = _getch();

        switch(key)
        {
            case 'j':
                choice = true;
                running = false;
                break;

            case 'n':
                choice = false;
                running = false;
                break;

            default:
                error(0);
                continue;
        }
    }
    return choice;
}

// Auswahl für Menüs

short choice()
{
    char key;
    key = _getch(); 
    if (key >= '0' && key <= '9') 
    {
        return key - '0';
    } 
    else 
    {
        return -1;
    }

}

// Skillpunkte check für Character Menü

bool condition(Player player[], short roundManager, double strength, double intelligence, double dexterity, double endurance)
{
    bool condition = false;

    if (player[roundManager].skillPoints > 0 || strength + intelligence + dexterity + endurance > 0)
    {
        condition = true;
        return condition;
    }

    return condition;
}

// Lebens-, Mana- und Exp - Anzeige des Spielers

void lifeDisplay(Player player[] , short roundManager,int posX, int posY)
{
    position(posX, posY);     std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    position(posX, posY + 1); std::cout << "| Leben |\033[41m                                                                                                    \033[0m|\n";
    position(posX, posY + 2); std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    position(posX, posY + 3); std::cout << "| Mana  |\033[41m                                                                                                    \033[0m|\n";
    position(posX, posY + 4); std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    position(posX, posY + 5); std::cout << "| Exp   |\033[41m                                                                                                    \033[0m|\n";
    position(posX, posY + 6); std::cout << "--------------------------------------------------------------------------------------------------------------\n";

    double range{};
    position((posX + 9), (posY + 1));
    round(range = 100 * (player[roundManager].realHealth / player[roundManager].health));
    for (int i = 0; i < range; i++)
    {
        std::cout << "\033[42m ";
    }
    
    range = 0;
    position((posX + 9), (posY + 3));
    round(range = 100 * (player[roundManager].realMana / player[roundManager].mana));
    for (int i = 0; i < range; i++)
    {
        std::cout << "\033[104m ";
    }
    
    range = 0;
    position((posX + 9), (posY + 5));
    round(range = 100 *(player[roundManager].realExp / player[roundManager].exp));
    for (int i = 0; i < range; i++)
    {
        std::cout << "\033[43m ";
    }
    std::cout << "\n\033[0m " << std::endl;
    return;
}

// Veränderung der Schalterfarben

void colorSwitch(int color)
{
    switch (color) 
    {   
        case 1:
            std::cout << "\033[30;102m";
            break;

        case 2:
            std::cout << "\033[30;103m";
            break;

        case 3: 
            std::cout << "\033[41m";
            break;
    }
    return;
}

// Veränderung der Textfarben

void textColor (int color)
{
    switch (color)
    {
        case 1:
            std::cout << "\033[92m";
            break;
        
        case 2:
            std::cout << "\033[93m";
            break;
            
        case 3:
            std::cout << "\033[31m";
            break;
    }
    return;
}

// Verändern der Hintergrundfarbe (case 0 = Standard)

void backgroundColor (short color)
{
    switch (color)
    {
        case 0:
            system("color");
            return;
    
        case 1:
            system("color A0");
            return;
    }

}

// Level up

void levelUp (Player player[], short roundManager)
{
    backgroundColor(1);    
    clearScreen();
    textLevelUp();
    line();

    player[roundManager].level++; 
    player[roundManager].skillPoints += 5;
    player[roundManager].exp = round(player[roundManager].exp * 1.25);

    std::cout << "\033[30;102m *** " << player[roundManager].getName() << " ist jetzt Level " << player[roundManager].level << " Ihre Skillpunkte sind um 5 gestiegen! *** \033[0m";
    std::cout << "\n\n";
    
    getKey();
    backgroundColor(0);
    return;
}


// Experience up

void expUp(Player player[], short roundManager)
{
    int range = 0;
    bool running = true;
        
    while(running)
    {
    clearScreen();
    textExpUp();
    line();

    if (player[roundManager].realExp > player[roundManager].exp)
    {
        std::cout << "Expierience : " << player[roundManager].realExp - player[roundManager].realExp << "/" << round(player[roundManager].exp * 1.2) << "\n\n";
    }
    else
    {
        std::cout << "Expierience : "<< player[roundManager].realExp << "/" << player[roundManager].exp << "\n\n";
    }
        std::cout << "------------------------------------------------------------------------------------------------------------\n";
        std::cout << "| Exp |\033[41m                                                                                                    \033[0m|\n";
        std::cout << "------------------------------------------------------------------------------------------------------------\n";

        position(7, 16);
    
        if (player[roundManager].realExp > player[roundManager].exp)
        {
        
        double px = player[roundManager].exp;
        range = 100 * (px / player[roundManager].exp);
        
        for (int i = 0; i < range; i++)
        {
            std::cout << "\033[103m ";
            Sleep(10);
            std::cout << "\033[0m";
        }
            std::cout << "\n\n" << std::endl;
            getKey();
            player[roundManager].realExp = player[roundManager].realExp - player[roundManager].exp;
            levelUp(player , roundManager);
            break;
        }
        else
        {
            range = 100 * (player[roundManager].realExp / player[roundManager].exp);
            
            for (int i = 0; i < range; i++)
            {
                std::cout << "\033[103m ";
                Sleep(10);
                std::cout << "\033[0m";
            }

            running = false;
            break;
        }
    }
    getKey();
    return;
}

// Überprüfung der Traglast

void capacityCheck(Player player[], short roundManager, double weight, short numberOfObjects)
{
    if ((numberOfObjects * weight) + player[roundManager].realCapacity > player[roundManager].capacity)
    {
        std::cout << "Sie tragen zu viel, möchten sie etwas wegwerfen? (J/N)";
        question();
    }
    return;
}

// Sortierung und Nachrutschen von Arrays

void arraySort(Player player[], short roundManager, std::string type)
{
    if (type == "weapon")
    {
        int arraySize = sizeof(player[roundManager].weapons) / sizeof(player[roundManager].weapons[0]);
        std::sort(player[roundManager].weapons, player[roundManager].weapons + arraySize, std::greater<int>());
        return;
    }
    else if (type == "armor")
    {
        int arraySize = sizeof(player[roundManager].armor) / sizeof(player[roundManager].armor[0]);
        std::sort(player[roundManager].armor, player[roundManager].armor + arraySize, std::greater<int>());
        return;
    }
    std::cout << "Error!" << std::endl;
    getKey();
    return;
}

// looten nach erfolgreicher Suche

void loot(Player player[], short roundManager)
{
    int chance = 0;
    double tempExp = 0;
    double findItem = 0;
    double experience = 0;
        
    clearScreen();
    textSearch();
    line();
    std::cout << "Sie begeben sich auf die Suche und finden:" << std::endl;
    line();
    
    for (int index = 0; index < 10; index++)
    {
        switch (index)
        {
            case 0: // Gold
                experience = 0;
                chance = 0; chance = round(random(1,100));
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 5), (player[roundManager].level * 25)) + player[roundManager].luck * 1);
                    experience = round((findItem * 0.125) * (player[roundManager].level * 1.25));
                    std::cout << "---------------------------------------------------" << std::endl;
                    std::cout << "\033[93mGold\033[0m --------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    player[roundManager].gold += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 1: // Schlüssel
                if (round(player[roundManager].key <= 1 + player[roundManager].luck))
                {
                    experience = 0;
                    chance = 0; chance = round(random(1,100));
                    if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                    {
                        findItem = 1;
                        experience = round((findItem * 20) * (player[roundManager].level * 1.25));
                        std::cout << "\033[36mSchluessel\033[0m --------------> " << findItem << " / " << experience << " Exp." << std::endl;
                        std::cout << "---------------------------------------------------" << std::endl;
                        player[roundManager].key += findItem;
                        tempExp += experience;
                        break;
                    }
                    break;
                }
                break;

            case 2: // Scrapmetal
                experience = 0;
                chance = round(random(1,100));
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)) + player[roundManager].luck * 1);
                    if (findItem < 1) {findItem = 1;} 
                    experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                    std::cout << "\033[90mAltmetall\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    capacityCheck(player, roundManager, 0.3, findItem);
                    player[roundManager].scrapMetal += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 3: // Aluminum
                experience = 0;
                chance = 0; chance = round(random(1,100));
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)) + player[roundManager].luck * 1);
                    if (findItem < 1) {findItem = 1;}
                    experience = round((findItem * 7.5) * (player[roundManager].level * 1.25));
                    std::cout << "\033[0mAluminium\033[0m ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    capacityCheck(player, roundManager, 0.2, findItem);
                    player[roundManager].aluminum += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 4: // Copper
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)) + player[roundManager].luck);
                    if (findItem < 1 ) {findItem = 1;} 
                    experience = round((findItem * 5) * (player[roundManager].level * 1.25));
                    std::cout << "\033[31mKupfer\033[0m ------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    capacityCheck(player, roundManager, 0.1, findItem);
                    player[roundManager].copper += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 5: // Healpotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)) + player[roundManager].luck * 1);
                    experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                    std::cout << "\033[91mHeiltraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    capacityCheck(player, roundManager, 0.25, findItem);
                    player[roundManager].healthPotion += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 6: // Manapotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)) + player[roundManager].luck * 1);
                    if (findItem < 1 ) {findItem = 1;}
                    experience = round((findItem * 15) * (player[roundManager].level * 1.25));
                    std::cout << "\033[94mManatraenke\033[0m -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    capacityCheck(player, roundManager, 0.25, findItem);
                    player[roundManager].manaPotion += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 7: // Regenerationpotion
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)) + player[roundManager].luck * 1);
                    if (findItem < 1) {findItem = 1;}
                    experience = round((findItem * 20) * (player[roundManager].level * 1.25));
                    std::cout << "\033[95mRegenerationstraenke\033[0m ----> " << findItem << " / " << experience << " Exp." << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    capacityCheck(player, roundManager, 0.25, findItem);
                    player[roundManager].regenPotion += findItem;
                    tempExp += experience;
                    break;
                }
                break;
            
            case 8: //
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    chance = 0; chance = random(1,100);
                    if (chance > 39 & chance < 61)
                    {
                        findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2));
                        findItem++;
                        experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                        std::cout << "\033[0mWaffe\033[0m -------------------> " << findItem << "DMG / " << experience << " Exp." << std::endl;
                        std::cout << "---------------------------------------------------" << std::endl;
                        capacityCheck(player, roundManager, findItem , 1);
                        for (int i = 0; player[roundManager].weapons[i] = !0; i++)
                        {
                            player[roundManager].weapons[index] += findItem;
                            arraySort(player, roundManager, "weapon");
                            tempExp += experience;
                            break;
                        }
                        
                    }
                    break;
                }
                break;

            case 9: // Rüstung
                experience = 0;
                chance = 0; chance = random(1,100);
                if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
                {
                    chance = 0; chance = random(1,100);
                    if (chance > (44 - player[roundManager].luck) & chance < round (56 + player[roundManager].luck))
                    {
                        findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2)); 
                        findItem++;
                        experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                        std::cout << "\033[90mRuestung\033[0m ----------------> " << findItem << "RST / " << experience << " Exp." << std::endl;
                        std::cout << "---------------------------------------------------" << std::endl;
                        capacityCheck(player, roundManager, findItem , 1);
                        for (int i = 0; player[roundManager].armor[i] = !0; i++)
                        {
                            player[roundManager].armor[i] += findItem;
                            arraySort(player, roundManager, "armor");
                            tempExp += experience;
                            break; 
                        }
                    }
                    break;
                }
                break;
                std::cout << "Index: " << index;
                
        }
  
    }
    if (tempExp < 1)
    {
        std::cout << "\n\nNichts!\n\n";
        getKey();
        return;
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Gesamt EXP --------------> " << tempExp << " EXP" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    player[roundManager].realExp += tempExp;
    getKey();
    expUp(player, roundManager);
    std::cout << "\n\n" << std::endl;
    return;
}

void loadGame()
{
    clearScreen();
    textLoad();
    line();
    getKey();
    return;
}

void textOne()
{
    position(70, 0); std::cout << "   _               \n";
    position(70, 1); std::cout << " /' \\    		  \n";
    position(70, 2); std::cout << "/\\_, \\           \n";
    position(70, 3); std::cout << "\\/_/\\ \\         \n";
    position(70, 4); std::cout << "   \\ \\ \\        \n";
    position(70, 5); std::cout << "    \\ \\_\\       \n";
    position(70, 6); std::cout << "     \\/_/         \n\n";
    return;
}

void textTwo()
{
    position(70, 0); std::cout << "   ___             \n";
    position(70, 1); std::cout << " /'___`\\          \n";
    position(70, 2); std::cout << "/\\_\\ /\\ \\      \n";
    position(70, 3); std::cout << "\\/_/// /__        \n";
    position(70, 4); std::cout << "   // /_\\ \\      \n";
    position(70, 5); std::cout << "  /\\______/       \n";
    position(70, 6); std::cout << "  \\/_____/        \n\n";
    return;
}

void textThree()
{
    position(70, 0); std::cout << "   __              \n";
    position(70, 1); std::cout << " /'__`\\           \n";
    position(70, 2); std::cout << "/\\_\\L\\ \\       \n";
    position(70, 3); std::cout << "\\/_/_\\_<_        \n";
    position(70, 4); std::cout << "  /\\ \\L\\ \\     \n";
    position(70, 5); std::cout << "  \\ \\____/       \n";
    position(70, 6); std::cout << "   \\/___/         \n\n";
    return;
}

void textFour()
{
    position(70, 0); std::cout << " __ __             \n";
    position(70, 1); std::cout << "/\\ \\\\ \\        \n";
    position(70, 2); std::cout << "\\ \\ \\\\ \\      \n";
    position(70, 3); std::cout << " \\ \\ \\\\ \\_    \n";
    position(70, 4); std::cout << "  \\ \\__ ,__\\    \n";
    position(70, 5); std::cout << "   \\/_/\\_\\_/    \n";
    position(70, 6); std::cout << "      \\/_/        \n\n";
    return;
}

// Ermittlung und Ausgabe der Spielernummer

void getNumber(short roundManager)
{
    switch (roundManager)
    {
        case 0:
            textOne();
            break;
        case 1:
            textTwo();
            break;
        case 2:
            textThree();
            break;
        case 3:
            textFour(); 
            break;       
    }
    return;
}

// Ermittlung der Gefahrenstufe der Räume

short dangerZone()
{
    short zone;
    bool running = true;

    while(running)
    {
        zone = round(random(1, 3));
        if (zone == dangerRepeater) {danger++;} else {danger = 0;}
        if (danger >= 2) {continue;}
        dangerRepeater = zone;
        running = false;
        danger = 0;
        break;
    }
    return zone;
}

// Anzeige der Gefahrenstufe des Raums

void dangerDisplay(short zone)
{
    switch(zone)
    {
        case 1:
            std::cout << "\033[30;102m Gefahrenstufe : Sicher \033[0m" << std::endl;
            break;
        case 2:
            std::cout << "\033[30;43m Gefahrenstufe : Unsicher \033[0m" << std::endl;
            break;
        case 3:
            std::cout << "\033[97;41m Gefahrenstufe : Gefahr \033[0m" << std::endl;
            break;
    }
    return;
}

void capacityColor(Player player[], short roundManager)
{
    double range{};
    round(range = 100 * (player[roundManager].realCapacity / player[roundManager].capacity));
    if (range <= 25)  {std::cout << "\033[92m"; return;}
    if (range <= 50)  {std::cout << "\033[32m"; return;}
    if (range <= 75)  {std::cout << "\033[43m"; return;}
    std::cout << "\033[31m"; 
    return;
}

// Ausgabe Tod des Spielers

void death(Player player[], short roundManager)
{
    player[roundManager].permaDeath = true;
    clearScreen();
    textDeath();
    line();
    position(16, 64); std::cout << player[roundManager].level;
    position(17, 64); std::cout << player[roundManager].rooms;
    position(18, 64); std::cout << player[roundManager].gold;
    position(19, 64); std::cout << player[roundManager].crafted;
    position(20, 64); std::cout << player[roundManager].monsters;
    position(21, 64); std::cout << player[roundManager].bosses;
    position(21, 64); std::cout << player[roundManager].deaths;    
    bool answer = question();
    if (answer == true)
    {
        loadGame();
    } 
    return;
}

void trapCall(Player player[], short roundManager, short zone)
{
    if (zone == 2) 
    {
        player[roundManager].traps = round(random(1, 5));
        round(player[roundManager].traps -= player[roundManager].luck);
        if (player[roundManager].traps < 1) {player[roundManager].traps = 0;}
    }
    if (zone >= 3)
    {
        player[roundManager].traps = round(random(1, 10));
        round(player[roundManager].traps -= player[roundManager].luck);
        if (player[roundManager].traps < 1) {player[roundManager].traps = 1;}
    }
    return;
}

void trapCheck(Player player[], short roundManager)
{
    double damage = 0;
    double vari = 0;
    short rand = round(random(1, 100));

    if (rand > 0 & rand < 26 + player[roundManager].luck || rand > 49 & rand < 76 + player[roundManager].luck)
    {
        if (player[roundManager].traps > 0)
        {
        
            clearScreen();
            textTrap();
            line();
            std::cout << "Um es mit den Worten Admiral Ackbars zu sagen: \033[37;41m *** Das ist eine Falle! *** \033[0m" << std::endl;
            line();
            player[roundManager].traps--;
            damage = (player[roundManager].health / 100 ) * 10;
            vari = round((damage / 100) * 10);
            damage = damage + (round(random(1, vari)) - player[roundManager].luck);
            std::cout << "Als Sie, natuerlich Ihren Geschaeften nachgehend, ziellos... aehm... zielstrebig durch die Gegend wandern, erwischt Sie eine Falle!\n" << std::endl;
            line();
            std::cout << "\033[37;41m *** Schaden: *** \033[0m \033[31m" << damage << " DMG.\033[0m\n\n" << std::endl;
            player[roundManager].realHealth -= damage;
            if (player[roundManager].realHealth < 0)
            {
                player[roundManager].realHealth = 0;
                lifeDisplay(player, roundManager, 0, 16);
                getKey();
                death(player, roundManager);
                return;
            }
            lifeDisplay(player, roundManager, 0, 16);
            getKey();
            return;
        }
    }
}

void trapSearch(Player player[], short roundManager, short danger)
{
    short zone = 0;
    short x = 0;
    double damage = 0;
    double vari = 0;

    clearScreen();
    textTrap();
    line();
    std::cout << "Sie begeben sich auf die Such nach Fallen....." << std::endl;
    line();
    if (danger == 1)
    {
        std::cout << "\nDoch da der Raum \033[30;102m * Sicher * \033[0m ist, gibt es keine Fallen...." << std::endl;
        getKey();
        return;
    }
    if (player[roundManager].traps < 1)
    {
        std::cout << "\nSelbst nach langer Suche koennen Sie keine Fallen entdecken! Koennte es sein, dass Sie bereits alle gefunden haben?" << std::endl;
        getKey();
        return;
    }
    std::cout << "\nSie begeben sich auf die Suche nach fallen";
    for (int i = 0; i < 5; i++)
    {
        std::cout << ".";
        Sleep(20);
    }
    zone = round(random(1, 100));
    if (danger == 2){ x = 14;}
    if (danger >= 2){ x = 25;}
    if (zone < (50 -x) - player[roundManager].luck & zone > (50 + x) + player[roundManager].luck)
    {
        std::cout << "\n\nSie entdecken eine Falle!\n\nDoch beim Entschärfen unterlaeuft Ihnen ein Missgeschick!\n" << std::endl;
        player[roundManager].traps--;
        damage = (player[roundManager].health / 100 ) * 10;
        vari = round((damage / 100) * 10);
        damage = damage + (round(random(1, vari)) - player[roundManager].luck);
        std::cout << "\033[37;41m *** Schaden: *** \033[0m \033[31m" << damage << " DMG.\033[0m\n\n" << std::endl;
        player[roundManager].realHealth -= damage;
        if (player[roundManager].realHealth < 0)
        {
                player[roundManager].realHealth = 0;
                lifeDisplay(player, roundManager, 0, 16);
                getKey();
                death(player, roundManager);
                return;
        }
        lifeDisplay(player, roundManager, 0, 16);
        getKey();
        return;
    }
    std::cout << "\n\nSie entdecken eine Falle!\n\nUnd Ihr Skill ist hoch genug sie zu entschaerfen!\n\n" << std::endl;
    player[roundManager].traps -= 1;
    getKey();
    return;
}

void takeBreak(Player player[], short roundManager, short danger)
{
    short zone = 0;
    int mana = 0;
    int health = 0;
    int x = 0;
     
    mana = round(random(((player[roundManager].mana / 100) * 25), ((player[roundManager].mana / 100) * 50)));
    health = round(random(((player[roundManager].health / 100) * 25), ((player[roundManager].health / 100) * 50)));
    zone = round(random(1, 100));
    
    if (danger == 1){ x = 50; }
    if (danger == 2){ x = 14; }
    if (danger >= 2){ x = 25; }
    if (zone < (50 -x) - player[roundManager].luck & zone > (50 + x) + player[roundManager].luck)
    {
        // Kampf und/oder Falle eintragen 
        return;
    }
    clearScreen();
    textBreak();
    line();
    std::cout << "Sie Suchen sich eine stille Ecke um Sich auszuruhen." << std::endl;
    line();
    std::cout << "\nBeim Rasten regenerieren Sie:" << std::endl;
    line();
    std::cout << "\033[31mLeben: " << health << std::endl;
    std::cout << "\n\033[34mMana : " << mana << std::endl;
    line();
    player[roundManager].health += health;
    player[roundManager].mana += mana;
    lifeDisplay(player, roundManager, 0, 23);
    getKey();
    return;
}

#endif

