#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>

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
    std::cout << "\n\n<<<< Press any key >>>>" << std::endl;
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

void ShowLife(Player player[] , short roundManager)
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
    player[roundManager].skillPoints = player[roundManager].skillPoints + 5;
    player[roundManager].exp = round(player[roundManager].exp * 1.2);

    std::cout << player[roundManager].getName() << " ist jetzt Level : " << player[roundManager].level;
    std::cout << "\n\nSkillpunkte sind um 5 gestiegen!";
    
    getKey();
    return;
}


// Experience up

void ExpUp(Player player[], short roundManager)
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

// looten nach erfolgreicher Suche

void loot(Player player[], short roundManager)
{
    double findGold = 0;
    double experience = 0;
    int findHeal = 0;
    int findMana = 0;
    int findRegen = 0;
    int findMetal = 0;
    int chance = random(1,100);
    int xp = 0;
    int px = 0;

    std::cout << "\n";

    if (chance > 0 & chance < 26 || chance > 49 & chance < 76) 
    {
        findGold = random((player[roundManager].level * 5), (player[roundManager].level * 25));
        experience = findGold * 0.25;
        xp = round(experience);
        px = px + xp;
        std::cout << "\n\033[93mGold -------------------> " << findGold << "\033[0m (" << xp << " EXP)";
        player[roundManager].gold += findGold;

    }
    if (player[roundManager].key < 1)
    {
        chance = 0; chance = random(1,100);
        if (chance > 0 & chance < 26 || chance > 49 & chance < 76)
        {
            xp = 0;
            experience = 0;
            experience = (50 * (player[roundManager].level * 0.5));
            xp = round(experience);
            px = px + xp;
            std::cout << "\nSchluessel -------------> 1 (" << xp << " EXP)";
            player[roundManager].key++;
        } 
    }
    chance = 0; chance = random(1,100);
    if (chance > 0 & chance < 26 || chance < 49 & chance < 76)
    {
        xp = 0;
        experience = 0;
        findHeal = random(1, 2);
        experience = (findHeal * 10) * (player[roundManager].level * 0.25);
        xp = round(experience);
        px = px + xp;
        std::cout << "\n\033[31mHeiltraenke ------------> " << findHeal << "\033[0m (" << xp << " EXP)";
        player[roundManager].healthPotion += findHeal;
    }
    chance = 0; chance = random(1,100);
    if (chance > 0 & chance < 26 || chance < 49 & chance < 76)
    {
        xp = 0;
        experience = 0;
        findMana = random(1, 2);
        experience = (findMana * 15) * (player[roundManager].level * 0.25);
        xp = round(experience);
        px = px + xp;
        std::cout << "\n\033[34mfindManaraenke ------------> " << findMana << "\033[0m (" << xp << " EXP)";
        player[roundManager].manaPotion += findMana;
    }
    chance = 0; chance = random(1,100);
    if (Chance > 0 & Chance < 26 || Chance < 49 & Chance < 76)
    {
        xp = 0;
        experience = 0;
        Regent = zufall(1, 3);
        experience = (Regent * 20) * (SpielerLevel[roundManager] * 0.25);
        xp = round(experience);
        px = px + xp;
        cout << "\n\033[35mRegenerationstraenke ----> " << findMana << "\033[0m (" << xp << " EXP)";
        findManarank[roundManager] = findManarank[roundManager] + findMana;
    }
    Chance = 0; Chance = zufall(1,100);
    if (Chance > 0 & Chance < 26 || Chance < 49 & Chance < 76)
    {
        xp = 0;
        experience = 0;
        Metall = zufall(1, 5);
        experience = (Metall * 5) * (SpielerLevel[roundManager] * 0.25);
        xp = round(experience);
        px = px + xp;
        cout << "\nAltmetall ----------> " << Metall << " (" << xp << " EXP)";
        Altmetall[roundManager] = Altmetall[roundManager] + Metall;
        Tragekapazitaet[roundManager] = Tragekapazitaet[roundManager] + (Metall * 0.1);
    }
    if (px < 1)
    {
        cout << "\n\nNichts!";
        getKey();
        return;
    }
    cout << "\nGesamt EXP ---------> " << px << " (EXP)";
    Exp[roundManager] = Exp[roundManager] + px;
    getKey();
    ExpUp();
    return;

}


#endif

