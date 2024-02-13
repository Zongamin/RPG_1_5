#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>

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

void ShowLife()
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

// Veränderung der Schriftfarben

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

#endif

