#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <C:\Users\DokBa\Desktop\Work\Game\RPG_1_5\Player.h>

int repeater;

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
        }
}

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

void error()
{
    std::cout << "Falsche Eingabe!" << std::endl;
    return;
}

void getKey() 
{
    char key;
    std::cout << "\n\n<<<< Press any key >>>>" << std::endl;
    key = _getch();
    return;
}

void clearScreen()
{
    system("cls");
    return;
}

void line()
{
    std::cout << "\n---------------------------------------------------------------------------------------------------------------\n\n";
    return;
}

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


