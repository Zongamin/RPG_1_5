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
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>

/*Inhaltsverzeichnis:
    - assignment     -- Zuweisung der Werte füür neue Spieler
    - random         -- Zufallsgenerierte Zahlen mit Minmal und Maximal übergabe
    - getKey         -- press any key - Funktion
    - error          -- Fehlermeldung : Falsche Eingabe
    - clearScreen    -- Windows-CMD Screen leeren
    - line           -- Trennstrich einfügen
    - question       -- Ja/Nein - Abfrage des Spielers
    - choice         -- Zahleneingabe des Spielers (0 - 9) ohne "Enter" - Eingabe 
    - showLife       -- Lebens- und Manaanzeige der Spieler
    - colorSwitch    -- Schalterfarben (Schrift mit Hintergrundfärbung) verändern
    - textColor      -- Schriftfarben verändern
    - levelUp        -- Anheben von Skillpunkten, Spielerlevel & geforderten Level Exp
    - expUp          -- Anheben der Spieler Exp und Level Umbruch
    - capacityCheck  -- Überprüfung der Traglast des Spielers mit evtl. Übergabe an Ablagefunktion für Gegenstände
    - arraySort      -- Sortierung von Waffen- und Rüstungsarrays der Spieler
    - loot           -- Funktion für die Suche-Option des Spielers
    - */

// Globale Variable zum eingrenzen von wiederholten Zufallszahlen

int repeater;

//Wertzuweisung neuer Spieler Objekte

void assignment(Player player[], short numberOfPlayers)
{
    for (int i = 0; i < numberOfPlayers; i++)
        {
        player[i].strength = 5;
        player[i].intelligence = 5;
        player[i].endurance = 5;
        player[i].dexterity = 5;
        player[i].luck = 5;
        player[i].level = 1;
        player[i].skillPoints = 5;
        player[i].exp = 1000;
        player[i].realExp = 0;
        player[i].health = (player[i].strength * 15) + (player[i].endurance * 5);
        player[i].mana = (player[i].intelligence * 3) + (player[i].endurance * 2);
        player[i].realHealth = player[i].health;
        player[i].realMana = player[i].mana;
        player[i].luck = (player[i].endurance * 0.01) + (player[i].dexterity * 0.1);
        player[i].capacity = (player[i].strength * 15) + (player[i].endurance * 5);
        player[i].regenerationOn = 0;
        player[i].fireAura = 0;
        player[i].key = 0;
        player[i].scrapMetal = 0;
        player[i].aluminum = 0;
        player[i].copper = 0;
        player[i].healthPotion = 0;
        player[i].manaPotion = 0;
        player[i].regenPotion = 0;
        player[i].rooms = 0;
        player[i].crafted = 0;
        player[i].monsters = 0;
        player[i].bosses = 0;
        }
}

//Generierung von Zufallszahlen mit min/max Wertübergabe

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

// Falsche Eingabe Fehlermeldung

void error()
{
    std::cout << "Falsche Eingabe!" << std::endl;
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
                error();
                continue;
        }
    }
    return choice;
}

// Auswahl für Menüs

int choice()
{
    char key;
    key = _getch(); 
    if (key >= '0' && key <= '9') {
        return key - '0';
    } else {
        return-1;
    }

}

// Lebens- und Manaanzeige

void showLife(Player player[] , short roundManager)
{
    COORD coord;
    coord.X = 0;
    coord.Y = 22;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "| Leben |\033[41m                                                                                                    \033[0m|\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
    std::cout << "| Mana  |\033[41m                                                                                                    \033[0m|\n";
    std::cout << "--------------------------------------------------------------------------------------------------------------\n";
        
    coord.X = 9;
    coord.Y = 23;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
    int range = 100 * (player[roundManager].realHealth / player[roundManager].health);
    for (int i = 0; i < range; i++)
    {
    std::cout << "\033[42m ";
    }
    coord.X = 9;
    coord.Y = 25;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

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

    COORD coord;
    coord.X = 7;
    coord.Y = 16;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
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


#endif

