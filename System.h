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

/*Inhaltsverzeichnis:
    - assignment     -- Zuweisung der Werte für neue Spieler
    - charCalc       -- Charkter Rechner zum errechnen neuer Werte bei Skillpunktverteilung
    - random         -- Zufallsgenerierte Zahlen mit Minmal und Maximal übergabe
    - getKey         -- press any key - Funktion
    - error          -- Fehlermeldung : Falsche Eingabe
    - clearScreen    -- Windows-CMD Screen leeren
    - line           -- Trennstrich einfügen
    - question       -- Ja/Nein - Abfrage des Spielers
    - choice         -- Zahleneingabe des Spielers (0 - 9) ohne "Enter" - Eingabe
    - position       -- Setzen der Cursor Position
    - condition      -- Skillpunkt ermittlung für Charactermenü 
    - showLife       -- Lebens- und Manaanzeige der Spieler
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
    */

// Globale Variable zum Eingrenzen von wiederholten Zufallszahlen

int repeater;

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
        continue;
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

// Trennlinie zeichnen

void line()
{
    std::cout << "\n---------------------------------------------------------------------------------------------------------------\n\n";
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
    if (key >= '0' && key <= '9') {
        return key - '0';
    } else {
        return-1;
    }

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

// Skillpunkte check für Character Menü

bool condition(Player player[], short roundManager, double strength, double intelligence, double dexterity, double endurance)
{
    if (player[roundManager].skillPoints > 0 || strength + intelligence + dexterity + endurance > 0)
    {
        bool condition = true;
        return condition;
    }
}

// Lebens- und Manaanzeige

void showLife(Player player[] , short roundManager)
{
    position(0, 22);
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "| Leben |\033[41m                                                                                                    \033[0m|\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "| Mana  |\033[41m                                                                                                    \033[0m|\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    position(9, 23);
    int range = 100 * (player[roundManager].realHealth / player[roundManager].health);

    for (int i = 0; i < range; i++)
    {
    std::cout << "\033[42m ";
    }
    position(9, 25);

    range = 100 * (player[roundManager].realMana / player[roundManager].mana);
    for (int x = 0; x < range; x++)
    {
    std::cout << "\033[104m ";
    }
    std::cout << "\n\n\n\033[0m";
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
    player[roundManager].level++; 
    player[roundManager].skillPoints += 5;
    player[roundManager].exp = round(player[roundManager].exp * 1.25);

    std::cout << player[roundManager].getName() << " ist jetzt Level : " << player[roundManager].level;
    std::cout << "\n\nSkillpunkte sind um 5 gestiegen!";
    
    getKey();
    return;
}


// Experience up

void expUp(Player player[], short roundManager)
{
    int range = 0;
    bool running = true;
        
    while(running)
    {
    if (player[roundManager].realExp > player[roundManager].exp)
    {
        std::cout << "\n Expierience : " << player[roundManager].realExp - player[roundManager].realExp << "/" << round(player[roundManager].exp * 1.2) << "\n\n";
    }
    else
    {
        std::cout << "\n Expierience : "<< player[roundManager].realExp << "/" << player[roundManager].exp << "\n\n";
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
    int chance;
    double tempExp = 0;
    double findItem = 0;
    double experience = 0;
    
    for (int x = 0 ; x < 8; x++)
    {
    chance = 0; chance = random(1,100);
    if (chance > 0 && chance < 26 || chance > 49 && chance < 76)
    {
        experience = 0;

        switch (x)
        {
            case 0: // Gold
                findItem = random((player[roundManager].level * 5), (player[roundManager].level * 25));
                experience = round((findItem * 0.125) * (player[roundManager].level * 1.25));
                std::cout << "\nGold ---------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                player[roundManager].gold += findItem;
                break;

            case 1: // Scrapmetal
                findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)));
                experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                std::cout << "\nAltmetall ----------------> " << findItem << " / " << experience << " Exp." << std::endl;
                capacityCheck(player, roundManager, 0.3, findItem);
                player[roundManager].scrapMetal += findItem;
                break;
            
            case 2: // Aluminum
                findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25)));
                experience = round((findItem * 7.5) * (player[roundManager].level * 1.25));
                std::cout << "\nAluminium ---------------> " << findItem << " / " << experience << " Exp." << std::endl;
                capacityCheck(player, roundManager, 0.2, findItem);
                player[roundManager].aluminum += findItem;
                break;
            
            case 3: // Copper
                findItem = round(random((player[roundManager].level * 0.125), (player[roundManager].level * 0.25))); 
                experience = round((findItem * 5) * (player[roundManager].level * 1.25));
                std::cout << "\nKupfer ------------------> " << findItem << " / " << experience << " Exp." << std::endl;
                capacityCheck(player, roundManager, 0.1, findItem);
                player[roundManager].copper += findItem;
                break;
            
            case 4: // Healpotion
                findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)));
                experience = round((findItem * 10) * (player[roundManager].level * 1.25));
                std::cout << "\nHeiltraenke -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                capacityCheck(player, roundManager, 0.25, findItem);
                player[roundManager].healthPotion += findItem;
                break;
            
            case 5: // Manapotion
                findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)));
                experience = round((findItem * 15) * (player[roundManager].level * 1.25));
                std::cout << "\nManatraenke -------------> " << findItem << " / " << experience << " Exp." << std::endl;
                capacityCheck(player, roundManager, 0.25, findItem);
                player[roundManager].manaPotion += findItem;
                break;
            
            case 6: // Regenerationpotion
                findItem = round(random((player[roundManager].level * 1), (player[roundManager].level * 1.25)));
                experience = round((findItem * 20) * (player[roundManager].level * 1.25));
                std::cout << "\nRegenerationstraenke ----> " << findItem << " / " << experience << " Exp." << std::endl;
                capacityCheck(player, roundManager, 0.25, findItem);
                player[roundManager].regenPotion += findItem;
                break;
            
            case 7: // Waffen
                chance = 0; chance = random(1,100);
                if (chance > 39 && chance < 61)
                {
                    findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2)); findItem++;
                    experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                    std::cout << "\nWaffe -------------------> " << findItem << "DMG / " << experience << " Exp." << std::endl;
                    capacityCheck(player, roundManager, findItem , 1);
                    for (int index = 0; player[roundManager].weapons[index] = !0; index++)
                    {
                    player[roundManager].weapons[index] += findItem;
                    arraySort(player, roundManager, "weapon");
                    break;
                    }
                }
                break;

            case 8: // Rüstung
                chance = 0; chance = random(1,100);
                if (chance > 39 && chance < 61)
                {
                    findItem = random((player[roundManager].level * 0.1), (player[roundManager].level * 0.2)); findItem++;
                    experience = round((findItem * 100) * (player[roundManager].level * 1.25));
                    std::cout << "\nRuestung ----------------> " << findItem << "RST / " << experience << " Exp." << std::endl;
                    capacityCheck(player, roundManager, findItem , 1);
                    for (int index = 0; player[roundManager].armor[index] = !0; index++)
                    {
                    player[roundManager].armor[index] += findItem;
                    arraySort(player, roundManager, "armor");
                    break;
                    }
                }
                break;
        }

        tempExp += experience;
    }
    
    if (tempExp < 1)
    {
        std::cout << "\n\nNichts!";
        getKey();
        return;
    }
    std::cout << "\nGesamt EXP --------------> " << tempExp << " (EXP)";
    player[roundManager].realExp += tempExp;
    getKey();
    expUp(player, roundManager);
    return;
    std::cout << "\n";
    }
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
    position(70, 6); std::cout << "     \\/_/         \n";
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
    position(70, 6); std::cout << "  \\/_____/        \n";
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
    position(70, 6); std::cout << "   \\/___/         \n";
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
    position(70, 6); std::cout << "      \\/_/        \n";
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

void dangerZone()
{
    return;
}

#endif

